#pragma once

#include "../../Define/KGDefine.h"
#include "../Base/CObj.h"

//! ����
class CSnd : public CObj {
public:			// ������, �Ҹ���

	//! ������
	CSnd(const std::string &a_rSndPath);

	//! �Ҹ���
	virtual ~CSnd(void);

private:			// private ����

	std::string m_oSndPath = "";
	IDirectSoundBuffer8 *m_pSndBuffer = nullptr;
};
