#pragma once

#include "../../Define/KGDefine.h"

//! 갱신 인터페이스
class IUpdatable {
public:			// 인터페이스

	//! 상태를 갱신한다
	virtual void onUpdate(float a_fDeltaTime) = 0;
};
