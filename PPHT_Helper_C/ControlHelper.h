#pragma once
#include "ConvertHelper.h"


// ControlHelper

class ControlHelper : public CWnd
{
	DECLARE_DYNCREATE(ControlHelper)

public:
	ControlHelper();
	virtual ~ControlHelper();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(ControlHelper)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	enum 
	{
		dispidKeyPress = 16L,
		dispidKeyUp = 15L,
		dispidKeyDown = 14L,
		dispidSendUTF8String = 13L,
		dispidSendANSIString = 12L,
		dispidSendUnicodeString = 11L,
		dispidRMouseClick = 10L,
		dispidRMouseUp = 9L,
		dispidRMouseDown = 8L,
		dispidMMouseClick = 7L,
		dispidMMouseUp = 6L,
		dispidMMouseDown = 5L,
		dispidLMouseClick = 4L,
		dispidLMouseUp = 3L,
		dispidLMouseDown = 2L,
		dispidMouseMove = 1L
	};
private:
	ConvertHelper convertHelper;

public:
	void MouseMove(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute);
	void LMouseDown(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute);
	void LMouseUp(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute);
	void LMouseClick(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute);
	void MMouseDown(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute);
	void MMouseUp(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute);
	void MMouseClick(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute);
	void RMouseDown(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute);
	void RMouseUp(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute);
	void RMouseClick(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute);
	void SendUnicodeString(ULONG hwnd, LPCTSTR msgStr);
	void SendANSIString(ULONG hwnd, LPCTSTR msgStr);
	void SendUTF8String(ULONG hwnd, LPCTSTR msgStr);
	void KeyDown(ULONG hwnd, ULONG key);
	void KeyUp(ULONG hwnd, ULONG key);
	void KeyPress(ULONG hwnd, ULONG key);
};


