#include "CSnd.h"

CSnd::CSnd(const std::string & a_rSndPath) 
: CObj(D3DXVECTOR2(0.0f, 0.0f))
{
	// Do Nothing
}

CSnd::~CSnd(void) {
	SAFE_RELEASE(m_pSndBuffer);
}
