#pragma once

#include "../../Define/KGDefine.h"

//! 렌더링 인터페이스
class IRenderable {
public:			// 인터페이스

	//! 물체를 그린다
	virtual void onRender(HDC a_hDC) = 0;
};
