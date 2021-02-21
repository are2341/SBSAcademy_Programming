#pragma once

#include "../../Define/KGDefine.h"
#include "../Base/CObj.h"

//! 사운드
class CSnd : public CObj {
public:			// 생성자, 소멸자

	//! 생성자
	CSnd(const std::string &a_rSndPath);

	//! 소멸자
	virtual ~CSnd(void);

private:			// private 변수

	std::string m_oSndPath = "";
	IDirectSoundBuffer8 *m_pSndBuffer = nullptr;
};
