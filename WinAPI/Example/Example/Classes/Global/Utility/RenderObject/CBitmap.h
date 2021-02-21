#pragma once

#include "../../Define/KGDefine.h"
#include "../Base/CObj.h"

//! ��Ʈ��
class CBitmap : public CObj {
public:			// public �Լ�

	//! ��Ʈ�� ������ ��ȯ�Ѵ�
	RECT getBitmapRect(void) const;

	//! ��Ʈ�� ������ �����Ѵ�
	void setBitmapRect(const RECT &a_rstBitmapRect);

public:			// ������

	//! ������
	CBitmap(const std::string &a_rFilePath, const D3DXVECTOR2 &a_rstPos);

protected:			// protected �Լ�

	//! ��ü�� �׸���
	virtual void doRender(HDC a_hDC) override;

private:			// private ����

	RECT m_stBitmapRect;

	HBITMAP m_hBitmap = nullptr;
	std::string m_oFilePath = "";
};
