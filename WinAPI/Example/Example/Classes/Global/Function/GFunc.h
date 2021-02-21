#pragma once

#include "../Define/KGDefine.h"

//! 전역 함수
class GFunc {
public:			// public 함수

	//! 동일 여부를 검사한다
	static bool isEquals(const float a_fLhs, const float a_fRhs);

	//! 포함 여부를 검사한다
	static bool isContains(const RECT &a_rstRect, const D3DXVECTOR2 &a_rstPoint);

	//! 포함 여부를 검사한다
	static bool isContains(const STCircle &a_rstCircle, const D3DXVECTOR2 &a_rstPoint);

	//! 영역을 생성한다
	static RECT makeRect(const D3DXVECTOR2 &a_rstPos, const D3DXVECTOR2 &a_rstSize);

	//! 영역을 생성한다
	static RECT makeLTRBRect(const D3DXVECTOR2 &a_rstPos, const D3DXVECTOR2 &a_rstSize);
};
