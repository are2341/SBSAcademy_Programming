#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdatable.h"
#include "../Interface/IRenderable.h"

//! 객체
class CObj : public IUpdatable, public IRenderable {
public:			// 인터페이스

	//! 상태를 갱신한다
	virtual void onUpdate(float a_fDeltaTime) override;

	//! 물체를 그린다
	virtual void onRender(HDC a_hDC) final override;

public:			// public 함수

	//! 위치를 반환한다
	D3DXVECTOR3 getPos(void) const;

	//! 크기를 반환한다
	D3DXVECTOR3 getSize(void) const;

	//! 부모 객체를 반환한다
	CObj * getParent(void) const;

	//! 부모 객체를 변경한다
	void setParent(CObj *a_pParent);

	//! 자식 객체를 추가한다
	void addChild(CObj *a_pChild);

public:			// 생성자, 소멸자

	//! 생성자
	CObj(const D3DXVECTOR3 &a_rstPos);

	//! 소멸자
	virtual ~CObj(void);

protected:			// protected 함수

	//! 물체를 그리기 전
	virtual void preRender(HDC a_hDC);

	//! 물체를 그린다
	virtual void doRender(HDC a_hDC);

	//! 물체를 그린 후
	virtual void postRender(HDC a_hDC);

protected:			// protected 변수

	D3DXVECTOR3 m_stPos;
	D3DXVECTOR3 m_stSize;

	CObj *m_pParent = nullptr;
	std::vector<CObj *> m_oChildList;
};
