#include "CResManager.h"
#include "../Base/CWndApp.h"

CResManager::CResManager(void) {
	// Do Nothing
}

CResManager::~CResManager(void) {
	for(auto &rstValueType : m_oDCList) {
		SAFE_DELETE_OBJ(rstValueType.second);
	}

	for(auto &rstValueType : m_oBitmapList) {
		SAFE_DELETE_OBJ(rstValueType.second);
	}
}

void CResManager::init(void) {
	// Do Nothing
}

HDC CResManager::getDC(const std::string & a_rKey, bool a_bIsAutoCreate) {
	// DC 생성이 가능 할 경우
	if(a_bIsAutoCreate && m_oDCList.find(a_rKey) == m_oDCList.end()) {
		auto hDC = GetDC(GET_WND_HANDLE());
		auto hMemoryDC = CreateCompatibleDC(hDC);

		m_oDCList.insert(decltype(m_oDCList)::value_type(a_rKey, hMemoryDC));
		SAFE_RELEASE_DC(GET_WND_HANDLE(), hDC);
	}

	assert(m_oDCList.find(a_rKey) != m_oDCList.end());
	return m_oDCList[a_rKey];
}

HBITMAP CResManager::getBitmap(const std::string & a_rKey, bool a_bIsAutoCreate) {
	// 비트맵 생성이 가능 할 경우
	if(a_bIsAutoCreate && m_oBitmapList.find(a_rKey) == m_oBitmapList.end()) {
		auto hBitmap = (HBITMAP)LoadImageA(NULL, a_rKey.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		m_oBitmapList.insert(decltype(m_oBitmapList)::value_type(a_rKey, hBitmap));
	}

	assert(m_oBitmapList.find(a_rKey) != m_oBitmapList.end());
	return m_oBitmapList[a_rKey];
}
