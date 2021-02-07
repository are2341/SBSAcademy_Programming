#pragma once

#include "../../Define/KGDefine.h"

//! ���ҽ� ������
class CResManager {
public:			// public �Լ�

	//! �̱���
	DECLARE_SINGLETON(CResManager);

	//! �ʱ�ȭ
	void init(void);

	//! DC �� ��ȯ�Ѵ�
	HDC getDC(const std::string &a_rKey, bool a_bIsAutoCreate = true);

	//! ��Ʈ���� ��ȯ�Ѵ�
	HBITMAP getBitmap(const std::string &a_rKey, bool a_bIsAutoCreate = true);

private:			// private �Լ�

	std::unordered_map<std::string, HDC> m_oDCList;
	std::unordered_map<std::string, HBITMAP> m_oBitmapList;
};
