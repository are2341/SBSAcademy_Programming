#pragma once

#include "../../Define/KGDefine.h"
#include "../Base/CObj.h"

//! 비트맵
class CBitmap : public CObj {
public:			// public 함수

	//! 비트맵 영역을 반환한다
	RECT getBitmapRect(void) const;

	//! 비트맵 영역을 변경한다
	void setBitmapRect(const RECT &a_rstBitmapRect);

public:			// 생성자

	//! 생성자
	CBitmap(const std::string &a_rFilePath, const D3DXVECTOR2 &a_rstPos);

protected:			// protected 함수

	//! 물체를 그린다
	virtual void doRender(HDC a_hDC) override;

private:			// private 변수

	RECT m_stBitmapRect;

	HBITMAP m_hBitmap = nullptr;
	std::string m_oFilePath = "";
};
