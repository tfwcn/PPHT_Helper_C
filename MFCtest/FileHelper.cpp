// FileHelper.cpp : 实现文件
//

#include "stdafx.h"
//#include "PPHT_Helper_C.h"
#include "FileHelper.h"


// FileHelper

IMPLEMENT_DYNCREATE(FileHelper, CWnd)

	FileHelper::FileHelper()
{

	EnableAutomation();

	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	maxid=1;

	AfxOleLockApp();
}

FileHelper::~FileHelper()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。

	map<ULONG,ULONG>::iterator pos;
	for (pos=typeList.begin();pos!=typeList.end();pos++)
	{
		CloseFile(pos->first);
	}

	AfxOleUnlockApp();
}

void FileHelper::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(FileHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(FileHelper, CWnd)
	DISP_FUNCTION_ID(FileHelper, "OpenFile", dispidOpenFile, OpenFile, VT_UI4, VTS_BSTR VTS_UI4)
	DISP_FUNCTION_ID(FileHelper, "CloseFile", dispidCloseFile, CloseFile, VT_EMPTY, VTS_UI4)
	DISP_FUNCTION_ID(FileHelper, "ReadAllString", dispidReadAllString, ReadAllString, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(FileHelper, "ReadLineString", dispidReadLineString, ReadLineString, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(FileHelper, "SetSeek", dispidSetSeek, SetSeek, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(FileHelper, "GetSeek", dispidGetSeek, GetSeek, VT_UI4, VTS_UI4)
	DISP_FUNCTION_ID(FileHelper, "GetFileSize", dispidGetFileSize, GetFileSize, VT_UI4, VTS_UI4)
	DISP_FUNCTION_ID(FileHelper, "WriteString", dispidWriteString, WriteString, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(FileHelper, "WriteLineString", dispidWriteLineString, WriteLineString, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(FileHelper, "ClearFile", dispidClearFile, ClearFile, VT_EMPTY, VTS_UI4)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IFileHelper 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {F6C73760-EAA2-4525-A85B-7C56E370F859}
static const IID IID_IFileHelper =
{ 0xF6C73760, 0xEAA2, 0x4525, { 0xA8, 0x5B, 0x7C, 0x56, 0xE3, 0x70, 0xF8, 0x59 } };

BEGIN_INTERFACE_MAP(FileHelper, CWnd)
	INTERFACE_PART(FileHelper, IID_IFileHelper, Dispatch)
END_INTERFACE_MAP()

// {0E270940-C4D7-4F5D-98A2-3FB00F0080F2}
IMPLEMENT_OLECREATE(FileHelper, "PPHT_Helper_C.FileHelper", 0xe270940, 0xc4d7, 0x4f5d, 0x98, 0xa2, 0x3f, 0xb0, 0xf, 0, 0x80, 0xf2)


	// FileHelper 消息处理程序




	ULONG FileHelper::OpenFile(LPCTSTR path, ULONG type)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	fstream *tmpf=new fstream();
	tmpf->open(path,ios::out|ios::binary);
	if (tmpf->good())
	{
		tmpf->close();
	}
	tmpf->open(path,ios::in|ios::out|ios::binary);

	if (tmpf->good())
	{
		fileList[maxid]=tmpf;
		typeList[maxid]=type;
		return maxid++;
	}
	else
	{
		return 0;
	}
}


void FileHelper::CloseFile(ULONG id)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	fstream *tmpf=fileList[id];
	if (tmpf)
	{
		tmpf->close();
		typeList.erase(id);
		fileList.erase(id);
	}
}


BSTR FileHelper::ReadAllString(ULONG id)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	fstream *tmpf=fileList[id];
	if (tmpf)
	{
		ULONG len=0;
		tmpf->seekg(0,ios::end);
		len=tmpf->tellg();
		tmpf->seekg(0,ios::beg);
		if (typeList[id]<=1)
		{
			if (tmpf->tellg()<2)
			{
				BYTE *header=new BYTE[2];
				header[0]=0xFF;
				header[1]=0xFE;
				tmpf->seekg(0,ios::beg);
				tmpf->read((char*)header,2);
				if (header[0]==0xFF && header[1]==0xFE)
				{
					len-=2;
				}
				else
				{
					tmpf->seekg(0,ios::beg);
				}
			}
			BYTE *val=new BYTE[len+2];
			tmpf->read((char*)val,len);
			val[len]='\0';
			val[len+1]='\0';
			strResult=convertHelper.BytesToUnicodeString(val);
		}
		else if(typeList[id]==2)
		{
			BYTE *val=new BYTE[len+1];
			tmpf->read((char*)val,len);
			val[len]='\0';
			strResult=convertHelper.BytesToANSIString(val);
		}
		else if(typeList[id]>=3)
		{
			if (tmpf->tellg()<3)
			{
				BYTE *header=new BYTE[3];
				tmpf->seekg(0,ios::beg);
				tmpf->read((char*)header,3);
				if (header[0]==0xEF && header[1]==0xBB && header[2]==0xBF)
				{
					len-=3;
				}
				else
				{
					tmpf->seekg(0,ios::beg);
				}
			}
			BYTE *val=new BYTE[len+1];
			tmpf->read((char*)val,len);
			val[len]='\0';
			strResult=convertHelper.BytesToUTF8String(val);
		}
	}

	return strResult.AllocSysString();
}


BSTR FileHelper::ReadLineString(ULONG id)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	fstream *tmpf=fileList[id];
	if (tmpf)
	{
		ULONG len=0,oldSeek=0;
		BYTE *val;
		oldSeek= tmpf->tellg();
		tmpf->seekg(0,ios::end);
		len=tmpf->tellg();
		tmpf->seekg(oldSeek,ios::beg);
		if (typeList[id]<=1)
		{
			if (tmpf->tellg()<2)
			{
				BYTE *header=new BYTE[2];
				header[0]=0xFF;
				header[1]=0xFE;
				tmpf->seekg(0,ios::beg);
				tmpf->read((char*)header,2);
				if (header[0]==0xFF && header[1]==0xFE)
				{
					len-=2;
				}
				else
				{
					tmpf->seekg(0,ios::beg);
				}
			}
			BYTE *val=new BYTE[len+2];
			tmpf->getline((char*)val,len,'\n');
			len=tmpf->tellg();
			val[len-oldSeek]='\0';
			val[len-oldSeek+1]='\0';
			strResult=convertHelper.BytesToUnicodeString(val);
		}
		else if(typeList[id]==2)
		{
			BYTE *val=new BYTE[len+1];
			tmpf->getline((char*)val,len,'\n');
			len=tmpf->tellg();
			val[len-oldSeek]='\0';
			strResult=convertHelper.BytesToANSIString(val);
		}
		else if(typeList[id]>=3)
		{
			if (tmpf->tellg()<3)
			{
				BYTE *header=new BYTE[3];
				tmpf->seekg(0,ios::beg);
				tmpf->read((char*)header,3);
				if (header[0]==0xEF && header[1]==0xBB && header[2]==0xBF)
				{
					len-=3;
				}
				else
				{
					tmpf->seekg(0,ios::beg);
				}
			}
			BYTE *val=new BYTE[len+1];
			tmpf->getline((char*)val,len,'\n');
			len=tmpf->tellg();
			val[len-oldSeek]='\0';
			strResult=convertHelper.BytesToUTF8String(val);
		}
	}

	return strResult.AllocSysString();
}


void FileHelper::SetSeek(ULONG id, ULONG offset, ULONG type)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	fstream *tmpf=fileList[id];
	if (tmpf)
	{
		if (type==1)
		{
			tmpf->seekg(offset,ios::cur);
		}
		else if (type==2)
		{
			tmpf->seekg(offset,ios::end);
		}
		else
		{
			tmpf->seekg(offset,ios::beg);
		}
	}
}


ULONG FileHelper::GetSeek(ULONG id)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	fstream *tmpf=fileList[id];
	if (tmpf)
	{
		return tmpf->tellg();
	}
	return 0;
}


