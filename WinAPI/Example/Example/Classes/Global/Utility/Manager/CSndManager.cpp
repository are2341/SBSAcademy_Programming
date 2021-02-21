#include "CSndManager.h"
#include "../Base/CWndApp.h"

CSndManager::CSndManager(void) {
	// Do Nothing
}

CSndManager::~CSndManager(void) {
	SAFE_RELEASE(m_pSndBuffer);
	SAFE_RELEASE(m_pDSnd);
}

void CSndManager::init(void) {
	m_pDSnd = this->createDSnd();
	m_pSndBuffer = this->createSndBuffer();
}

IDirectSound8 * CSndManager::createDSnd(void) {
	IDirectSound8 *pDSnd = nullptr;
	DirectSoundCreate8(NULL, &pDSnd, NULL);

	pDSnd->SetCooperativeLevel(GET_WND_HANDLE(), DSSCL_PRIORITY);
	return pDSnd;
}

IDirectSoundBuffer8 * CSndManager::createSndBuffer(void) {
	DSBUFFERDESC stBufferDesc;
	ZeroMemory(&stBufferDesc, sizeof(stBufferDesc));

	IDirectSoundBuffer8 *pSndBuffer = nullptr;
	m_pDSnd->CreateSoundBuffer(&stBufferDesc, (IDirectSoundBuffer **)&pSndBuffer, NULL);

	return pSndBuffer;
}

void CSndManager::enumerateFXSnds(const std::function<void(CSnd*)>& a_rCallback) {
	for(auto &rstValueType : m_oFXSndListContainer) {
		for(auto pFXSnd : rstValueType.second) {
			a_rCallback(pFXSnd);
		}
	}
}
