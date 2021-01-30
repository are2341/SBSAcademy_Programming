#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IWndMsgHandler.h"

//! 윈도우 어플리케이션
class CWndApp : public IWndMsgHandler {
public:			// IWndMsgHandler

	//! 윈도우 메세지를 처리한다
	virtual LRESULT handleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) override;

public:			// public 함수

	//! 윈도우 크기를 반환한다
	SIZE getWndSize(void) const;

	//! 윈도우 핸들을 반환한다
	HWND getWndHandle(void) const;

	//! 인스턴스 핸들을 반환한다
	HINSTANCE getInstHandle(void) const;

	//! 어플리케이션을 실행한다
	int run(void);

	//! 인스턴스를 반환한다
	static CWndApp * getInst(void);

protected:			// protected 함수

	//! 초기화
	virtual void init(void);

	//! 메세지 루프를 실행한다
	virtual int runMsgLoop(void);

	//! 크기 메세지를 처리한다
	virtual void handleSizeMsg(HWND a_hWnd, WPARAM a_wParams, LPARAM a_lParams);

	//! 제거 메세지를 처리한다
	virtual void handleDestroyMsg(HWND a_hWnd, WPARAM a_wParams, LPARAM a_lParams);

	//! 윈도우를 생성한다
	virtual HWND createWnd(WNDCLASS &a_rstOutWndClass);

protected:			// 생성자, 소멸자

	//! 생성자
	CWndApp(HINSTANCE a_hInst, const SIZE &a_rstWndSize, int a_nShowOpts);

	//! 소멸자
	virtual ~CWndApp(void);

protected:			// protected 변수

	int m_nShowOpts = 0;

	SIZE m_stWndSize;
	WNDCLASS m_stWndClass;

	HWND m_hWnd = nullptr;
	HINSTANCE m_hInst = nullptr;

	HDC m_hDC = nullptr;
	HBITMAP m_hMemoryBitmap = nullptr;

	FILE *m_pstRStream = nullptr;
	FILE *m_pstWStream = nullptr;
};
