// ConvertHelper.cpp : 实现文件
//

#include "stdafx.h"
#include "PPHT_Helper_C.h"
#include "ConvertHelper.h"


// ConvertHelper

IMPLEMENT_DYNCREATE(ConvertHelper, CWnd)

ConvertHelper::ConvertHelper()
{

	EnableAutomation();
	
	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	
	AfxOleLockApp();
}

ConvertHelper::~ConvertHelper()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	
	AfxOleUnlockApp();
}

void ConvertHelper::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(ConvertHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(ConvertHelper, CWnd)
	DISP_FUNCTION_ID(ConvertHelper, "IntToHex", dispidIntToHex, IntToHex, VT_BSTR, VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ConvertHelper, "HexToInt", dispidHexToInt, HexToInt, VT_UI4, VTS_BSTR)
	DISP_FUNCTION_ID(ConvertHelper, "StringToUnicodeBytes", dispidStringToUnicodeBytes, StringToUnicodeBytes, VT_UI4, VTS_BSTR VTS_PUI1)
	DISP_FUNCTION_ID(ConvertHelper, "StringToANSIBytes", dispidStringToANSIBytes, StringToANSIBytes, VT_UI4, VTS_BSTR VTS_PUI1)
	DISP_FUNCTION_ID(ConvertHelper, "StringToUTF8Bytes", dispidStringToUTF8Bytes, StringToUTF8Bytes, VT_UI4, VTS_BSTR VTS_PUI1)
	DISP_FUNCTION_ID(ConvertHelper, "BytesToUnicodeString", dispidBytesToUnicodeString, BytesToUnicodeString, VT_BSTR, VTS_PUI1)
	DISP_FUNCTION_ID(ConvertHelper, "BytesToANSIString", dispidBytesToANSIString, BytesToANSIString, VT_BSTR, VTS_PUI1)
	DISP_FUNCTION_ID(ConvertHelper, "BytesToUTF8String", dispidBytesToUTF8String, BytesToUTF8String, VT_BSTR, VTS_PUI1)
	DISP_FUNCTION_ID(ConvertHelper, "BytesToInt", dispidBytesToInt, BytesToInt, VT_I4, VTS_PUI1)
	DISP_FUNCTION_ID(ConvertHelper, "BytesToDouble", dispidBytesToDouble, BytesToDouble, VT_R8, VTS_PUI1)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IConvertHelper 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {BC39A831-E868-48B6-ACD3-4CB0341B531F}
static const IID IID_IConvertHelper =
{ 0xBC39A831, 0xE868, 0x48B6, { 0xAC, 0xD3, 0x4C, 0xB0, 0x34, 0x1B, 0x53, 0x1F } };

BEGIN_INTERFACE_MAP(ConvertHelper, CWnd)
	INTERFACE_PART(ConvertHelper, IID_IConvertHelper, Dispatch)
END_INTERFACE_MAP()

// {8B462A43-4FC8-493C-9E11-41CE8B2A81AB}
IMPLEMENT_OLECREATE(ConvertHelper, "PPHT_Helper_C.ConvertHelper", 0x8b462a43, 0x4fc8, 0x493c, 0x9e, 0x11, 0x41, 0xce, 0x8b, 0x2a, 0x81, 0xab)


// ConvertHelper 消息处理程序




BSTR ConvertHelper::IntToHex(ULONG val,ULONG len)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	if (len>0)
	{
		strResult.Format(L"%X",val);
	}
	for (ULONG i=strResult.GetLength();i<len;i++)
	{
	strResult=L"0" + strResult;
	}
	
	return strResult.AllocSysString();
}


ULONG ConvertHelper::HexToInt(LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ULONG r=0;
	r=wcstoul(val,NULL,16);
	return r;
}


ULONG ConvertHelper::StringToUnicodeBytes(LPCTSTR val,BYTE** bytes)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*bytes=new BYTE[wcslen(val)*2+2];
	wcscpy((wchar_t*)(*bytes),val);
	(*bytes)[wcslen(val)*2]='\0';
	(*bytes)[wcslen(val)*2+1]='\0';
	
	return wcslen(val)*2;
}


ULONG ConvertHelper::StringToANSIBytes(LPCTSTR val,BYTE** bytes)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int len = ::WideCharToMultiByte(CP_ACP, NULL, val, wcslen(val), NULL, 0, NULL, NULL);
	*bytes=new BYTE[len+1];
	::WideCharToMultiByte(CP_ACP, NULL, val, wcslen(val), (LPSTR)*bytes, len, NULL, NULL);
	(*bytes)[len]='\0';

	return len;
}


ULONG ConvertHelper::StringToUTF8Bytes(LPCTSTR val,BYTE** bytes)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int len = ::WideCharToMultiByte(CP_UTF8, NULL, val, wcslen(val), NULL, 0, NULL, NULL);
	*bytes=new BYTE[len+1];
	::WideCharToMultiByte(CP_UTF8, NULL, val, wcslen(val), (LPSTR)*bytes, len, NULL, NULL);
	(*bytes)[len]='\0';

	return len;
}


BSTR ConvertHelper::BytesToUnicodeString(BYTE* val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult=(wchar_t*)val;
	return strResult.AllocSysString();
}


BSTR ConvertHelper::BytesToANSIString(BYTE* val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	int len = ::MultiByteToWideChar(CP_ACP, NULL, (LPCSTR)val, strlen((LPCSTR)val), NULL, 0);
	wchar_t* wszString = new wchar_t[len + 1];
	::MultiByteToWideChar(CP_ACP, NULL, (LPCSTR)val, strlen((LPCSTR)val), wszString, len);
	wszString[len]='\0';
	strResult=wszString;

	return strResult.AllocSysString();
}


BSTR ConvertHelper::BytesToUTF8String(BYTE* val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	int len = ::MultiByteToWideChar(CP_UTF8, NULL, (LPCSTR)val, strlen((LPCSTR)val), NULL, 0);
	wchar_t* wszString = new wchar_t[len + 1];
	::MultiByteToWideChar(CP_UTF8, NULL, (LPCSTR)val, strlen((LPCSTR)val), wszString, len);
	wszString[len]='\0';
	strResult=wszString;

	return strResult.AllocSysString();
}


LONG ConvertHelper::BytesToInt(BYTE* val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	LONG ret=0;
	int len=strlen((LPCSTR)val);
	if (len<=8)
	{
		for(int i=0;i<len;i++)
		{
			ret+=val[i]*i*0x100;
		}
	}

	return ret;
}


DOUBLE ConvertHelper::BytesToDouble(BYTE* val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	DOUBLE *ret=0;
	LONG tmp=0;
	int len=strlen((LPCSTR)val);
	if (len<=8)
	{
		for(int i=0;i<len;i++)
		{
			tmp+=val[i]*i*0x100;
		}
	}
	ret=(DOUBLE*)&tmp;
	
	return *ret;
}
