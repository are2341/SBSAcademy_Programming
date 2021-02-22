#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdatable.h"
#include "../Interface/IRenderable.h"

//! ��ü
class CObj : public IUpdatable, public IRenderable {
public:			// �������̽�

	//! ���¸� �����Ѵ�
	virtual void onUpdate(float a_fDeltaTime) final override;

	//! ��ü�� �׸���
	virtual void onRender(HDC a_hDC) final override;

public:			// public �Լ�

	//! ��ġ�� ��ȯ�Ѵ�
	D3DXVECTOR2 getPos(void) const;

	//! ���� ��ġ�� ��ȯ�Ѵ�
	D3DXVECTOR2 getWorldPos(void) const;

	//! ũ�⸦ ��ȯ�Ѵ�
	D3DXVECTOR2 getSize(void) const;

	//! �θ� ��ü�� ��ȯ�Ѵ�
	CObj * getParent(void) const;

	//! ��ġ�� �����Ѵ�
	void setPos(const D3DXVECTOR2 &a_rstPos);

	//! ũ�⸦ �����Ѵ�
	void setSize(const D3DXVECTOR2 &a_rstSize);

	//! �θ� ��ü�� �����Ѵ�
	void setParent(CObj *a_pParent);

	//! �ڽ� ��ü�� �߰��Ѵ�
	void addChild(CObj *a_pChild);

	//! �ڽ� ��ü�� �����Ѵ�
	void removeChild(CObj *a_pChild);

public:			// ������, �Ҹ���

	//! ������
	CObj(const D3DXVECTOR2 &a_rstPos);

	//! ������
	CObj(const D3DXVECTOR2 &a_rstPos, const D3DXVECTOR2 &a_rstSize);

	//! �Ҹ���
	virtual ~CObj(void);

protected:			// protected �Լ�

	//! ���¸� �����Ѵ�
	virtual void doUpdate(float a_fDeltaTime);

	//! ��ü�� �׸��� ��
	virtual void preRender(HDC a_hDC);

	//! ��ü�� �׸���
	virtual void doRender(HDC a_hDC);

	//! ��ü�� �׸� ��
	virtual void postRender(HDC a_hDC);

protected:			// protected ����

	D3DXVECTOR2 m_stPos;
	D3DXVECTOR2 m_stWorldPos;

	D3DXVECTOR2 m_stSize;

	CObj *m_pParent = nullptr;
	std::vector<CObj *> m_oChildList;
};
