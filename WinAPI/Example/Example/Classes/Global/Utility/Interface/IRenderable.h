#pragma once

#include "../../Define/KGDefine.h"

//! ������ �������̽�
class IRenderable {
public:			// �������̽�

	//! ��ü�� �׸���
	virtual void onRender(HDC a_hDC) = 0;
};
