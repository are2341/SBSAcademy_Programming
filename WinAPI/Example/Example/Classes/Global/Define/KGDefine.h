#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
#include <functional>
#include <vector>
#include <unordered_map>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <dsound.h>
#include <Windows.h>
#include <tchar.h>

// 리소스 정리 {
#define SAFE_FREE(TARGET)			if((TARGET) != nullptr) { free((TARGET)); (TARGET) = nullptr; }
#define SAFE_FCLOSE(TARGET)			if((TARGET) != nullptr) { fclose((TARGET)); (TARGET) = nullptr; }

#define SAFE_DELETE(TARGET)					if((TARGET) != nullptr) { delete (TARGET); (TARGET) = nullptr; }
#define SAFE_DELETE_ARRAY(TARGET)			if((TARGET) != nullptr) { delete[] (TARGET); (TARGET) = nullptr; }

#define SAFE_DELETE_DC(TARGET)							if((TARGET) != nullptr) { DeleteDC((TARGET)); (TARGET) = nullptr; }
#define SAFE_DELETE_OBJ(TARGET)							if((TARGET) != nullptr) { DeleteObject((TARGET)); (TARGET) = nullptr; }
#define SAFE_RELEASE_DC(TARGET_WND, TARGET_DC)			if((TARGET_WND) != NULL && (TARGET_DC) != NULL) { ReleaseDC((TARGET_WND), (TARGET_DC)); (TARGET_DC) = nullptr; }

#define SAFE_RELEASE(TARGET)			if((TARGET) != nullptr) { (TARGET)->Release(); (TARGET) = nullptr; }
#define SAFE_UNACQUIRE(TARGET)			if((TARGET) != nullptr) { (TARGET)->Unacquire(); SAFE_RELEASE(TARGET); }
// 리소스 정리 }

// 윈도우 어플리케이션
#define GET_WND_APP()				(CWndApp::getInst())
#define GET_WND_HANDLE()			(GET_WND_APP()->getWndHandle())
#define GET_INST_HANDLE()			(GET_WND_APP()->getInstHandle())

// 입력 관리자 {
#define GET_INPUT_MANAGER()			(CInputManager::getInst())
#define GET_MOUSE_POS()				(GET_INPUT_MANAGER()->getMousePos())

#define IS_KEY_DOWN(KEY_CODE)				(GET_INPUT_MANAGER()->isKeyDown((KEY_CODE)))
#define IS_KEY_PRESS(KEY_CODE)				(GET_INPUT_MANAGER()->isKeyPress((KEY_CODE)))
#define IS_KEY_RELEASE(KEY_CODE)			(GET_INPUT_MANAGER()->isKeyRelease((KEY_CODE)))

#define IS_MOUSE_BTN_DOWN(MOUSE_BTN)			(GET_INPUT_MANAGER()->isMouseBtnDown((MOUSE_BTN)))
#define IS_MOUSE_BTN_PRESS(MOUSE_BTN)			(GET_INPUT_MANAGER()->isMouseBtnPress((MOUSE_BTN)))
#define IS_MOUSE_BTN_RELEASE(MOUSE_BTN)			(GET_INPUT_MANAGER()->isMouseBtnRelease((MOUSE_BTN)))
// 입력 관리자 }

// 리소스 관리자 {
#define GET_RES_MANAGER()			(CResManager::getInst())

#define GET_DC(KEY)				(GET_RES_MANAGER()->getDC((KEY)))
#define GET_BITMAP(KEY)			(GET_RES_MANAGER()->getBitmap((KEY)))
// 리소스 관리자 }

#define DECLARE_SINGLETON(CLS_NAME)			\
private:									\
CLS_NAME(void);								\
~CLS_NAME(void);							\
public:										\
static CLS_NAME * getInst(void) {			\
	static CLS_NAME oInst;					\
	return &oInst;							\
}

//! 마우스 버튼
enum class EMouseBtn {
	NONE = -1,
	LEFT,
	RIGHT,
	MIDDLE,
	MAX_VALUE
};

//! 원
struct STCircle {
	float m_fRadius;
	D3DXVECTOR2 m_stCenter;
};
