#include "CInputManager.h"
#include "../Base/CWndApp.h"

CInputManager::CInputManager(void) {
	ZeroMemory(m_anKeyStates, sizeof(m_anKeyStates));
	ZeroMemory(m_anPrevKeyStates, sizeof(m_anPrevKeyStates));

	ZeroMemory(&m_stMouseState, sizeof(m_stMouseState));
	ZeroMemory(&m_stPrevMouseState, sizeof(m_stPrevMouseState));
}

CInputManager::~CInputManager(void) {
	// Do Nothing
}

void CInputManager::onUpdate(float a_fDeltaTime) {
	CopyMemory(m_anKeyStates, m_anKeyStates, sizeof(m_anKeyStates));
	CopyMemory(&m_stPrevMouseState, &m_stMouseState, sizeof(m_stMouseState));

	m_pKeyboardDevice->GetDeviceState(sizeof(m_anKeyStates), m_anKeyStates);
	m_pMouseDevice->GetDeviceState(sizeof(m_stMouseState), &m_stMouseState);
}

void CInputManager::init(void) {
	m_pDInput = this->createDInput();

	m_pKeyboardDevice = this->createKeyboardDevice();
	m_pMouseDevice = this->createMouseDevice();
}

bool CInputManager::isKeyDown(int a_nKeyCode) const {
	return m_anKeyStates[a_nKeyCode] & 0x80;
}

bool CInputManager::isKeyPress(int a_nKeyCode) const {
	return this->isKeyDown(a_nKeyCode) && !(m_anPrevKeyStates[a_nKeyCode] & 0x80);
}

bool CInputManager::isKeyRelease(int a_nKeyCode) const {
	return !this->isKeyDown(a_nKeyCode) && (m_anPrevKeyStates[a_nKeyCode] & 0x80);
}

bool CInputManager::isMouseBtnDown(EMouseBtn a_eBtn) const {
	return m_stMouseState.rgbButtons[(int)a_eBtn] & 0x80;
}

bool CInputManager::isMouseBtnPress(EMouseBtn a_eBtn) const {
	return this->isMouseBtnDown(a_eBtn) && !(m_stPrevMouseState.rgbButtons[(int)a_eBtn] & 0x80);
}

bool CInputManager::isMouseBtnRelease(EMouseBtn a_eBtn) const {
	return !this->isMouseBtnDown(a_eBtn) && (m_stPrevMouseState.rgbButtons[(int)a_eBtn] & 0x80);
}

long CInputManager::getWheelDelta(void) const {
	return m_stMouseState.lZ;
}

POINT CInputManager::getMousePos(void) const {
	POINT stMousePos = { 0 };

	GetCursorPos(&stMousePos);
	ScreenToClient(GET_WND_HANDLE(), &stMousePos);

	return stMousePos;
}

IDirectInput8 * CInputManager::createDInput(void) {
	IDirectInput8 *pDInput = nullptr;
	DirectInput8Create(GET_INST_HANDLE(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void **)&pDInput, NULL);

	return pDInput;
}

IDirectInputDevice8 * CInputManager::createKeyboardDevice(void) {
	IDirectInputDevice8 *pKeyboardDevice = nullptr;
	m_pDInput->CreateDevice(GUID_SysKeyboard, &pKeyboardDevice, NULL);

	pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	pKeyboardDevice->SetCooperativeLevel(GET_WND_HANDLE(), DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
	pKeyboardDevice->Acquire();

	return pKeyboardDevice;
}

IDirectInputDevice8 * CInputManager::createMouseDevice(void) {
	IDirectInputDevice8 *pMouseDevice = nullptr;
	m_pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice, NULL);

	pMouseDevice->SetDataFormat(&c_dfDIMouse);
	pMouseDevice->SetCooperativeLevel(GET_WND_HANDLE(), DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
	pMouseDevice->Acquire();

	return pMouseDevice;
}
