#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdatable.h"
#include "../Interface/IRenderable.h"
#include "../Interface/IWndMsgHandler.h"

class CObj;

//! ������ ���ø����̼�
class CWndApp : public IUpdatable, public IRenderable, public IWndMsgHandler {
public:			// �������̽�

	//! ���¸� �����Ѵ�
	virtual void onUpdate(float a_fDeltaTime) override;

	//! ��ü�� �׸���
	virtual void onRender(HDC a_hDC) override;

	//! ������ �޼����� ó���Ѵ�
	virtual LRESULT handleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) override;

public:			// public �Լ�

	//! ������ ũ�⸦ ��ȯ�Ѵ�
	SIZE getWndSize(void) const;

	//! ������ �ڵ��� ��ȯ�Ѵ�
	HWND getWndHandle(void) const;

	//! �ν��Ͻ� �ڵ��� ��ȯ�Ѵ�
	HINSTANCE getInstHandle(void) const;

	//! ��Ʈ ��ü�� �����Ѵ�
	void setRoot(CObj *a_pRoot);

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

	//! ��Ʈ ��ü�� �����Ѵ�
	virtual CObj * createRoot(void);

protected:			// ������, �Ҹ���

	//! ������
	CWndApp(HINSTANCE a_hInst, const SIZE &a_rstWndSize, int a_nShowOpts);

	//! �Ҹ���
	virtual ~CWndApp(void);

protected:			// protected ����

	int m_nShowOpts = 0;
	float m_fRunningTime = 0.0f;

	SIZE m_stWndSize;
	RECT m_stWndRect;
	WNDCLASS m_stWndClass;

	LARGE_INTEGER m_unPrevTime;
	LARGE_INTEGER m_unFrequency;

	HWND m_hWnd = nullptr;
	HINSTANCE m_hInst = nullptr;

	HDC m_hDC = nullptr;
	HBITMAP m_hMemoryBitmap = nullptr;

	CObj *m_pRoot = nullptr;
	CObj *m_pNextRoot = nullptr;

	FILE *m_pstRStream = nullptr;
	FILE *m_pstWStream = nullptr;
};
