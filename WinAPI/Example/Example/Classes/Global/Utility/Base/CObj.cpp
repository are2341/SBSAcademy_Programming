#include "CObj.h"

CObj::CObj(const D3DXVECTOR3 & a_rstPos) 
:
m_stPos(a_rstPos)
{
	ZeroMemory(&m_stSize, sizeof(m_stSize));
}

CObj::~CObj(void) {
	for(auto pChild : m_oChildList) {
		SAFE_DELETE(pChild);
	}
}

void CObj::onUpdate(float a_fDeltaTime) {
	// Do Nothing
}

void CObj::onRender(HDC a_hDC) {
	this->preRender(a_hDC);
	this->doRender(a_hDC);
	this->postRender(a_hDC);
}

D3DXVECTOR3 CObj::getPos(void) const {
	return m_stPos;
}

D3DXVECTOR3 CObj::getSize(void) const {
	return m_stSize;
}

CObj * CObj::getParent(void) const {
	return m_pParent;
}

void CObj::setParent(CObj * a_pParent) {
	assert(m_pParent == nullptr);
	m_pParent = a_pParent;
}

void CObj::addChild(CObj * a_pChild) {
	assert(a_pChild->getParent() == nullptr);

	a_pChild->setParent(this);
	m_oChildList.push_back(a_pChild);
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
