// ControlHelper.cpp : 实现文件
//

#include "stdafx.h"
#include "PPHT_Helper_C.h"
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
	DISP_FUNCTION_ID(ControlHelper, "MouseMove", dispidMouseMove, MouseMove, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_BOOL)
	DISP_FUNCTION_ID(ControlHelper, "LMouseDown", dispidLMouseDown, LMouseDown, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_BOOL)
	DISP_FUNCTION_ID(ControlHelper, "LMouseUp", dispidLMouseUp, LMouseUp, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_BOOL)
	DISP_FUNCTION_ID(ControlHelper, "LMouseClick", dispidLMouseClick, LMouseClick, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_BOOL)
	DISP_FUNCTION_ID(ControlHelper, "MMouseDown", dispidMMouseDown, MMouseDown, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_BOOL)
	DISP_FUNCTION_ID(ControlHelper, "MMouseUp", dispidMMouseUp, MMouseUp, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_BOOL)
	DISP_FUNCTION_ID(ControlHelper, "MMouseClick", dispidMMouseClick, MMouseClick, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_BOOL)
	DISP_FUNCTION_ID(ControlHelper, "RMouseDown", dispidRMouseDown, RMouseDown, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_BOOL)
	DISP_FUNCTION_ID(ControlHelper, "RMouseUp", dispidRMouseUp, RMouseUp, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_BOOL)
	DISP_FUNCTION_ID(ControlHelper, "RMouseClick", dispidRMouseClick, RMouseClick, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_BOOL)
	DISP_FUNCTION_ID(ControlHelper, "SendUnicodeString", dispidSendUnicodeString, SendUnicodeString, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(ControlHelper, "SendANSIString", dispidSendANSIString, SendANSIString, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(ControlHelper, "SendUTF8String", dispidSendUTF8String, SendUTF8String, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(ControlHelper, "KeyDown", dispidKeyDown, KeyDown, VT_EMPTY, VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ControlHelper, "KeyUp", dispidKeyUp, KeyUp, VT_EMPTY, VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ControlHelper, "KeyPress", dispidKeyPress, KeyPress, VT_EMPTY, VTS_UI4 VTS_UI4)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IControlHelper 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {9C3DC0C5-927B-400E-81EC-2A7BFAB02B62}
static const IID IID_IControlHelper =
{ 0x9C3DC0C5, 0x927B, 0x400E, { 0x81, 0xEC, 0x2A, 0x7B, 0xFA, 0xB0, 0x2B, 0x62 } };

BEGIN_INTERFACE_MAP(ControlHelper, CWnd)
	INTERFACE_PART(ControlHelper, IID_IControlHelper, Dispatch)
END_INTERFACE_MAP()

// {D815E262-ABFA-4437-BFBB-EFB316F4A31E}
IMPLEMENT_OLECREATE(ControlHelper, "PPHT_Helper_C.ControlHelper", 0xd815e262, 0xabfa, 0x4437, 0xbf, 0xbb, 0xef, 0xb3, 0x16, 0xf4, 0xa3, 0x1e)


// ControlHelper 消息处理程序




void ControlHelper::MouseMove(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
		LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
		LONG fx = x*(65535.0f/fScreenWidth);
		LONG fy = y*(65535.0f/fScreenHeight);
		/*INPUT *input=new INPUT[1];
		input[0].type=INPUT_MOUSE;
		input[0].mi.dx=fx;
		input[0].mi.dy=fy;
		input[0].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE;

		::SendInput(1,input,sizeof(INPUT));*/
		if (absolute)
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE, fx, fy, 0, 0);
		else
			::mouse_event(MOUSEEVENTF_MOVE, fx, fy, 0, 0);
	}
	else
	{
		::SendMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	}
}


void ControlHelper::LMouseDown(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
		LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
		LONG fx = x*(65535.0f/fScreenWidth);
		LONG fy = y*(65535.0f/fScreenHeight);
		/*INPUT *input=new INPUT[1];
		input[0].type=INPUT_MOUSE;
		input[0].mi.dx=fx;
		input[0].mi.dy=fy;
		input[0].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTDOWN;

		::SendInput(1,input,sizeof(INPUT));*/
		if (absolute)
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTDOWN, fx, fy, 0, 0);
		else
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTDOWN, fx, fy, 0, 0);
	}
	else
	{
		::SendMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_LBUTTONDOWN,0x1,x+y*0x10000);
	}
}


void ControlHelper::LMouseUp(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
		LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
		LONG fx = x*(65535.0f/fScreenWidth);
		LONG fy = y*(65535.0f/fScreenHeight);
		/*INPUT *input=new INPUT[1];
		input[0].type=INPUT_MOUSE;
		input[0].mi.dx=fx;
		input[0].mi.dy=fy;
		input[0].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTUP;

		::SendInput(1,input,sizeof(INPUT));*/
		if (absolute)
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTUP, fx, fy, 0, 0);
		else
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTUP, fx, fy, 0, 0);
	}
	else
	{
		::SendMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_LBUTTONUP,0,x+y*0x10000);
	}
}


