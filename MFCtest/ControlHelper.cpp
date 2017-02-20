// ControlHelper.cpp : 实现文件
//

#include "stdafx.h"
//#include "PPHT_Helper_C.h"
#include "ControlHelper.h"


// ControlHelper

IMPLEMENT_DYNCREATE(ControlHelper, CWnd)

ControlHelper::ControlHelper()
{

	EnableAutomation();
	
	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	
	AfxOleLockApp();
}

ControlHelper::~ControlHelper()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	
	AfxOleUnlockApp();
}

void ControlHelper::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(ControlHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(ControlHelper, CWnd)
	DISP_FUNCTION_ID(ControlHelper, "MouseMove", dispidMouseMove, MouseMove, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "LMouseDown", dispidLMouseDown, LMouseDown, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "LMouseUp", dispidLMouseUp, LMouseUp, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "LMouseClick", dispidLMouseClick, LMouseClick, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "MMouseDown", dispidMMouseDown, MMouseDown, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "MMouseUp", dispidMMouseUp, MMouseUp, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "MMouseClick", dispidMMouseClick, MMouseClick, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "RMouseDown", dispidRMouseDown, RMouseDown, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "RMouseUp", dispidRMouseUp, RMouseUp, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "RMouseClick", dispidRMouseClick, RMouseClick, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "SendUnicodeString", dispidSendUnicodeString, SendUnicodeString, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(ControlHelper, "SendANSIString", dispidSendANSIString, SendANSIString, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(ControlHelper, "SendUTF8String", dispidSendUTF8String, SendUTF8String, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(ControlHelper, "KeyDown", dispidKeyDown, KeyDown, VT_EMPTY, VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ControlHelper, "KeyUp", dispidKeyUp, KeyUp, VT_EMPTY, VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ControlHelper, "KeyPress", dispidKeyPress, KeyPress, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_UI4)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IontrolHelper 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {9C3DC0C5-927B-400E-81EC-2A7BFAB02B62}
static const IID IID_IontrolHelper =
{ 0x9C3DC0C5, 0x927B, 0x400E, { 0x81, 0xEC, 0x2A, 0x7B, 0xFA, 0xB0, 0x2B, 0x62 } };

BEGIN_INTERFACE_MAP(ControlHelper, CWnd)
	INTERFACE_PART(ControlHelper, IID_IontrolHelper, Dispatch)
END_INTERFACE_MAP()

// {D815E262-ABFA-4437-BFBB-EFB316F4A31E}
IMPLEMENT_OLECREATE(ControlHelper, "PPHT_Helper_C.ControlHelper", 0xd815e262, 0xabfa, 0x4437, 0xbf, 0xbb, 0xef, 0xb3, 0x16, 0xf4, 0xa3, 0x1e)


// ControlHelper 消息处理程序




void ControlHelper::MouseMove(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
}


void ControlHelper::LMouseDown(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_LBUTTONDOWN,0x1,x+y*0x10000);
}


void ControlHelper::LMouseUp(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_LBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::LMouseClick(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_LBUTTONDOWN,0x1,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_LBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::MMouseDown(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_MBUTTONDOWN,0x10,x+y*0x10000);
}


void ControlHelper::MMouseUp(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_MBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::MMouseClick(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_MBUTTONDOWN,0x10,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_MBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::RMouseDown(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_RBUTTONDOWN,0x2,x+y*0x10000);
}


void ControlHelper::RMouseUp(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_RBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::RMouseClick(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_RBUTTONDOWN,0x2,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_RBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::SendUnicodeString(ULONG hwnd, LPCTSTR msgStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	BYTE *bytes;
	int len = convertHelper.StringToUnicodeBytes(msgStr,&bytes);
	for (int i=0;i<len;i++)
	{
		::PostMessageA((HWND)hwnd,WM_CHAR, bytes[i], 0);
	}
}


void ControlHelper::SendANSIString(ULONG hwnd, LPCTSTR msgStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes;
	int len = convertHelper.StringToANSIBytes(msgStr,&bytes);
	for (int i=0;i<len;i++)
	{
		::PostMessageA((HWND)hwnd,WM_CHAR, bytes[i], 0);
	}
}


void ControlHelper::SendUTF8String(ULONG hwnd, LPCTSTR msgStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes;
	int len = convertHelper.StringToUTF8Bytes(msgStr,&bytes);
	for (int i=0;i<len;i++)
	{
		::PostMessageA((HWND)hwnd,WM_CHAR, bytes[i], 0);
	}
}


void ControlHelper::KeyDown(ULONG hwnd, ULONG key)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd, WM_KEYDOWN, key, 1);
}


void ControlHelper::KeyUp(ULONG hwnd, ULONG key)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd, WM_KEYUP, key, 1);
}


void ControlHelper::KeyPress(ULONG hwnd, ULONG key, ULONG count)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd, WM_KEYDOWN|WM_KEYUP, key, count);
}
