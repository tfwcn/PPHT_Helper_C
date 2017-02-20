// XmlHelper.cpp : 实现文件
//

#include "stdafx.h"
//#include "PPHT_Helper_C.h"
#include "XmlHelper.h"


// XmlHelper

IMPLEMENT_DYNCREATE(XmlHelper, CWnd)

XmlHelper::XmlHelper()
{

	EnableAutomation();
	
	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	maxid=1;
	
	AfxOleLockApp();
}

XmlHelper::~XmlHelper()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	
	AfxOleUnlockApp();
}

void XmlHelper::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(XmlHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(XmlHelper, CWnd)
	DISP_FUNCTION_ID(XmlHelper, "OpenXml", dispidOpenXml, OpenXml, VT_UI4, VTS_BSTR VTS_UI4)
	DISP_FUNCTION_ID(XmlHelper, "SaveXml", dispidSaveXml, SaveXml, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(XmlHelper, "CloseXml", dispidCloseXml, CloseXml, VT_EMPTY, VTS_UI4)
	DISP_FUNCTION_ID(XmlHelper, "FindNode", dispidFindNode, FindNode, VT_UI4, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(XmlHelper, "FindChildNode", dispidFindChildNode, FindChildNode, VT_UI4, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(XmlHelper, "GetNextNode", dispidGetNextNode, GetNextNode, VT_UI4, VTS_UI4)
	DISP_FUNCTION_ID(XmlHelper, "GetText", dispidGetText, GetText, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(XmlHelper, "GetAttribute", dispidGetAttribute, GetAttribute, VT_BSTR, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(XmlHelper, "SetText", dispidSetText, SetText, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(XmlHelper, "SetAttribute", dispidSetAttribute, SetAttribute, VT_EMPTY, VTS_UI4 VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(XmlHelper, "RemoveAttribute", dispidRemoveAttribute, RemoveAttribute, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(XmlHelper, "AddChildNode", dispidAddChildNode, AddChildNode, VT_UI4, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(XmlHelper, "GetName", dispidGetName, GetName, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(XmlHelper, "RemoveNode", dispidRemoveNode, RemoveNode, VT_EMPTY, VTS_UI4)
	DISP_FUNCTION_ID(XmlHelper, "SetName", dispidSetName, SetName, VT_EMPTY, VTS_UI4 VTS_BSTR)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IXmlHelper 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {C620CE0F-8578-4405-805E-A8AEFFE07F87}
static const IID IID_IXmlHelper =
{ 0xC620CE0F, 0x8578, 0x4405, { 0x80, 0x5E, 0xA8, 0xAE, 0xFF, 0xE0, 0x7F, 0x87 } };

BEGIN_INTERFACE_MAP(XmlHelper, CWnd)
	INTERFACE_PART(XmlHelper, IID_IXmlHelper, Dispatch)
END_INTERFACE_MAP()

// {347858BE-4736-4FA7-9B0C-E6F01FCDE9D6}
IMPLEMENT_OLECREATE(XmlHelper, "PPHT_Helper_C.XmlHelper", 0x347858be, 0x4736, 0x4fa7, 0x9b, 0xc, 0xe6, 0xf0, 0x1f, 0xcd, 0xe9, 0xd6)


// XmlHelper 消息处理程序




ULONG XmlHelper::OpenXml(LPCTSTR path, ULONG type)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	try
	{
		CString str;
		ULONG id1= fileHelper.OpenFile(path,type);
		str=fileHelper.ReadAllString(id1);
		fileHelper.CloseFile(id1);
		TiXmlDocument *xmldoc=new TiXmlDocument();
		BYTE *utf8str;
		convertHelper.StringToUTF8Bytes(str,&utf8str);
		xmldoc->Parse((const char*)utf8str);
		if (!xmldoc->Error())
		{
			docList[maxid]=xmldoc;
			typeList[maxid]=type;
			return maxid++;
		}
	}catch(...){}
	
	return 0;
}


void XmlHelper::SaveXml(ULONG id, LPCTSTR path)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	try
	{
		CString strResult=L"";
		TiXmlDocument *tmpdoc=docList[id];
		ULONG tmptype=typeList[id];
		if (tmpdoc)
		{
			TiXmlPrinter *printer=new TiXmlPrinter();
			tmpdoc->Accept(printer);
			BYTE *textBytes=(BYTE*)printer->CStr();
			if (textBytes)
			{
				strResult=convertHelper.BytesToUTF8String(textBytes);
			}

			ULONG id1= fileHelper.OpenFile(path,tmptype);
			fileHelper.WriteString(id1,strResult.AllocSysString());
			fileHelper.CloseFile(id1);
		}
	}catch(...){}
}


void XmlHelper::CloseXml(ULONG id)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	try
	{
		TiXmlDocument *tmpdoc=docList[id];
		if (tmpdoc)
		{
			delete tmpdoc;
			typeList.erase(id);
			docList.erase(id);
		}
	}catch(...){}
}


ULONG XmlHelper::FindNode(ULONG id, LPCTSTR findStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	try
	{
		CString tmpstr=findStr;
		TiXmlDocument *tmpdoc=docList[id];
		if (tmpdoc && tmpstr.GetLength()>0)
		{
			CString tmpNodeName;
			if (tmpstr.Find(L">")!=-1)
			{
				tmpNodeName=tmpstr.Mid(0,tmpstr.Find(L">"));
				tmpstr=tmpstr.Mid(tmpstr.Find(L">")+1);
			} 
			else
			{
				tmpNodeName=tmpstr;
				tmpstr="";
			}

			BYTE *tmpbyte;
			convertHelper.StringToUTF8Bytes(tmpNodeName,&tmpbyte);
			TiXmlElement *tmpElement=tmpdoc->FirstChildElement((const char*)tmpbyte);
			while(tmpElement)
			{
				if (tmpstr.GetLength()==0 && tmpElement)
				{
					return (ULONG)tmpElement;
				}
				if (tmpstr.Find(L">")!=-1)
				{
					tmpNodeName=tmpstr.Mid(0,tmpstr.Find(L">"));
					tmpstr=tmpstr.Mid(tmpstr.Find(L">")+1);
				} 
				else
				{
					tmpNodeName=tmpstr;
					tmpstr="";
				}
				delete tmpbyte;
				convertHelper.StringToUTF8Bytes(tmpNodeName,&tmpbyte);
				tmpElement=tmpdoc->FirstChildElement((const char*)tmpbyte);
			}
		}
	}catch(...){}

	return 0;
}


ULONG XmlHelper::FindChildNode(ULONG nodeId, LPCTSTR findStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString tmpstr=findStr;
	try
	{
		TiXmlElement *tmpElement=(TiXmlElement*)nodeId;
		if (tmpElement && tmpstr.GetLength()>0)
		{
			CString tmpNodeName;
			if (tmpstr.Find(L">")!=-1)
			{
				tmpNodeName=tmpstr.Mid(0,tmpstr.Find(L">"));
				tmpstr=tmpstr.Mid(tmpstr.Find(L">")+1);
			} 
			else
			{
				tmpNodeName=tmpstr;
				tmpstr="";
			}

			BYTE *tmpbyte;
			convertHelper.StringToUTF8Bytes(tmpNodeName,&tmpbyte);
			tmpElement=tmpElement->FirstChildElement((const char*)tmpbyte);
			while(tmpElement)
			{
				if (tmpstr.GetLength()==0 && tmpElement)
				{
					return (ULONG)tmpElement;
				}
				if (tmpstr.Find(L">")!=-1)
				{
					tmpNodeName=tmpstr.Mid(0,tmpstr.Find(L">"));
					tmpstr=tmpstr.Mid(tmpstr.Find(L">")+1);
				} 
				else
				{
					tmpNodeName=tmpstr;
					tmpstr="";
				}
				delete tmpbyte;
				convertHelper.StringToUTF8Bytes(tmpNodeName,&tmpbyte);
				tmpElement=tmpElement->FirstChildElement((const char*)tmpbyte);
			}
		}
	}catch(...){}

	return 0;
}


ULONG XmlHelper::GetNextNode(ULONG nodeId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	try
	{
		TiXmlElement *tmpElement=(TiXmlElement*)nodeId;
		return (ULONG)tmpElement->NextSiblingElement();
	}catch(...){}
	return 0;
}


BSTR XmlHelper::GetText(ULONG nodeId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	try
	{
	}catch(...){}
	CString strResult=L"";

	TiXmlElement *tmpElement=(TiXmlElement*)nodeId;
	BYTE *textBytes=(BYTE*)tmpElement->GetText();
	if (textBytes)
	{
		strResult=convertHelper.BytesToUTF8String(textBytes);
	}

	return strResult.AllocSysString();
}


BSTR XmlHelper::GetAttribute(ULONG nodeId, LPCTSTR attributeName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString strResult=L"";
	try
	{
		BYTE* tmpAttrName;
		convertHelper.StringToUTF8Bytes(attributeName,&tmpAttrName);
		TiXmlElement *tmpElement=(TiXmlElement*)nodeId;
		BYTE *textBytes=(BYTE*)tmpElement->Attribute((const char*)tmpAttrName);
		if (textBytes)
		{
			strResult=convertHelper.BytesToUTF8String(textBytes);
		}
	}catch(...){}

	return strResult.AllocSysString();
}


void XmlHelper::SetText(ULONG nodeId, LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	try
	{
		BYTE* tmpTextBytes;
		convertHelper.StringToUTF8Bytes(val,&tmpTextBytes);
		TiXmlElement *tmpElement=(TiXmlElement*)nodeId;
		tmpElement->Clear();
		TiXmlText *tmpText=new TiXmlText((const char*)tmpTextBytes);
		tmpElement->LinkEndChild(tmpText);
	}catch(...){}
}


void XmlHelper::SetAttribute(ULONG nodeId, LPCTSTR key, LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	try
	{
		BYTE* tmpKeyBytes;
		BYTE* tmpValBytes;
		convertHelper.StringToUTF8Bytes(key,&tmpKeyBytes);
		convertHelper.StringToUTF8Bytes(val,&tmpValBytes);
		TiXmlElement *tmpElement=(TiXmlElement*)nodeId;
		tmpElement->SetAttribute((const char*)tmpKeyBytes,(const char*)tmpValBytes);
	}catch(...){}
}


void XmlHelper::RemoveAttribute(ULONG nodeId, LPCTSTR key)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	try
	{
		BYTE* tmpKeyBytes;
		convertHelper.StringToUTF8Bytes(key,&tmpKeyBytes);
		TiXmlElement *tmpElement=(TiXmlElement*)nodeId;
		tmpElement->RemoveAttribute((const char*)tmpKeyBytes);
	}catch(...){}
}


ULONG XmlHelper::AddChildNode(ULONG nodeId, LPCTSTR name)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	try
	{
		TiXmlElement *tmpElement=(TiXmlElement*)nodeId;

		BYTE* tmpNameBytes;
		convertHelper.StringToUTF8Bytes(name,&tmpNameBytes);
		TiXmlElement *newElement=new TiXmlElement((const char*)tmpNameBytes);
		return (ULONG)tmpElement->LinkEndChild(newElement)->ToElement();
	}catch(...){}
	return 0;
}


BSTR XmlHelper::GetName(ULONG nodeId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString strResult=L"";
	try
	{
		TiXmlElement *tmpElement=(TiXmlElement*)nodeId;
		BYTE* tmpValBytes=(BYTE*)tmpElement->Value();
		if (tmpValBytes)
		{
			strResult=convertHelper.BytesToUTF8String(tmpValBytes);
		}
	}catch(...){}

	return strResult.AllocSysString();
}


void XmlHelper::RemoveNode(ULONG nodeId)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	try
	{
		TiXmlElement *tmpElement=(TiXmlElement*)nodeId;
		TiXmlNode *tmpParent=tmpElement->Parent();
		if (tmpParent)
		{
			tmpParent->RemoveChild(tmpElement);
		}
	}catch(...){}
}


void XmlHelper::SetName(ULONG nodeId, LPCTSTR name)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	try
	{
		TiXmlElement *tmpElement=(TiXmlElement*)nodeId;
		BYTE* tmpNameBytes;
		convertHelper.StringToUTF8Bytes(name,&tmpNameBytes);
		tmpElement->SetValue((const char*)tmpNameBytes);
	}catch(...){}
}