void ControlHelper::LMouseClick(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
		LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
		LONG fx = x*(65535.0f/fScreenWidth);
		LONG fy = y*(65535.0f/fScreenHeight);
		/*INPUT *input=new INPUT[2];
		input[0].type=INPUT_MOUSE;
		input[0].mi.dx=fx;
		input[0].mi.dy=fy;
		input[0].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTDOWN;
		input[1].type=INPUT_MOUSE;
		input[1].mi.dx=fx;
		input[1].mi.dy=fy;
		input[1].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTUP;

		::SendInput(2,input,sizeof(INPUT));*/
		if (absolute)
		{
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTDOWN, fx, fy, 0, 0);
			::Sleep(60);
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTUP, fx, fy, 0, 0);
		}
		else
		{
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTDOWN, fx, fy, 0, 0);
			::Sleep(60);
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_LEFTUP, fx, fy, 0, 0);
		}
	}
	else
	{
		::SendMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_LBUTTONDOWN,0x1,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_LBUTTONUP,0,x+y*0x10000);
	}
}


void ControlHelper::MMouseDown(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
		LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
		LONG fx = x*(65535.0f/fScreenWidth);
		LONG fy = y*(65535.0f/fScreenHeight);
		/*INPUT *input=new INPUT[1];
		input[0].type=INPUT_MOUSE;
		input[0].mi.dx=fx;
		input[0].mi.dy=fy;
		input[0].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_MIDDLEDOWN;

		::SendInput(1,input,sizeof(INPUT));*/
		if (absolute)
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MIDDLEDOWN, fx, fy, 0, 0);
		else
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_MIDDLEDOWN, fx, fy, 0, 0);
	}
	else
	{
		::SendMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_MBUTTONDOWN,0x10,x+y*0x10000);
	}
}


void ControlHelper::MMouseUp(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
		LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
		LONG fx = x*(65535.0f/fScreenWidth);
		LONG fy = y*(65535.0f/fScreenHeight);
		/*INPUT *input=new INPUT[1];
		input[0].type=INPUT_MOUSE;
		input[0].mi.dx=fx;
		input[0].mi.dy=fy;
		input[0].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_MIDDLEUP;

		::SendInput(1,input,sizeof(INPUT));*/
		if (absolute)
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MIDDLEUP, fx, fy, 0, 0);
		else
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_MIDDLEUP, fx, fy, 0, 0);
	}
	else
	{
		::SendMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_MBUTTONUP,0,x+y*0x10000);
	}
}


void ControlHelper::MMouseClick(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
		LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
		LONG fx = x*(65535.0f/fScreenWidth);
		LONG fy = y*(65535.0f/fScreenHeight);
		/*INPUT *input=new INPUT[2];
		input[0].type=INPUT_MOUSE;
		input[0].mi.dx=fx;
		input[0].mi.dy=fy;
		input[0].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_MIDDLEDOWN;
		input[1].type=INPUT_MOUSE;
		input[1].mi.dx=fx;
		input[1].mi.dy=fy;
		input[1].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_MIDDLEUP;

		::SendInput(2,input,sizeof(INPUT));*/
		if (absolute)
		{
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MIDDLEDOWN, fx, fy, 0, 0);
			::Sleep(60);
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MIDDLEUP, fx, fy, 0, 0);
		}
		else
		{
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_MIDDLEDOWN, fx, fy, 0, 0);
			::Sleep(60);
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_MIDDLEUP, fx, fy, 0, 0);
		}
	}
	else
	{
		::SendMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_MBUTTONDOWN,0x10,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_MBUTTONUP,0,x+y*0x10000);
	}
}


void ControlHelper::RMouseDown(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
		LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
		LONG fx = x*(65535.0f/fScreenWidth);
		LONG fy = y*(65535.0f/fScreenHeight);
		/*INPUT *input=new INPUT[1];
		input[0].type=INPUT_MOUSE;
		input[0].mi.dx=fx;
		input[0].mi.dy=fy;
		input[0].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_RIGHTDOWN;

		::SendInput(1,input,sizeof(INPUT));*/
		if (absolute)
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_RIGHTDOWN, fx, fy, 0, 0);
		else
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_RIGHTDOWN, fx, fy, 0, 0);
	}
	else
	{
		::SendMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_RBUTTONDOWN,0x2,x+y*0x10000);
	}
}


