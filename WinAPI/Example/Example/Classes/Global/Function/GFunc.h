#pragma once

#include "../Define/KGDefine.h"

//! ���� �Լ�
class GFunc {
public:			// public �Լ�

	//! ���� ���θ� �˻��Ѵ�
	static bool isEquals(const float a_fLhs, const float a_fRhs);

	//! ���� ���θ� �˻��Ѵ�
	static bool isContains(const RECT &a_rstRect, const D3DXVECTOR2 &a_rstPoint);

	//! ���� ���θ� �˻��Ѵ�
	static bool isContains(const STCircle &a_rstCircle, const D3DXVECTOR2 &a_rstPoint);

	//! ������ �����Ѵ�
	static RECT makeRect(const D3DXVECTOR2 &a_rstPos, const D3DXVECTOR2 &a_rstSize);

	//! ������ �����Ѵ�
	static RECT makeLTRBRect(const D3DXVECTOR2 &a_rstPos, const D3DXVECTOR2 &a_rstSize);
};
