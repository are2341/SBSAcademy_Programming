#include "CWndApp.h"

// ���� ����
static CWndApp *g_pInst = nullptr;

// ������ ���ν���
static LRESULT CALLBACK WndProc(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) {
	static IWndMsgHandler *pMsgHandler = nullptr;

	switch(a_nMsg) {
		case WM_CREATE: {
			auto pstCreateStruct = (CREATESTRUCT *)a_lParams;
			pMsgHandler = static_cast<IWndMsgHandler *>(pstCreateStruct->lpCreateParams);
		} break;
	}

	// ������ �޼��� ó���ڰ� ���� �� ���
	if(pMsgHandler != nullptr){
		return pMsgHandler->handleWndMsg(a_hWnd, a_nMsg, a_wParams, a_lParams);
	}

	return DefWindowProc(a_hWnd, a_nMsg, a_wParams, a_lParams);
}

CWndApp::CWndApp(HINSTANCE a_hInst, const SIZE & a_rstWndSize, int a_nShowOpts) 
:
m_hInst(a_hInst),
m_nShowOpts(a_nShowOpts),
m_stWndSize(a_rstWndSize)
{
	// �ܼ��� �����Ѵ�
	if(AllocConsole()) {
		m_pstRStream = freopen("CONIN$", "rb", stdin);
		m_pstWStream = freopen("CONOUT$", "wb", stdout);
	}

	g_pInst = this;
	ZeroMemory(&m_stWndClass, sizeof(m_stWndClass));
}

CWndApp::~CWndApp(void) {
	SAFE_FCLOSE(m_pstRStream);
	SAFE_FCLOSE(m_pstWStream);

	UnregisterClass(m_stWndClass.lpszClassName, m_stWndClass.hInstance);
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
}

int CWndApp::runMsgLoop(void) {
	MSG stMsg;
	ZeroMemory(&stMsg, sizeof(stMsg));

	while(GetMessage(&stMsg, NULL, 0, 0)) {
		TranslateMessage(&stMsg);
		DispatchMessage(&stMsg);
	}

	return stMsg.wParam;
}

void CWndApp::handleSizeMsg(HWND a_hWnd, WPARAM a_wParams, LPARAM a_lParams) {
	m_stWndSize.cx = LOWORD(a_lParams);
	m_stWndSize.cy = HIWORD(a_lParams);

	auto hDC = GetDC(a_hWnd);

	SAFE_DELETE_OBJ(m_hMemoryBitmap);
	m_hMemoryBitmap = CreateCompatibleBitmap(hDC, m_stWndSize.cx, m_stWndSize.cy);

	ReleaseDC(a_hWnd, hDC);
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
