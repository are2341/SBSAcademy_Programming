#pragma once

#include "../../Define/KGDefine.h"

//! ������ �޼��� ó����
class IWndMsgHandler {
public:			// �������̽�

	//! ������ �޼����� ó���Ѵ�
	virtual LRESULT handleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) = 0;
};