ULONG FileHelper::GetFileSize(ULONG id)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	fstream *tmpf=fileList[id];
	if (tmpf)
	{
		ULONG len=0;
		BYTE *val;
		tmpf->seekg(0,ios::end);
		len=tmpf->tellg();
		tmpf->seekg(0,ios::beg);
		return len;
	}

	return 0;
}


void FileHelper::WriteString(ULONG id, LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	fstream *tmpf=fileList[id];
	if (tmpf)
	{
		if (typeList[id]<=1)
		{
			if (tmpf->tellg()<2)
			{
				BYTE *header=new BYTE[2];
				header[0]=0xFF;
				header[1]=0xFE;
				tmpf->seekg(0,ios::beg);
				tmpf->write((char*)header,2);
			}
			BYTE *writeVal;
			ULONG len=convertHelper.StringToUnicodeBytes(val,&writeVal);
			tmpf->write((char*)writeVal,len);
		}
		else if(typeList[id]==2)
		{
			BYTE *writeVal;
			ULONG len=convertHelper.StringToANSIBytes(val,&writeVal);
			tmpf->write((char*)writeVal,len);
		}
		else if(typeList[id]>=3)
		{
			if (tmpf->tellg()<3)
			{
				BYTE *header=new BYTE[3];
				header[0]=0xEF;
				header[1]=0xBB;
				header[2]=0xBF;
				tmpf->seekg(0,ios::beg);
				tmpf->write((char*)header,3);
			}
			BYTE *writeVal;
			ULONG len=convertHelper.StringToUTF8Bytes(val,&writeVal);
			tmpf->write((char*)writeVal,len);
		}
	}
}


void FileHelper::WriteLineString(ULONG id, LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	fstream *tmpf=fileList[id];
	if (tmpf)
	{
		if (typeList[id]<=1)
		{
			if (tmpf->tellg()<2)
			{
				BYTE *header=new BYTE[2];
				header[0]=0xFF;
				header[1]=0xFE;
				tmpf->seekg(0,ios::beg);
				tmpf->write((char*)header,2);
			}
			BYTE *writeVal;
			ULONG len=convertHelper.StringToUnicodeBytes(val,&writeVal);
			tmpf->write((char*)writeVal,len);
			tmpf->write("\r\0\n\0",4);
		}
		else if(typeList[id]==2)
		{
			BYTE *writeVal;
			ULONG len=convertHelper.StringToANSIBytes(val,&writeVal);
			tmpf->write((char*)writeVal,len);
			tmpf->write("\r\n",2);
		}
		else if(typeList[id]>=3)
		{
			if (tmpf->tellg()<3)
			{
				BYTE *header=new BYTE[3];
				header[0]=0xEF;
				header[1]=0xBB;
				header[2]=0xBF;
				tmpf->seekg(0,ios::beg);
				tmpf->write((char*)header,3);
			}
			BYTE *writeVal;
			ULONG len=convertHelper.StringToUTF8Bytes(val,&writeVal);
			tmpf->write((char*)writeVal,len);
			tmpf->write("\r\n",2);
		}
	}
}


void FileHelper::ClearFile(ULONG id)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	fstream *tmpf=fileList[id];
	if (tmpf)
	{
		tmpf->clear();
	}
}
