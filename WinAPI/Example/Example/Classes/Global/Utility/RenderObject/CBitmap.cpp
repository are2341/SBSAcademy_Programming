#include "CBitmap.h"
#include "../../Function/GFunc.h"
#include "../Manager/CResManager.h"

CBitmap::CBitmap(const std::string & a_rFilePath, const D3DXVECTOR2 &a_rstPos)
: CObj(a_rstPos),
m_oFilePath(a_rFilePath)
{
	m_hBitmap = GET_BITMAP(a_rFilePath);
	ZeroMemory(&m_stBitmapRect, sizeof(m_stBitmapRect));

	BITMAP stBitmap;
	GetObject(m_hBitmap, sizeof(stBitmap), &stBitmap);

	m_stSize = D3DXVECTOR2(stBitmap.bmWidth, stBitmap.bmHeight);

	m_stBitmapRect.right = stBitmap.bmWidth;
	m_stBitmapRect.bottom = stBitmap.bmHeight;
}

RECT CBitmap::getBitmapRect(void) const {
	return m_stBitmapRect;
}

void CBitmap::setBitmapRect(const RECT & a_rstBitmapRect) {
	m_stBitmapRect = a_rstBitmapRect;
}

void CBitmap::doRender(HDC a_hDC) {
	auto stRect = GFunc::makeRect(m_stWorldPos, m_stSize);
	auto hPrevBitmap = SelectObject(GET_DC(m_oFilePath), m_hBitmap);

	StretchBlt(a_hDC, stRect.left, stRect.top, stRect.right, stRect.bottom, GET_DC(m_oFilePath), m_stBitmapRect.left, m_stBitmapRect.top, m_stBitmapRect.right, m_stBitmapRect.bottom, SRCCOPY);
	SelectObject(GET_DC(m_oFilePath), hPrevBitmap);
}
