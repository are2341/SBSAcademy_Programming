#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IWndMsgHandler.h"

//! ������ ���ø����̼�
class CWndApp : public IWndMsgHandler {
public:			// IWndMsgHandler

	//! ������ �޼����� ó���Ѵ�
	virtual LRESULT handleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) override;

public:			// public �Լ�

	//! ������ ũ�⸦ ��ȯ�Ѵ�
	SIZE getWndSize(void) const;

	//! ������ �ڵ��� ��ȯ�Ѵ�
	HWND getWndHandle(void) const;

	//! �ν��Ͻ� �ڵ��� ��ȯ�Ѵ�
	HINSTANCE getInstHandle(void) const;

	//! ���ø����̼��� �����Ѵ�
	int run(void);

	//! �ν��Ͻ��� ��ȯ�Ѵ�
	static CWndApp * getInst(void);

protected:			// protected �Լ�

	//! �ʱ�ȭ
	virtual void init(void);

	//! �޼��� ������ �����Ѵ�
	virtual int runMsgLoop(void);

	//! ũ�� �޼����� ó���Ѵ�
	virtual void handleSizeMsg(HWND a_hWnd, WPARAM a_wParams, LPARAM a_lParams);

	//! ���� �޼����� ó���Ѵ�
	virtual void handleDestroyMsg(HWND a_hWnd, WPARAM a_wParams, LPARAM a_lParams);

	//! �����츦 �����Ѵ�
	virtual HWND createWnd(WNDCLASS &a_rstOutWndClass);

protected:			// ������, �Ҹ���

	//! ������
	CWndApp(HINSTANCE a_hInst, const SIZE &a_rstWndSize, int a_nShowOpts);

	//! �Ҹ���
	virtual ~CWndApp(void);

protected:			// protected ����

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
