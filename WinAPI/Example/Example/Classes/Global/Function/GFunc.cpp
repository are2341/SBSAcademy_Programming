#include "GFunc.h"

bool GFunc::isEquals(const float a_fLhs, const float a_fRhs) {
	return fabsf(a_fLhs - a_fRhs) < FLT_EPSILON;
}

bool GFunc::isContains(const RECT & a_rstRect, const D3DXVECTOR2 & a_rstPoint) {
	return false;
}

bool GFunc::isContains(const STCircle & a_rstCircle, const D3DXVECTOR2 & a_rstPoint) {

}

RECT GFunc::makeRect(const D3DXVECTOR2 & a_rstPos, const D3DXVECTOR2 & a_rstSize) {
	RECT stRect = {
		(int)(a_rstPos.x - (a_rstSize.x / 2.0f)),
		(int)(a_rstPos.y - (a_rstSize.y / 2.0f)),
		(int)(a_rstPos.x + a_rstSize.x),
		(int)(a_rstPos.y + a_rstSize.y)
	};

	return stRect;
}

RECT GFunc::makeLTRBRect(const D3DXVECTOR2 & a_rstPos, const D3DXVECTOR2 & a_rstSize) {
	RECT stRect = {
		(int)(a_rstPos.x - (a_rstSize.x / 2.0f)),
		(int)(a_rstPos.y - (a_rstSize.y / 2.0f)),
		(int)(a_rstPos.x + (a_rstSize.x / 2.0f)),
		(int)(a_rstPos.y + (a_rstSize.y / 2.0f))
	};

	return stRect;
}
