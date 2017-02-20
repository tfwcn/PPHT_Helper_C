#pragma once
#include "ConvertHelper.h"


// MemoryHelper

class MemoryHelper : public CWnd
{
	DECLARE_DYNCREATE(MemoryHelper)

public:
	MemoryHelper();
	virtual ~MemoryHelper();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(MemoryHelper)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	enum 
	{
		dispidFindSubWindow = 19L,
		dispidGetHwndsByWindowName = 18L,
		dispidGetHwndByPid = 17L,
		dispidWriteUTF8String = 16L,
		dispidWriteANSIString = 15L,
		dispidWriteUnicodeString = 14L,
		dispidWriteByte = 13L,
		dispidWriteShort = 12L,
		dispidWriteFloat = 11L,
		dispidWriteDouble = 10L,
		dispidWriteInt = 9L,
		dispidGetAddressOfString = 8L,
		dispidReadUTF8String = 7L,
		dispidReadANSIString = 6L,
		dispidReadUnicodeString = 5L,
		dispidReadDouble = 4L,
		dispidReadInt = 3L,
		dispidGetPidByProcessName = 2L,
		dispidGetPidByHwnd = 1L
	};
private:
	ConvertHelper convertHelper;

public:
	ULONG GetPidByHwnd(ULONG hwnd);
	ULONG GetPidByProcessName(LPCTSTR processName);
	LONG ReadInt(ULONG pid, ULONG address, ULONG len);
	DOUBLE ReadDouble(ULONG pid, ULONG address, ULONG len);
	BSTR ReadUnicodeString(ULONG pid, ULONG address, ULONG maxLen);
	BSTR ReadANSIString(ULONG pid, ULONG address, ULONG maxLen);
	BSTR ReadUTF8String(ULONG pid, ULONG address, ULONG maxLen);
	ULONG GetAddressOfString(ULONG pid, LPCTSTR address);
	void WriteInt(ULONG pid, ULONG address, LONG val);
	void WriteDouble(ULONG pid, ULONG address, DOUBLE val);
	void WriteFloat(ULONG pid, ULONG address, FLOAT val);
	void WriteShort(ULONG pid, ULONG address, SHORT val);
	void WriteByte(ULONG pid, ULONG address, BYTE val);
	void WriteUnicodeString(ULONG pid, ULONG address, LPCTSTR val);
	void WriteANSIString(ULONG pid, ULONG address, LPCTSTR val);
	void WriteUTF8String(ULONG pid, ULONG address, LPCTSTR val);
	ULONG GetHwndByPid(ULONG pid);
protected:
	BSTR GetHwndsByWindowName(LPCTSTR windowName, ULONG cmpType);
	ULONG FindSubWindow(ULONG hwnd1, ULONG hwnd2, LPCTSTR className1, LPCTSTR className2);
};


