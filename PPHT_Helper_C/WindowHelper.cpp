// WindowHelper.cpp : 实现文件
//

#include "stdafx.h"
#include "PPHT_Helper_C.h"
#include "WindowHelper.h"


// WindowHelper

IMPLEMENT_DYNCREATE(WindowHelper, CWnd)

WindowHelper::WindowHelper()
{

	EnableAutomation();
	
	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	
	AfxOleLockApp();
}

WindowHelper::~WindowHelper()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	
	AfxOleUnlockApp();
}

void WindowHelper::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(WindowHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(WindowHelper, CWnd)
	DISP_FUNCTION_ID(WindowHelper, "FlashWindow", dispidFlashWindow, FlashWindow, VT_I4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "GetWindowTitle", dispidGetWindowTitle, GetWindowTitle, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "GetForegroundWindow", dispidGetForegroundWindow, GetForegroundWindow, VT_UI4, VTS_NONE)
	DISP_FUNCTION_ID(WindowHelper, "IsMin", dispidIsMin, IsMin, VT_I4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "IsWindow", dispidIsWindow, IsWindow, VT_I4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "IsMax", dispidIsMax, IsMax, VT_I4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "SetForegroundWindow", dispidSetForegroundWindow, SetForegroundWindow, VT_I4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "MinWindow", dispidMinWindow, MinWindow, VT_EMPTY, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "RestoreWindow", dispidRestoreWindow, RestoreWindow, VT_EMPTY, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "MaxWindow", dispidMaxWindow, MaxWindow, VT_EMPTY, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "GetWindowSize", dispidGetWindowSize, GetWindowSize, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "GetClientSize", dispidGetClientSize, GetClientSize, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "MoveWindow", dispidMoveWindow, MoveWindow, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(WindowHelper, "SetWindowSize", dispidSetWindowSize, SetWindowSize, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "SetClientSize", dispidSetClientSize, SetClientSize, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "WindowFromPoint", dispidWindowFromPoint, WindowFromPoint, VT_UI4, VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(WindowHelper, "GetDC", dispidGetDC, GetDC, VT_UI4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "GetClientRect", dispidGetClientRect, GetClientRect, VT_EMPTY, VTS_UI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IWindowHelper 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {0F49A766-672F-4D97-BE2A-487D32C569EE}
static const IID IID_IWindowHelper =
{ 0xF49A766, 0x672F, 0x4D97, { 0xBE, 0x2A, 0x48, 0x7D, 0x32, 0xC5, 0x69, 0xEE } };

BEGIN_INTERFACE_MAP(WindowHelper, CWnd)
	INTERFACE_PART(WindowHelper, IID_IWindowHelper, Dispatch)
END_INTERFACE_MAP()

// {2539E6F3-C471-4340-8AE1-914269F7BE66}
IMPLEMENT_OLECREATE(WindowHelper, "PPHT_Helper_C.WindowHelper", 0x2539e6f3, 0xc471, 0x4340, 0x8a, 0xe1, 0x91, 0x42, 0x69, 0xf7, 0xbe, 0x66)


// WindowHelper 消息处理程序

//闪烁窗口
LONG WindowHelper::FlashWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return ::FlashWindow((HWND)hwnd,0);
}

//获得窗口标题
BSTR WindowHelper::GetWindowTitle(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	LPWSTR tmpstr;
	::GetWindowText((HWND)hwnd,tmpstr,255);
	strResult=tmpstr;
	return strResult.AllocSysString();
}

//获得当前窗口
ULONG WindowHelper::GetForegroundWindow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return (ULONG)::GetForegroundWindow();
}

//判断窗口是否已最小化
LONG WindowHelper::IsMin(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return ::IsIconic((HWND)hwnd);
}

//判断窗口句柄是否有效
LONG WindowHelper::IsWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return ::IsWindow((HWND)hwnd);
}

//判断窗口是否最大化
LONG WindowHelper::IsMax(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return ::IsZoomed((HWND)hwnd);
}

//将窗口设为系统的前台窗口
LONG WindowHelper::SetForegroundWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return (LONG)::SetForegroundWindow((HWND)hwnd);
}

//最小化窗口
void WindowHelper::MinWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::ShowWindow((HWND)hwnd,SW_MINIMIZE);
}

//还原窗口
void WindowHelper::RestoreWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::ShowWindow((HWND)hwnd,SW_RESTORE);
}

//最大化窗口
void WindowHelper::MaxWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::ShowWindow((HWND)hwnd,SW_MAXIMIZE);
}

//获得窗口位置和大小
BSTR WindowHelper::GetWindowSize(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	RECT *size=new RECT();
	::GetWindowRect((HWND)hwnd,size);
	strResult.Format(L"%d|%d|%d|%d",size->left,size->top,size->right-size->left,size->bottom-size->top);

	return strResult.AllocSysString();
}

//获得客户区位置和大小
BSTR WindowHelper::GetClientSize(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	POINT *p=new POINT();
	::ClientToScreen((HWND)hwnd,p);
	RECT *size=new RECT();
	::GetClientRect((HWND)hwnd,size);
	strResult.Format(L"%d|%d|%d|%d",p->x,p->y,size->right-size->left,size->bottom-size->top);

	return strResult.AllocSysString();
}

//移动窗口
void WindowHelper::MoveWindow(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT *size=new RECT();
	::GetWindowRect((HWND)hwnd,size);
	::MoveWindow((HWND)hwnd,x,y,size->right-size->left,size->bottom-size->top,true);
}

//设置窗口大小
void WindowHelper::SetWindowSize(ULONG hwnd, ULONG width, ULONG height)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT *size=new RECT();
	::GetWindowRect((HWND)hwnd,size);
	::MoveWindow((HWND)hwnd,size->left,size->top,width,height,true);
}

//设置客户区大小
void WindowHelper::SetClientSize(ULONG hwnd, ULONG width, ULONG height)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT *wsize=new RECT();
	RECT *csize=new RECT();
	ULONG w,h;
	::GetWindowRect((HWND)hwnd,wsize);
	::GetClientRect((HWND)hwnd,csize);
	w=width+((wsize->right-wsize->left)-(csize->right-csize->left));
	h=height+((wsize->bottom-wsize->top)-(csize->bottom-csize->top));
	::MoveWindow((HWND)hwnd,wsize->left,wsize->top,w,h,true);
}


ULONG WindowHelper::WindowFromPoint(LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	POINT *point =new POINT();
	point->x=x;
	point->y=y;
	return (ULONG)::WindowFromPoint(*point);
}


ULONG WindowHelper::GetDC(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return (ULONG)::GetDC((HWND)hwnd);
}


void WindowHelper::GetClientRect(ULONG hwnd, LONG* left, LONG* right, LONG* top, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT *rect=new RECT();
	::GetClientRect((HWND)hwnd,rect);
	*left=rect->left;
	*right=rect->right;
	*top=rect->top;
	*bottom=rect->bottom;
}
