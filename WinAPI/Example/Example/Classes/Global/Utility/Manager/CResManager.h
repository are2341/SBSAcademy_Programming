#pragma once

#include "../../Define/KGDefine.h"

//! 리소스 관리자
class CResManager {
public:			// public 함수

	//! 싱글턴
	DECLARE_SINGLETON(CResManager);

	//! 초기화
	void init(void);

	//! DC 를 반환한다
	HDC getDC(const std::string &a_rKey, bool a_bIsAutoCreate = true);

	//! 비트맵을 반환한다
	HBITMAP getBitmap(const std::string &a_rKey, bool a_bIsAutoCreate = true);

private:			// private 함수

	std::unordered_map<std::string, HDC> m_oDCList;
	std::unordered_map<std::string, HBITMAP> m_oBitmapList;
};
