#pragma once


// WindowHelper

class WindowHelper : public CWnd
{
	DECLARE_DYNCREATE(WindowHelper)

public:
	WindowHelper();
	virtual ~WindowHelper();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(WindowHelper)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	LONG FlashWindow(ULONG hwnd);

	enum 
	{
		dispidGetClientRect = 18L,
		dispidGetDC = 17L,
		dispidWindowFromPoint = 16L,
		dispidSetClientSize = 15L,
		dispidSetWindowSize = 14L,
		dispidMoveWindow = 13L,
		dispidGetClientSize = 12L,
		dispidGetWindowSize = 11L,
		dispidMaxWindow = 10L,
		dispidRestoreWindow = 9L,
		dispidMinWindow = 8L,
		dispidSetForegroundWindow = 7L,
		dispidIsMax = 6L,
		dispidIsWindow = 5L,
		dispidIsMin = 4L,
		dispidGetForegroundWindow = 3L,
		dispidGetWindowTitle = 2L,
		dispidFlashWindow = 1L
	};
	BSTR GetWindowTitle(ULONG hwnd);
	ULONG GetForegroundWindow(void);
	LONG IsMin(ULONG hwnd);
	LONG IsWindow(ULONG hwnd);
	LONG IsMax(ULONG hwnd);
	LONG SetForegroundWindow(ULONG hwnd);
	void MinWindow(ULONG hwnd);
	void RestoreWindow(ULONG hwnd);
	void MaxWindow(ULONG hwnd);
	BSTR GetWindowSize(ULONG hwnd);
	BSTR GetClientSize(ULONG hwnd);
	void MoveWindow(ULONG hwnd, LONG x, LONG y);
	void SetWindowSize(ULONG hwnd, ULONG width, ULONG height);
	void SetClientSize(ULONG hwnd, ULONG width, ULONG height);
	ULONG WindowFromPoint(LONG x, LONG y);
	ULONG GetDC(ULONG hwnd);
	void GetClientRect(ULONG hwnd, LONG* left, LONG* right, LONG* top, LONG* bottom);
};


