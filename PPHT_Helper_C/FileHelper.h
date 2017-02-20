#pragma once

#include <map>
#include <fstream>
#include "ConvertHelper.h"

using namespace std;

// FileHelper

class FileHelper : public CWnd
{
	DECLARE_DYNCREATE(FileHelper)

public:
	FileHelper();
	virtual ~FileHelper();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(FileHelper)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	enum 
	{
		dispidClearFile = 10L,
		dispidWriteLineString = 9L,
		dispidWriteString = 8L,
		dispidGetFileSize = 7L,
		dispidGetSeek = 6L,
		dispidSetSeek = 5L,
		dispidReadLineString = 4L,
		dispidReadAllString = 3L,
		dispidCloseFile = 2L,
		dispidOpenFile = 1L
	};

private:
	map<ULONG,fstream*> fileList;
	map<ULONG,ULONG> typeList;
	ULONG maxid;
	ConvertHelper convertHelper;

public:
	ULONG OpenFile(LPCTSTR path, ULONG type);
	void CloseFile(ULONG id);
	BSTR ReadAllString(ULONG id);
	BSTR ReadLineString(ULONG id);
	void SetSeek(ULONG id, ULONG offset, ULONG type);
	ULONG GetSeek(ULONG id);
	ULONG GetFileSize(ULONG id);
	void WriteString(ULONG id, LPCTSTR val);
	void WriteLineString(ULONG id, LPCTSTR val);
	void ClearFile(ULONG id);
};


