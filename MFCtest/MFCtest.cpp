// MFCtest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MFCtest.h"
#include "FileHelper.h"
#include "tinyxml.h"
#include "ConvertHelper.h"
#include <boost\regex.hpp>
#include <iostream>
#include "MemoryHelper.h"
#include "ControlHelper.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 唯一的应用程序对象

CWinApp theApp;

using namespace std;
using namespace boost;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	//MemoryHelper *memoryHelper=new MemoryHelper();
	/*ULONG pid = memoryHelper->GetPidByProcessName(L"DragonNest.exe");
	ULONG hwnd = memoryHelper->GetHwndByPid(pid);*/
	//ULONG hwnd = 0x6066C;
	//ControlHelper *controlHelper=new ControlHelper();
	//controlHelper->KeyPress(hwnd,67,2);
	//FileHelper *fh=new FileHelper();
	//int id=fh->OpenFile(L"G:\\log.txt",3);
	//DWORD ImageBase = (DWORD)::GetModuleHandle(NULL);
	//IMAGE_DOS_HEADER *pdosHeader = (IMAGE_DOS_HEADER*)ImageBase;
	////首部地址偏移
	//IMAGE_NT_HEADERS *pntHeaders = (IMAGE_NT_HEADERS*)((DWORD)ImageBase + pdosHeader->e_lfanew);
	//if (pntHeaders->Signature==IMAGE_NT_SIGNATURE)
	//{
	//	//32位影像文件
	//	if (pntHeaders->OptionalHeader.Magic==IMAGE_NT_OPTIONAL_HDR32_MAGIC)
	//	{
	//		//数组第一个为导出表，第二个为导入表
	//		IMAGE_DATA_DIRECTORY *pSymbolTable = &pntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
	//		IMAGE_IMPORT_DESCRIPTOR *piid = (IMAGE_IMPORT_DESCRIPTOR*)((DWORD)ImageBase + pSymbolTable->VirtualAddress);
	//		while(piid->FirstThunk)
	//		{
	//			char* dllName=(char*)((DWORD)ImageBase +piid->Name);
	//			string s=dllName;
	//			CString dllNameStr;
	//			dllNameStr.Format(L"%s",s);
	//			fh->WriteLineString(id,dllNameStr);
	//			IMAGE_THUNK_DATA *pitd=(IMAGE_THUNK_DATA*)((DWORD)ImageBase + piid->FirstThunk);
	//			IMAGE_THUNK_DATA *pitd2=(IMAGE_THUNK_DATA*)((DWORD)ImageBase + piid->OriginalFirstThunk);
	//			while(pitd->u1.Function)
	//			{
	//				if ((*((DWORD*)pitd2)&0x80000000)==0)
	//				{
	//					IMAGE_IMPORT_BY_NAME *piibn=(IMAGE_IMPORT_BY_NAME*)((DWORD)ImageBase + pitd2->u1.AddressOfData);
	//					char* funName=(char*)piibn->Name;
	//					CString funNameStr;
	//					funNameStr.Format(L"\t%d,%s",piibn->Hint,funName);
	//					fh->WriteLineString(id,funNameStr);
	//					funNameStr.Format(L"\t%d,%d",pitd->u1.Function,pitd2->u1.Function);
	//					fh->WriteLineString(id,funNameStr);
	//				}
	//				pitd++;
	//				pitd2++;
	//			}
	//			piid++;
	//		}
	//	}
	//}
	//fh->CloseFile(id);
	::Sleep(2000);
	LONG x=60,y=80;
	LONG fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
	LONG fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;
	LONG fx = x*(65535.0f/fScreenWidth);
	LONG fy = y*(65535.0f/fScreenHeight);
	RECT *size=new RECT();
	//::GetWindowRect((HWND)0x601E4,size);
	::GetClientRect((HWND)0x601E4,size);
	POINT *p=new POINT();
	::ClientToScreen((HWND)0x601E4,p);
	::MoveWindow((HWND)0x601E4,100,100,size->right-size->left,size->bottom-size->top,true);
	return 0;
}