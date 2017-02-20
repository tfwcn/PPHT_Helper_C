#pragma once
#include "converthelper.h"


// ColorHelper

class ColorHelper : public CWnd
{
	DECLARE_DYNCREATE(ColorHelper)

public:
	ColorHelper();
	virtual ~ColorHelper();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(ColorHelper)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	enum 
	{
		dispidCheckIn = 7L,
		dispidGetColorPositions = 6L,
		dispidGetColorStr = 5L,
		dispidFindPic = 4L,
		dispidCheckColorOfPosition = 3L,
		dispidCheckColor = 2L,
		dispidGetPixelColor = 1L
	};
private:
	ConvertHelper convertHelper;

public:
	ULONG GetPixelColor(ULONG hwnd, LONG x, LONG y);
	LONG CheckColor(ULONG color1, ULONG color2, ULONG offset);
	LONG CheckColorOfPosition(ULONG hwnd, LONG x, LONG y, ULONG color, ULONG offset);
	BSTR FindPic(ULONG hwnd, LPCTSTR path, LONG x, LONG y, ULONG width, ULONG height, ULONG offset);
	BSTR GetColorStr(ULONG color);
	BSTR GetColorPositions(ULONG hwnd, LONG x, LONG y, ULONG width, ULONG height, LPCTSTR direction, ULONG beginSize, ULONG endSize, ULONG color, ULONG offset, ULONG iscut);
	DOUBLE CheckIn(LPCTSTR points1, LPCTSTR points2);
};


