#pragma once

#include "../../Define/KGDefine.h"

class CSnd;

//! ���� ������
class CSndManager {
public:			// public �Լ�

	//! �̱���
	DECLARE_SINGLETON(CSndManager);

	//! �ʱ�ȭ
	void init(void);

private:			// private �Լ�

	//! ���̷�Ʈ ���带 �����Ѵ�
	IDirectSound8 * createDSnd(void);

	//! ���� ���۸� �����Ѵ�
	IDirectSoundBuffer8 * createSndBuffer(void);

private:			// private �Լ�

	//! ȿ������ ��ȸ�Ѵ�
	void enumerateFXSnds(const std::function<void (CSnd *)> &a_rCallback);

private:			// private ����

	IDirectSound8 *m_pDSnd = nullptr;
	IDirectSoundBuffer8 *m_pSndBuffer = nullptr;

	CSnd *m_pBGSnd = nullptr;
	std::unordered_map<std::string, std::vector<CSnd *>> m_oFXSndListContainer;
};
