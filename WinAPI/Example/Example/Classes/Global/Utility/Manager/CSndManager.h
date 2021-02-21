#pragma once

#include "../../Define/KGDefine.h"

class CSnd;

//! 사운드 관리자
class CSndManager {
public:			// public 함수

	//! 싱글턴
	DECLARE_SINGLETON(CSndManager);

	//! 초기화
	void init(void);

private:			// private 함수

	//! 다이렉트 사운드를 생성한다
	IDirectSound8 * createDSnd(void);

	//! 사운드 버퍼를 생성한다
	IDirectSoundBuffer8 * createSndBuffer(void);

private:			// private 함수

	//! 효과음을 순회한다
	void enumerateFXSnds(const std::function<void (CSnd *)> &a_rCallback);

private:			// private 변수

	IDirectSound8 *m_pDSnd = nullptr;
	IDirectSoundBuffer8 *m_pSndBuffer = nullptr;

	CSnd *m_pBGSnd = nullptr;
	std::unordered_map<std::string, std::vector<CSnd *>> m_oFXSndListContainer;
};
