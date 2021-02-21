#include "CWndApp.h"
#include "CObj.h"
#include "../Manager/CInputManager.h"

// 전역 변수
static CWndApp *g_pInst = nullptr;

// 윈도우 프로시저
static LRESULT CALLBACK WndProc(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) {
	static CWndApp *pWndApp = nullptr;

	switch(a_nMsg) {
		case WM_CREATE: {
			auto pstCreateStruct = (CREATESTRUCT *)a_lParams;
			pWndApp = static_cast<CWndApp *>(pstCreateStruct->lpCreateParams);
		} break;
	}

	// 윈도우가 생성 되었을 경우
	if(pWndApp != nullptr){
		return pWndApp->handleWndMsg(a_hWnd, a_nMsg, a_wParams, a_lParams);
	}

	return DefWindowProc(a_hWnd, a_nMsg, a_wParams, a_lParams);
}

CWndApp::CWndApp(HINSTANCE a_hInst, const SIZE & a_rstWndSize, int a_nShowOpts) 
:
m_hInst(a_hInst),
m_nShowOpts(a_nShowOpts),
m_stWndSize(a_rstWndSize)
{
	// 콘솔을 생성한다
	if(AllocConsole()) {
		m_pstRStream = freopen("CONIN$", "rb", stdin);
		m_pstWStream = freopen("CONOUT$", "wb", stdout);
	}

	m_stWndRect = RECT {
		0, 0, a_rstWndSize.cx, a_rstWndSize.cy
	};

	g_pInst = this;

	ZeroMemory(&m_unPrevTime, sizeof(m_unPrevTime));
	ZeroMemory(&m_unFrequency, sizeof(m_unFrequency));
	ZeroMemory(&m_stWndClass, sizeof(m_stWndClass));
}

CWndApp::~CWndApp(void) {
	SAFE_DELETE(m_pRoot);
	SAFE_DELETE(m_pNextRoot);

	SAFE_FCLOSE(m_pstRStream);
	SAFE_FCLOSE(m_pstWStream);

	SAFE_DELETE_OBJ(m_hMemoryBitmap);
	UnregisterClass(m_stWndClass.lpszClassName, m_stWndClass.hInstance);
}

void CWndApp::onUpdate(float a_fDeltaTime) {
	GET_INPUT_MANAGER()->onUpdate(a_fDeltaTime);

	// 루트 객체가 존재 할 경우
	if(m_pRoot != nullptr) {
		m_pRoot->onUpdate(a_fDeltaTime);
	}
}

void CWndApp::onRender(HDC a_hDC) {
	// 루트 객체가 존재 할 경우
	if(m_pRoot != nullptr){
		m_pRoot->onRender(a_hDC);
	}
}

LRESULT CWndApp::handleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) {
	switch(a_nMsg) {
		case WM_SIZE: this->handleSizeMsg(a_hWnd, a_wParams, a_lParams); break;
		case WM_DESTROY: this->handleDestroyMsg(a_hWnd, a_wParams, a_lParams); break;
	}

	return DefWindowProc(a_hWnd, a_nMsg, a_wParams, a_lParams);
}

SIZE CWndApp::getWndSize(void) const {
	return m_stWndSize;
}

HWND CWndApp::getWndHandle(void) const {
	return m_hWnd;
}

HINSTANCE CWndApp::getInstHandle(void) const {
	return m_hInst;
}

void CWndApp::setRoot(CObj * a_pRoot) {
	m_pNextRoot = a_pRoot;
}

int CWndApp::run(void) {
	this->init();

	ShowWindow(m_hWnd, m_nShowOpts);
	UpdateWindow(m_hWnd);

	return this->runMsgLoop();
}

CWndApp * CWndApp::getInst(void) {
	return g_pInst;
}

void CWndApp::init(void) {
	m_hWnd = this->createWnd(m_stWndClass);
	m_pRoot = this->createRoot();

	GET_INPUT_MANAGER()->init();
}

