// StringHelper.cpp : 实现文件
//

#include "stdafx.h"
//#include "PPHT_Helper_C.h"
#include "StringHelper.h"
#include "boost\regex.hpp"

using namespace boost;

// StringHelper

IMPLEMENT_DYNCREATE(StringHelper, CWnd)

StringHelper::StringHelper()
{

	EnableAutomation();
	
	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	
	AfxOleLockApp();
}

StringHelper::~StringHelper()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	
	AfxOleUnlockApp();
}

void StringHelper::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(StringHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(StringHelper, CWnd)
	DISP_FUNCTION_ID(StringHelper, "Length", dispidLength, Length, VT_UI4, VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "SubString", dispidSubString, SubString, VT_BSTR, VTS_BSTR VTS_UI4 VTS_I4)
	DISP_FUNCTION_ID(StringHelper, "Left", dispidLeft, Left, VT_BSTR, VTS_BSTR VTS_UI4)
	DISP_FUNCTION_ID(StringHelper, "Right", dispidRight, Right, VT_BSTR, VTS_BSTR VTS_UI4)
	DISP_FUNCTION_ID(StringHelper, "Trim", dispidTrim, Trim, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "LTrim", dispidLTrim, LTrim, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "RTrim", dispidRTrim, RTrim, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "Replace", dispidReplace, Replace, VT_BSTR, VTS_BSTR VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "IndexOf", dispidIndexOf, IndexOf, VT_I4, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "LastIndexOf", dispidLastIndexOf, LastIndexOf, VT_I4, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "ToLower", dispidToLower, ToLower, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "ToUpper", dispidToUpper, ToUpper, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "RegexMatch", dispidRegexMatch, RegexMatch, VT_I4, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "RegexReplace", dispidRegexReplace, RegexReplace, VT_BSTR, VTS_BSTR VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "RegexIndexOf", dispidRegexIndexOf, RegexIndexOf, VT_I4, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "RegexLastIndexOf", dispidRegexLastIndexOf, RegexLastIndexOf, VT_I4, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(StringHelper, "RegexFindSubString", dispidRegexFindSubString, RegexFindSubString, VT_BSTR, VTS_BSTR VTS_BSTR)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IStringHelper 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {59408ABD-8597-4678-80EE-B359EE192984}
static const IID IID_IStringHelper =
{ 0x59408ABD, 0x8597, 0x4678, { 0x80, 0xEE, 0xB3, 0x59, 0xEE, 0x19, 0x29, 0x84 } };

BEGIN_INTERFACE_MAP(StringHelper, CWnd)
	INTERFACE_PART(StringHelper, IID_IStringHelper, Dispatch)
END_INTERFACE_MAP()

// {A1F09381-8B0A-4587-B8FF-2B490EA8E437}
IMPLEMENT_OLECREATE(StringHelper, "PPHT_Helper_C.StringHelper", 0xa1f09381, 0x8b0a, 0x4587, 0xb8, 0xff, 0x2b, 0x49, 0xe, 0xa8, 0xe4, 0x37)


// StringHelper 消息处理程序




ULONG StringHelper::Length(LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString tmpstr=val;

	return tmpstr.GetLength();
}


BSTR StringHelper::SubString(LPCTSTR val, ULONG start, LONG len)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	strResult=val;
	if (len>=0)
	{
		strResult=strResult.Mid(start,len);
	} 
	else
	{
		strResult=strResult.Mid(start);
	}

	return strResult.AllocSysString();
}


BSTR StringHelper::Left(LPCTSTR val, ULONG len)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	strResult=val;
	strResult=strResult.Left(len);

	return strResult.AllocSysString();
}


BSTR StringHelper::Right(LPCTSTR val, ULONG len)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	strResult=val;
	strResult=strResult.Right(len);

	return strResult.AllocSysString();
}


BSTR StringHelper::Trim(LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	strResult=val;
	strResult=strResult.Trim();

	return strResult.AllocSysString();
}


