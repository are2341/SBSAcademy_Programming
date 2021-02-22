#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdatable.h"
#include "../Interface/IRenderable.h"

//! 객체
class CObj : public IUpdatable, public IRenderable {
public:			// 인터페이스

	//! 상태를 갱신한다
	virtual void onUpdate(float a_fDeltaTime) final override;

	//! 물체를 그린다
	virtual void onRender(HDC a_hDC) final override;

public:			// public 함수

	//! 위치를 반환한다
	D3DXVECTOR2 getPos(void) const;

	//! 월드 위치를 반환한다
	D3DXVECTOR2 getWorldPos(void) const;

	//! 크기를 반환한다
	D3DXVECTOR2 getSize(void) const;

	//! 부모 객체를 반환한다
	CObj * getParent(void) const;

	//! 위치를 변경한다
	void setPos(const D3DXVECTOR2 &a_rstPos);

	//! 크기를 변경한다
	void setSize(const D3DXVECTOR2 &a_rstSize);

	//! 부모 객체를 변경한다
	void setParent(CObj *a_pParent);

	//! 자식 객체를 추가한다
	void addChild(CObj *a_pChild);

	//! 자식 객체를 제거한다
	void removeChild(CObj *a_pChild);

public:			// 생성자, 소멸자

	//! 생성자
	CObj(const D3DXVECTOR2 &a_rstPos);

	//! 생성자
	CObj(const D3DXVECTOR2 &a_rstPos, const D3DXVECTOR2 &a_rstSize);

	//! 소멸자
	virtual ~CObj(void);

protected:			// protected 함수

	//! 상태를 갱신한다
	virtual void doUpdate(float a_fDeltaTime);

	//! 물체를 그리기 전
	virtual void preRender(HDC a_hDC);

	//! 물체를 그린다
	virtual void doRender(HDC a_hDC);

	//! 물체를 그린 후
	virtual void postRender(HDC a_hDC);

protected:			// protected 변수

	D3DXVECTOR2 m_stPos;
	D3DXVECTOR2 m_stWorldPos;

	D3DXVECTOR2 m_stSize;

	CObj *m_pParent = nullptr;
	std::vector<CObj *> m_oChildList;
};