int CWndApp::runMsgLoop(void) {
	MSG stMsg;
	ZeroMemory(&stMsg, sizeof(stMsg));

	QueryPerformanceCounter(&m_unPrevTime);
	QueryPerformanceFrequency(&m_unFrequency);

	while(stMsg.message != WM_QUIT) {
		// 메세지가 존재 할 경우
		if(PeekMessage(&stMsg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&stMsg);
			DispatchMessage(&stMsg);
		}

		auto hDC = GetDC(m_hWnd);
		auto hMemoryDC = CreateCompatibleDC(hDC);

		auto hPrevBitmap = SelectObject(hMemoryDC, m_hMemoryBitmap);
		FillRect(hMemoryDC, &m_stWndRect, m_stWndClass.hbrBackground);

		LARGE_INTEGER unCurTime;
		QueryPerformanceCounter(&unCurTime);

		float fDeltaTime = (unCurTime.QuadPart - m_unPrevTime.QuadPart) / (float)m_unFrequency.QuadPart;
		m_fRunningTime += fDeltaTime;

		this->onUpdate(fDeltaTime);
		this->onRender(hMemoryDC);

		RECT stTextRect = { 10, 10 };
		TCHAR szTimeInfoString[MAX_PATH] = _T("");

		_stprintf(szTimeInfoString, _T("Delta Time: %f sec\nRunning Time: %f sec"), fDeltaTime, m_fRunningTime);

		DrawText(hMemoryDC, szTimeInfoString, _tcslen(szTimeInfoString), &stTextRect, DT_TOP | DT_LEFT | DT_CALCRECT);
		DrawText(hMemoryDC, szTimeInfoString, _tcslen(szTimeInfoString), &stTextRect, DT_TOP | DT_LEFT);

		BitBlt(hDC, 0, 0, m_stWndSize.cx, m_stWndSize.cy, hMemoryDC, 0, 0, SRCCOPY);
		SelectObject(hMemoryDC, hPrevBitmap);

		m_unPrevTime = unCurTime;

		SAFE_DELETE_DC(hMemoryDC);
		SAFE_RELEASE_DC(m_hWnd, hDC);

		// 다음 루트가 존재 할 경우
		if(m_pNextRoot != nullptr) {
			SAFE_DELETE(m_pRoot);

			m_pRoot = m_pNextRoot;
			m_pNextRoot = nullptr;
		}
	}

	return stMsg.wParam;
}

void CWndApp::handleSizeMsg(HWND a_hWnd, WPARAM a_wParams, LPARAM a_lParams) {
	m_stWndSize.cx = m_stWndRect.right = LOWORD(a_lParams);
	m_stWndSize.cy = m_stWndRect.bottom = HIWORD(a_lParams);

	SAFE_DELETE_OBJ(m_hMemoryBitmap);

	auto hDC = GetDC(m_hWnd);
	m_hMemoryBitmap = CreateCompatibleBitmap(hDC, m_stWndSize.cx, m_stWndSize.cy);

	SAFE_RELEASE_DC(m_hWnd, hDC);
}

void CWndApp::handleDestroyMsg(HWND a_hWnd, WPARAM a_wParams, LPARAM a_lParams) {
	PostQuitMessage(0);
}

HWND CWndApp::createWnd(WNDCLASS & a_rstOutWndClass) {
	WNDCLASS stWndClass = {
		CS_VREDRAW | CS_HREDRAW,
		WndProc,
		0,
		0,
		m_hInst,
		LoadIcon(NULL, IDI_APPLICATION),
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)GetStockObject(COLOR_WINDOW + 1),
		NULL,
		_T("Example")
	};

	RegisterClass(&stWndClass);
	CopyMemory(&a_rstOutWndClass, &stWndClass, sizeof(stWndClass));

	RECT stWndRect = {
		0, 0, m_stWndSize.cx, m_stWndSize.cy
	};

	AdjustWindowRect(&stWndRect, WS_OVERLAPPEDWINDOW, FALSE);
	return CreateWindow(stWndClass.lpszClassName, stWndClass.lpszClassName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, stWndRect.right - stWndRect.left, stWndRect.bottom - stWndRect.top, GetDesktopWindow(), NULL, stWndClass.hInstance, this);
}

CObj * CWndApp::createRoot(void) {
	return new CObj(D3DXVECTOR2(0.0f, 0.0f));
}
