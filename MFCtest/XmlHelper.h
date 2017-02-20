#pragma once
#include "FileHelper.h"
#include "ConvertHelper.h"
#include "tinyxml.h"


// XmlHelper

class XmlHelper : public CWnd
{
	DECLARE_DYNCREATE(XmlHelper)

public:
	XmlHelper();
	virtual ~XmlHelper();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(XmlHelper)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	enum 
	{
		dispidSetName = 15L,
		dispidRemoveNode = 14L,
		dispidGetName = 13L,
		dispidAddChildNode = 12L,
		dispidRemoveAttribute = 11L,
		dispidSetAttribute = 10L,
		dispidSetText = 9L,
		dispidGetAttribute = 8L,
		dispidGetText = 7L,
		dispidGetNextNode = 6L,
		dispidFindChildNode = 5L,
		dispidFindNode = 4L,
		dispidCloseXml = 3L,
		dispidSaveXml = 2L,
		dispidOpenXml = 1L
	};

private:
	map<ULONG,TiXmlDocument*> docList;
	map<ULONG,ULONG> typeList;
	TiXmlElement *nowElement;
	ULONG maxid;
	FileHelper fileHelper;
	ConvertHelper convertHelper;
public:
	ULONG OpenXml(LPCTSTR path, ULONG type);
	void SaveXml(ULONG id, LPCTSTR path);
	void CloseXml(ULONG id);
	ULONG FindNode(ULONG id, LPCTSTR findStr);
	ULONG FindChildNode(ULONG nodeId, LPCTSTR findStr);
	ULONG GetNextNode(ULONG nodeId);
	BSTR GetText(ULONG nodeId);
	BSTR GetAttribute(ULONG nodeId, LPCTSTR attributeName);
	void SetText(ULONG nodeId, LPCTSTR val);
	void SetAttribute(ULONG nodeId, LPCTSTR key, LPCTSTR val);
	void RemoveAttribute(ULONG nodeId, LPCTSTR key);
	ULONG AddChildNode(ULONG nodeId, LPCTSTR name);
	BSTR GetName(ULONG nodeId);
	void RemoveNode(ULONG nodeId);
	void SetName(ULONG nodeId, LPCTSTR name);
};


