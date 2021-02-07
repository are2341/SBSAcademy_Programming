#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdatable.h"
#include "../Interface/IRenderable.h"

//! ��ü
class CObj : public IUpdatable, public IRenderable {
public:			// �������̽�

	//! ���¸� �����Ѵ�
	virtual void onUpdate(float a_fDeltaTime) override;

	//! ��ü�� �׸���
	virtual void onRender(HDC a_hDC) final override;

public:			// public �Լ�

	//! ��ġ�� ��ȯ�Ѵ�
	D3DXVECTOR3 getPos(void) const;

	//! ũ�⸦ ��ȯ�Ѵ�
	D3DXVECTOR3 getSize(void) const;

	//! �θ� ��ü�� ��ȯ�Ѵ�
	CObj * getParent(void) const;

	//! �θ� ��ü�� �����Ѵ�
	void setParent(CObj *a_pParent);

	//! �ڽ� ��ü�� �߰��Ѵ�
	void addChild(CObj *a_pChild);

public:			// ������, �Ҹ���

	//! ������
	CObj(const D3DXVECTOR3 &a_rstPos);

	//! �Ҹ���
	virtual ~CObj(void);

protected:			// protected �Լ�

	//! ��ü�� �׸��� ��
	virtual void preRender(HDC a_hDC);

	//! ��ü�� �׸���
	virtual void doRender(HDC a_hDC);

	//! ��ü�� �׸� ��
	virtual void postRender(HDC a_hDC);

protected:			// protected ����

	D3DXVECTOR3 m_stPos;
	D3DXVECTOR3 m_stSize;

	CObj *m_pParent = nullptr;
	std::vector<CObj *> m_oChildList;
};
