#pragma once

#include "../../Define/KGDefine.h"

//! 윈도우 메세지 처리자
class IWndMsgHandler {
public:			// 인터페이스

	//! 윈도우 메세지를 처리한다
	virtual LRESULT handleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) = 0;
};
