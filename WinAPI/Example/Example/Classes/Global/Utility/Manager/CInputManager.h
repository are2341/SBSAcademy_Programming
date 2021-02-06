#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdatable.h"

//! �Է� ������
class CInputManager : public IUpdatable {
public:			// �������̽�
	
	//! ���¸� �����Ѵ�
	virtual void onUpdate(float a_fDeltaTime) override;

public:			// public �Լ�

	DECLARE_SINGLETON(CInputManager);

	//! �ʱ�ȭ
	void init(void);

	//! Ű ���� ���θ� ��ȯ�Ѵ�
	bool isKeyDown(int a_nKeyCode) const;

	//! Ű ���� ���� ���θ� ��ȯ�Ѵ�
	bool isKeyPress(int a_nKeyCode) const;

	//! Ű ���� ���� ���θ� ��ȯ�Ѵ�
	bool isKeyRelease(int a_nKeyCode) const;

	//! ���콺 ��ư ���� ���θ� ��ȯ�Ѵ�
	bool isMouseBtnDown(EMouseBtn a_eBtn) const;

	//! ���콺 ��ư ���� ���� ���θ� ��ȯ�Ѵ�
	bool isMouseBtnPress(EMouseBtn a_eBtn) const;

	//! ���콺 ��ư ���� ���� ���θ� ��ȯ�Ѵ�
	bool isMouseBtnRelease(EMouseBtn a_eBtn) const;

	//! ���콺 ��ġ�� ��ȯ�Ѵ�
	POINT getMousePos(void) const;

private:			// private �Լ�

	//! ���̷�Ʈ �Է��� �����Ѵ�
	IDirectInput8 * createDInput(void);

	//! Ű���� ����̽��� �����Ѵ�
	IDirectInputDevice8 * createKeyboardDevice(void);

	//! ���콺 ����̽��� �����Ѵ�
	IDirectInputDevice8 * createMouseDevice(void);

private:			// private ����

	char m_anKeyStates[UCHAR_MAX + 1];
	char m_anPrevKeyStates[UCHAR_MAX + 1];

	DIMOUSESTATE m_stMouseState;
	DIMOUSESTATE m_stPrevMouseState;

	IDirectInput8 *m_pDInput = nullptr;

	IDirectInputDevice8 *m_pKeyboardDevice = nullptr;
	IDirectInputDevice8 *m_pMouseDevice = nullptr;
};
