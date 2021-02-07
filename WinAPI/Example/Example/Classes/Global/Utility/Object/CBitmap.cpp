#include "CBitmap.h"
#include "../Manager/CResManager.h"

CBitmap::CBitmap(const std::string & a_rFilePath, const D3DXVECTOR3 &a_rstPos)
: CObj(a_rstPos),
m_oFilePath(a_rFilePath)
{
	m_hBitmap = GET_BITMAP(a_rFilePath);
	ZeroMemory(&m_stBitmapRect, sizeof(m_stBitmapRect));

	BITMAP stBitmap;
	GetObject(m_hBitmap, sizeof(stBitmap), &stBitmap);

	m_stSize = D3DXVECTOR3(stBitmap.bmWidth, stBitmap.bmHeight, 0.0f);

	m_stBitmapRect.right = stBitmap.bmWidth;
	m_stBitmapRect.bottom = stBitmap.bmHeight;
}

void CBitmap::setBitmapRect(const RECT & a_rstBitmapRect) {
	m_stBitmapRect = a_rstBitmapRect;
}

void CBitmap::doRender(HDC a_hDC) {
	auto hPrevBitmap = SelectObject(GET_DC(m_oFilePath), m_hBitmap);
	auto stWorldPos = (m_pParent == nullptr) ? m_stPos : m_stPos + m_pParent->getPos();

	RECT stRect = {
		(int)(stWorldPos.x - (m_stSize.x / 2.0f)),
		(int)(stWorldPos.y - (m_stSize.y / 2.0f)),
		(int)(stWorldPos.x + m_stSize.x),
		(int)(stWorldPos.y + m_stSize.y)
	};

	StretchBlt(a_hDC, stRect.left, stRect.top, stRect.right, stRect.bottom, GET_DC(m_oFilePath), m_stBitmapRect.left, m_stBitmapRect.top, m_stBitmapRect.right, m_stBitmapRect.bottom, SRCCOPY);
	SelectObject(GET_DC(m_oFilePath), hPrevBitmap);
}