void ControlHelper::RMouseUp(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
		LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
		LONG fx = x*(65535.0f/fScreenWidth);
		LONG fy = y*(65535.0f/fScreenHeight);
		/*INPUT *input=new INPUT[1];
		input[0].type=INPUT_MOUSE;
		input[0].mi.dx=fx;
		input[0].mi.dy=fy;
		input[0].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_RIGHTUP;

		::SendInput(1,input,sizeof(INPUT));*/
		if (absolute)
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_RIGHTUP, fx, fy, 0, 0);
		else
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_RIGHTUP, fx, fy, 0, 0);
	}
	else
	{
		::SendMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_RBUTTONUP,0,x+y*0x10000);
	}
}


void ControlHelper::RMouseClick(ULONG hwnd, LONG x, LONG y, VARIANT_BOOL absolute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
		LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
		LONG fx = x*(65535.0f/fScreenWidth);
		LONG fy = y*(65535.0f/fScreenHeight);
		/*INPUT *input=new INPUT[2];
		input[0].type=INPUT_MOUSE;
		input[0].mi.dx=fx;
		input[0].mi.dy=fy;
		input[0].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_RIGHTDOWN;
		input[1].type=INPUT_MOUSE;
		input[1].mi.dx=fx;
		input[1].mi.dy=fy;
		input[1].mi.dwFlags=MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE|MOUSEEVENTF_RIGHTUP;

		::SendInput(2,input,sizeof(INPUT));*/
		if (absolute)
		{
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_RIGHTDOWN, fx, fy, 0, 0);
			::Sleep(60);
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_RIGHTUP, fx, fy, 0, 0);
		}
		else
		{
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_RIGHTDOWN, fx, fy, 0, 0);
			::Sleep(60);
			::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_RIGHTUP, fx, fy, 0, 0);
		}
	}
	else
	{
		::SendMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_RBUTTONDOWN,0x2,x+y*0x10000);
		::SendMessageA((HWND)hwnd,WM_RBUTTONUP,0,x+y*0x10000);
	}
}


void ControlHelper::SendUnicodeString(ULONG hwnd, LPCTSTR msgStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	BYTE *bytes;
	int len = convertHelper.StringToUnicodeBytes(msgStr,&bytes);
	for (int i=0;i<len;i++)
	{
		::SendMessageA((HWND)hwnd,WM_CHAR, bytes[i], 0);
	}
}


void ControlHelper::SendANSIString(ULONG hwnd, LPCTSTR msgStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes;
	int len = convertHelper.StringToANSIBytes(msgStr,&bytes);
	for (int i=0;i<len;i++)
	{
		::SendMessageA((HWND)hwnd,WM_CHAR, bytes[i], 0);
	}
}


void ControlHelper::SendUTF8String(ULONG hwnd, LPCTSTR msgStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes;
	int len = convertHelper.StringToUTF8Bytes(msgStr,&bytes);
	for (int i=0;i<len;i++)
	{
		::SendMessageA((HWND)hwnd,WM_CHAR, bytes[i], 0);
	}
}


void ControlHelper::KeyDown(ULONG hwnd, ULONG key)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		/*INPUT *input=new INPUT[1];
		input[0].type=INPUT_KEYBOARD;
		input[0].ki.wVk = key;

		::SendInput(1,input,sizeof(INPUT));*/
		::keybd_event(key,::MapVirtualKey(key,0),0,0);
	}
	else
	{
		::SendMessageA((HWND)hwnd, WM_KEYDOWN, key, 1);
	}
}


void ControlHelper::KeyUp(ULONG hwnd, ULONG key)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		/*INPUT *input=new INPUT[1];
		input[0].type=INPUT_KEYBOARD;
		input[0].ki.wVk = key;
		input[0].ki.dwFlags = KEYEVENTF_KEYUP;

		::SendInput(1,input,sizeof(INPUT));*/
		::keybd_event(key,::MapVirtualKey(key,0),KEYEVENTF_KEYUP,0);
	}
	else
	{
		::SendMessageA((HWND)hwnd, WM_KEYUP, key, 1);
	}
}


void ControlHelper::KeyPress(ULONG hwnd, ULONG key)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (hwnd==0)
	{
		/*INPUT *input=new INPUT[2];
		input[0].type=INPUT_KEYBOARD;
		input[0].ki.wVk = key;
		input[1].type=INPUT_KEYBOARD;
		input[1].ki.wVk = key;
		input[1].ki.dwFlags = KEYEVENTF_KEYUP;

		::SendInput(2,input,sizeof(INPUT));*/
		::keybd_event(key,::MapVirtualKey(key,0),0,0);
		::Sleep(60);
		::keybd_event(key,::MapVirtualKey(key,0),KEYEVENTF_KEYUP,0);
	}
	else
	{
		::SendMessageA((HWND)hwnd, WM_KEYDOWN|WM_KEYUP, key,1);
	}
}
