#pragma once

#include "../../Define/KGDefine.h"

//! ���� �������̽�
class IUpdatable {
public:			// �������̽�

	//! ���¸� �����Ѵ�
	virtual void onUpdate(float a_fDeltaTime) = 0;
};
