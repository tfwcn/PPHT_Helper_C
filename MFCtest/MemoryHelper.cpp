// MemoryHelper.cpp : 实现文件
//

#include "stdafx.h"
//#include "PPHT_Helper_C.h"
#include "MemoryHelper.h"
#include <TlHelp32.h>


// MemoryHelper

IMPLEMENT_DYNCREATE(MemoryHelper, CWnd)

MemoryHelper::MemoryHelper()
{

	EnableAutomation();
	
	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	
	AfxOleLockApp();
}

MemoryHelper::~MemoryHelper()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	
	AfxOleUnlockApp();
}

void MemoryHelper::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(MemoryHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(MemoryHelper, CWnd)
	DISP_FUNCTION_ID(MemoryHelper, "GetPidByHwnd", dispidGetPidByHwnd, GetPidByHwnd, VT_UI4, VTS_UI4)
	DISP_FUNCTION_ID(MemoryHelper, "GetPidByProcessName", dispidGetPidByProcessName, GetPidByProcessName, VT_UI4, VTS_BSTR)
	DISP_FUNCTION_ID(MemoryHelper, "ReadInt", dispidReadInt, ReadInt, VT_I4, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(MemoryHelper, "ReadDouble", dispidReadDouble, ReadDouble, VT_R8, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(MemoryHelper, "ReadUnicodeString", dispidReadUnicodeString, ReadUnicodeString, VT_BSTR, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(MemoryHelper, "ReadANSIString", dispidReadANSIString, ReadANSIString, VT_BSTR, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(MemoryHelper, "ReadUTF8String", dispidReadUTF8String, ReadUTF8String, VT_BSTR, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(MemoryHelper, "GetAddressOfString", dispidGetAddressOfString, GetAddressOfString, VT_UI4, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(MemoryHelper, "WriteInt", dispidWriteInt, WriteInt, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_I4)
	DISP_FUNCTION_ID(MemoryHelper, "WriteDouble", dispidWriteDouble, WriteDouble, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_R8)
	DISP_FUNCTION_ID(MemoryHelper, "WriteFloat", dispidWriteFloat, WriteFloat, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_R4)
	DISP_FUNCTION_ID(MemoryHelper, "WriteShort", dispidWriteShort, WriteShort, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_I2)
	DISP_FUNCTION_ID(MemoryHelper, "WriteByte", dispidWriteByte, WriteByte, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_UI1)
	DISP_FUNCTION_ID(MemoryHelper, "WriteUnicodeString", dispidWriteUnicodeString, WriteUnicodeString, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(MemoryHelper, "WriteANSIString", dispidWriteANSIString, WriteANSIString, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(MemoryHelper, "WriteUTF8String", dispidWriteUTF8String, WriteUTF8String, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(MemoryHelper, "GetHwndByPid", dispidGetHwndByPid, GetHwndByPid, VT_UI4, VTS_UI4)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IMemoryHelper 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {DBA955B9-0175-4087-A36B-D47D43FD7DA9}
static const IID IID_IMemoryHelper =
{ 0xDBA955B9, 0x175, 0x4087, { 0xA3, 0x6B, 0xD4, 0x7D, 0x43, 0xFD, 0x7D, 0xA9 } };

BEGIN_INTERFACE_MAP(MemoryHelper, CWnd)
	INTERFACE_PART(MemoryHelper, IID_IMemoryHelper, Dispatch)
END_INTERFACE_MAP()

// {45CB3674-3B8B-4F59-8EF1-DA1566AB5B3B}
IMPLEMENT_OLECREATE(MemoryHelper, "PPHT_Helper_C.MemoryHelper", 0x45cb3674, 0x3b8b, 0x4f59, 0x8e, 0xf1, 0xda, 0x15, 0x66, 0xab, 0x5b, 0x3b)


// MemoryHelper 消息处理程序




ULONG MemoryHelper::GetPidByHwnd(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	ULONG pid=0;
	::GetWindowThreadProcessId((HWND)hwnd,&pid);

	return pid;
}


ULONG MemoryHelper::GetPidByProcessName(LPCTSTR processName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	ULONG pid=0;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	if (hProcessSnap != INVALID_HANDLE_VALUE)
	{
		BOOL bMore = ::Process32First(hProcessSnap,&pe32);
		while(bMore)
		{
			if (wcscmp(pe32.szExeFile,processName)==0)
			{
				pid=pe32.th32ProcessID;
			}
			bMore = ::Process32Next(hProcessSnap,&pe32);
		}
		::CloseHandle(hProcessSnap);
	}

	return pid;
}


LONG MemoryHelper::ReadInt(ULONG pid, ULONG address, ULONG len)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes=new BYTE[len];
	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,bytes,len,NULL);
	LONG ret= convertHelper.BytesToInt(bytes);
	::CloseHandle(hProcess);

	return ret;
}


DOUBLE MemoryHelper::ReadDouble(ULONG pid, ULONG address, ULONG len)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes=new BYTE[len];
	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,bytes,len,NULL);
	LONG ret= convertHelper.BytesToDouble(bytes);
	::CloseHandle(hProcess);

	return ret;
}


BSTR MemoryHelper::ReadUnicodeString(ULONG pid, ULONG address, ULONG maxLen)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	BYTE *bytes=new BYTE[maxLen];
	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,bytes,maxLen,NULL);
	strResult= convertHelper.BytesToUnicodeString(bytes);
	::CloseHandle(hProcess);

	return strResult.AllocSysString();
}


BSTR MemoryHelper::ReadANSIString(ULONG pid, ULONG address, ULONG maxLen)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	BYTE *bytes=new BYTE[maxLen];
	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,bytes,maxLen,NULL);
	strResult= convertHelper.BytesToANSIString(bytes);
	::CloseHandle(hProcess);

	return strResult.AllocSysString();
}


BSTR MemoryHelper::ReadUTF8String(ULONG pid, ULONG address, ULONG maxLen)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	BYTE *bytes=new BYTE[maxLen];
	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,bytes,maxLen,NULL);
	strResult= convertHelper.BytesToUTF8String(bytes);
	::CloseHandle(hProcess);

	return strResult.AllocSysString();
}


