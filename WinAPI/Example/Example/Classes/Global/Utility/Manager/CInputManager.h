#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdatable.h"

//! 입력 관리자
class CInputManager : public IUpdatable {
public:			// 인터페이스
	
	//! 상태를 갱신한다
	virtual void onUpdate(float a_fDeltaTime) override;

public:			// public 함수

	DECLARE_SINGLETON(CInputManager);

	//! 초기화
	void init(void);

	//! 키 눌림 여부를 반환한다
	bool isKeyDown(int a_nKeyCode) const;

	//! 키 눌림 시작 여부를 반환한다
	bool isKeyPress(int a_nKeyCode) const;

	//! 키 눌림 종료 여부를 반환한다
	bool isKeyRelease(int a_nKeyCode) const;

	//! 마우스 버튼 눌림 여부를 반환한다
	bool isMouseBtnDown(EMouseBtn a_eBtn) const;

	//! 마우스 버튼 눌림 시작 여부를 반환한다
	bool isMouseBtnPress(EMouseBtn a_eBtn) const;

	//! 마우스 버튼 눌림 종료 여부를 반환한다
	bool isMouseBtnRelease(EMouseBtn a_eBtn) const;

	//! 마우스 위치를 반환한다
	POINT getMousePos(void) const;

private:			// private 함수

	//! 다이렉트 입력을 생성한다
	IDirectInput8 * createDInput(void);

	//! 키보드 디바이스를 생성한다
	IDirectInputDevice8 * createKeyboardDevice(void);

	//! 마우스 디바이스를 생성한다
	IDirectInputDevice8 * createMouseDevice(void);

private:			// private 변수

	char m_anKeyStates[UCHAR_MAX + 1];
	char m_anPrevKeyStates[UCHAR_MAX + 1];

	DIMOUSESTATE m_stMouseState;
	DIMOUSESTATE m_stPrevMouseState;

	IDirectInput8 *m_pDInput = nullptr;

	IDirectInputDevice8 *m_pKeyboardDevice = nullptr;
	IDirectInputDevice8 *m_pMouseDevice = nullptr;
};
