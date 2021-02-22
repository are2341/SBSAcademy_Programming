#include "CObj.h"

CObj::CObj(const D3DXVECTOR2 & a_rstPos)
: CObj(a_rstPos, D3DXVECTOR2(0.0f, 0.0f))
{
	// Do Nothing
}

CObj::CObj(const D3DXVECTOR2 & a_rstPos, const D3DXVECTOR2 & a_rstSize) 
:
m_stPos(a_rstPos),
m_stSize(a_rstSize)
{
	m_stWorldPos = a_rstPos;
}

CObj::~CObj(void) {
	for(auto pChild : m_oChildList) {
		SAFE_DELETE(pChild);
	}
}

void CObj::onUpdate(float a_fDeltaTime) {
	this->doUpdate(a_fDeltaTime);

	// 부모 객체가 존재 할 경우
	if(m_pParent != nullptr) {
		m_stWorldPos = m_stPos + m_pParent->getPos();
	} else {
		m_stWorldPos = m_stPos;
	}

	for(auto pChild : m_oChildList) {
		pChild->doUpdate(a_fDeltaTime);
	}
}

void CObj::onRender(HDC a_hDC) {
	this->preRender(a_hDC);
	this->doRender(a_hDC);
	this->postRender(a_hDC);

	for(auto pChild : m_oChildList) {
		pChild->onRender(a_hDC);
	}
}

D3DXVECTOR2 CObj::getPos(void) const {
	return m_stPos;
}

D3DXVECTOR2 CObj::getWorldPos(void) const {
	return m_stWorldPos;
}

D3DXVECTOR2 CObj::getSize(void) const {
	return m_stSize;
}

CObj * CObj::getParent(void) const {
	return m_pParent;
}

void CObj::setPos(const D3DXVECTOR2 & a_rstPos) {
	m_stPos = a_rstPos;
}

void CObj::setSize(const D3DXVECTOR2 & a_rstSize) {
	m_stSize = a_rstSize;
}

void CObj::setParent(CObj * a_pParent) {
	// 부모 객체가 존재 할 경우
	if(m_pParent != nullptr) {
		m_pParent->removeChild(this);
	}

	m_pParent = a_pParent;

	// 부모 객체가 존재 할 경우
	if(a_pParent != nullptr) {
		auto oIterator = std::find(a_pParent->m_oChildList.begin(), a_pParent->m_oChildList.end(), this);

		// 자식 객체가 없을 경우
		if(oIterator == a_pParent->m_oChildList.end()) {
			a_pParent->m_oChildList.push_back(this);
		}
	}
}

void CObj::addChild(CObj * a_pChild) {
	assert(a_pChild->getParent() == nullptr);
	m_oChildList.push_back(a_pChild);

	a_pChild->setParent(this);
}

void CObj::removeChild(CObj * a_pChild) {
	auto oIterator = std::find(m_oChildList.begin(), m_oChildList.end(), a_pChild);

	// 자식 객체가 존재 할 경우
	if(oIterator != m_oChildList.end()) {
		m_oChildList.erase(oIterator);
	}
}

void CObj::doUpdate(float a_fDeltaTime) {
	// Do Nothing
}

void CObj::preRender(HDC a_hDC) {
	// Do Nothing
}

void CObj::doRender(HDC a_hDC) {
	// Do Nothing
}

void CObj::postRender(HDC a_hDC) {
	for(auto pChild : m_oChildList) {
		pChild->onRender(a_hDC);
	}
}