BSTR StringHelper::LTrim(LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	strResult=val;
	strResult=strResult.TrimLeft();

	return strResult.AllocSysString();
}


BSTR StringHelper::RTrim(LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	strResult=val;
	strResult=strResult.TrimRight();

	return strResult.AllocSysString();
}


BSTR StringHelper::Replace(LPCTSTR val, LPCTSTR oldVal, LPCTSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	strResult=val;
	strResult.Replace(oldVal,newVal);

	return strResult.AllocSysString();
}


LONG StringHelper::IndexOf(LPCTSTR val, LPCTSTR selectVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	strResult=val;

	return strResult.Find(selectVal);;
}


LONG StringHelper::LastIndexOf(LPCTSTR val, LPCTSTR selectVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult=val;
	CString selectStr=selectVal;

	for(ULONG i=strResult.GetLength()-selectStr.GetLength();i>=0;i--){
		for(ULONG j=0;j< selectStr.GetLength();j++){
			if(strResult[i+j]==selectStr[j] && j==selectStr.GetLength()-1){
				return i;
			}else if(strResult[i+j]!=selectStr[j]){
				break;
			}
		}
	}

	return -1;
}


BSTR StringHelper::ToLower(LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	strResult=val;
	strResult=strResult.MakeLower();

	return strResult.AllocSysString();
}


BSTR StringHelper::ToUpper(LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	strResult=val;
	strResult=strResult.MakeUpper();

	return strResult.AllocSysString();
}


LONG StringHelper::RegexMatch(LPCTSTR str, LPCTSTR regex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	try
	{
		wregex tmpregex(regex);
		bool ret= regex_match(str,tmpregex);
		if (ret)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}catch(...){}

	return -1;
}


BSTR StringHelper::RegexReplace(LPCTSTR str, LPCTSTR newVal, LPCTSTR regex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	CString strResult=L"";
	try
	{
		wregex tmpregex(regex);
		wcmatch tmpmatch;
		CString tmpstr=str;
		while(regex_search(tmpstr.AllocSysString(),tmpmatch,tmpregex))
		{
			CString lstr=tmpstr;
			tmpstr=tmpmatch[0].second;
			strResult+=lstr.Left(lstr.GetLength()-tmpmatch[0].length()-tmpstr.GetLength());
			strResult+=newVal;
		}
		strResult+=tmpstr;
	}catch(...){}

	return strResult.AllocSysString();
}


LONG StringHelper::RegexIndexOf(LPCTSTR str, LPCTSTR regex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	try
	{
		wregex tmpregex(regex);
		wcmatch tmpmatch;
		bool ret= regex_search(str,tmpmatch,tmpregex);
		if (ret)
		{
			return IndexOf(str,tmpmatch[0].str().c_str());
		}
		else
		{
			return -1;
		}
	}catch(...){}

	return -1;
}


LONG StringHelper::RegexLastIndexOf(LPCTSTR str, LPCTSTR regex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	try
	{
		wregex tmpregex(regex);
		wcmatch tmpmatch;
		CString tmpstr=str;
		CString lastStr=L"";
		while(regex_search(tmpstr.AllocSysString(),tmpmatch,tmpregex))
		{
			lastStr=tmpmatch[0].str().c_str();
			tmpstr=tmpmatch[0].second;
		}
		if (lastStr.GetLength()>0)
		{
			return LastIndexOf(str,lastStr);
		}

	}catch(...){}

	return -1;
}


BSTR StringHelper::RegexFindSubString(LPCTSTR str, LPCTSTR regex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult=L"";

	wregex tmpregex(regex);
	wcmatch tmpmatch;
	CString tmpstr=str;
	while(regex_search(tmpstr.AllocSysString(),tmpmatch,tmpregex))
	{
		strResult+=tmpmatch[0].str().c_str();
		strResult+=L"|";
		tmpstr=tmpmatch[0].second;
	}
	if (strResult.GetLength()>0)
	{
		strResult=strResult.Left(strResult.GetLength()-1);
	}

	return strResult.AllocSysString();
}