ULONG MemoryHelper::GetAddressOfString(ULONG pid, LPCTSTR address)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	ULONG ret = 0;
	CString addressValue = address;
	addressValue.Replace(L" ", L"");
	ret = convertHelper.HexToInt(L"0x"+addressValue.Mid(addressValue.Find(L"[") + 1, addressValue.Find(L"]") - addressValue.Find(L"[") - 1));
	addressValue = addressValue.Mid(addressValue.Find(L"]") + 1);
	if (addressValue.GetLength() > 0)
	{
		addressValue = addressValue.Mid(1);
	}
	while (addressValue.GetLength() > 0)
	{
		ret = ReadInt(pid, ret,4);
		if (addressValue.Find(L"+") > 0)
		{
			ret +=convertHelper.HexToInt(L"0x"+addressValue.Mid(0, addressValue.Find(L"+")));
			addressValue = addressValue.Mid(addressValue.Find(L"+") + 1);
		}
		else if (addressValue.Find(L"+") == -1)
		{
			ret += convertHelper.HexToInt(L"0x"+addressValue);
			addressValue = "";
		}
	}

	return ret;
}


void MemoryHelper::WriteInt(ULONG pid, ULONG address, LONG val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,&val,sizeof(val),NULL);
	::CloseHandle(hProcess);
}


void MemoryHelper::WriteDouble(ULONG pid, ULONG address, DOUBLE val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,&val,sizeof(val),NULL);
	::CloseHandle(hProcess);
}


void MemoryHelper::WriteFloat(ULONG pid, ULONG address, FLOAT val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,&val,sizeof(val),NULL);
	::CloseHandle(hProcess);
}


void MemoryHelper::WriteShort(ULONG pid, ULONG address, SHORT val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,&val,sizeof(val),NULL);
	::CloseHandle(hProcess);
}


void MemoryHelper::WriteByte(ULONG pid, ULONG address, BYTE val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,&val,sizeof(val),NULL);
	::CloseHandle(hProcess);
}


void MemoryHelper::WriteUnicodeString(ULONG pid, ULONG address, LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes;
	ULONG len=convertHelper.StringToUnicodeBytes(val,&bytes);
	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,bytes,len,NULL);
	::CloseHandle(hProcess);
}


void MemoryHelper::WriteANSIString(ULONG pid, ULONG address, LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes;
	ULONG len=convertHelper.StringToUnicodeBytes(val,&bytes);
	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,bytes,len,NULL);
	::CloseHandle(hProcess);
}


void MemoryHelper::WriteUTF8String(ULONG pid, ULONG address, LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes;
	ULONG len=convertHelper.StringToUnicodeBytes(val,&bytes);
	HANDLE hProcess=::OpenProcess(PROCESS_ALL_ACCESS,false,pid);
	::ReadProcessMemory(hProcess,&address,bytes,len,NULL);
	::CloseHandle(hProcess);
}


ULONG MemoryHelper::GetHwndByPid(ULONG pid)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CWnd *tmpHwnd=CWnd::FindWindowW(NULL,NULL);
	while(tmpHwnd){
		ULONG tmpPid= GetPidByHwnd((ULONG)tmpHwnd->m_hWnd);
		CString titstr;
		tmpHwnd->GetWindowTextW(titstr);
		if (pid!=0 && tmpPid!=0 && pid==tmpPid &&(GetWindowLong(tmpHwnd->m_hWnd,GWL_STYLE) & WS_VISIBLE) && titstr.GetLength()>0)
		{
			return (ULONG)tmpHwnd->m_hWnd;
		}
		tmpHwnd=tmpHwnd->GetNextWindow();
	}

	return 0;
}
