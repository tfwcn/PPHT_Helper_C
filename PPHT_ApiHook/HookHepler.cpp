// HookHepler.cpp : 实现文件
//

#include "stdafx.h"
#include "PPHT_ApiHook.h"
#include "HookHepler.h"
#include "FileHelper.h"

#define WM_ENABLEAPIHOOK 0x08
#define WM_DISABLEAPIHOOK 0x09

struct HookShare{
	int unHookOk;
	DWORD oldFun;
};

HookShare *share_data;

// HookHepler

IMPLEMENT_DYNCREATE(HookHepler, CWnd)

HookHepler::HookHepler()
{

	EnableAutomation();
	
	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	HANDLE hMap = CreateFileMapping((HFILE *)0xFFFFFFFF,NULL,PAGE_READWRITE,0,sizeof(HookShare),L"HookShare"); 
	share_data = (HookShare*)MapViewOfFile(hMap,FILE_MAP_ALL_ACCESS,0 ,0 ,0); 
	share_data->unHookOk=0;
	theApp=(CPPHT_ApiHookApp*)::AfxGetApp();
	/*share_data=theApp->share_data;*/

	AfxOleLockApp();
}

HookHepler::~HookHepler()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	
	AfxOleUnlockApp();
}

void HookHepler::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(HookHepler, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(HookHepler, CWnd)
	DISP_FUNCTION_ID(HookHepler, "SetHook", dispidSetHook, SetHook, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(HookHepler, "RemoveHook", dispidRemoveHook, RemoveHook, VT_I4, VTS_NONE)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IHookHepler 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {9DD297A7-31C2-43BE-83C6-5024790CB870}
static const IID IID_IHookHepler =
{ 0x9DD297A7, 0x31C2, 0x43BE, { 0x83, 0xC6, 0x50, 0x24, 0x79, 0xC, 0xB8, 0x70 } };

BEGIN_INTERFACE_MAP(HookHepler, CWnd)
	INTERFACE_PART(HookHepler, IID_IHookHepler, Dispatch)
END_INTERFACE_MAP()

// {D609900D-F747-4FB4-974D-B9C49A6FD231}
IMPLEMENT_OLECREATE(HookHepler, "PPHT_ApiHook.HookHepler", 0xd609900d, 0xf747, 0x4fb4, 0x97, 0x4d, 0xb9, 0xc4, 0x9a, 0x6f, 0xd2, 0x31)


// HookHepler 消息处理程序


DWORD pid,tid;
HHOOK hhk1=0;

typedef HRESULT (*MyDirectInput8Create)(HINSTANCE hinst,DWORD dwVersion,
	REFIID riidltf, LPVOID *ppvOut, LPUNKNOWN punkOuter);

typedef HRESULT (*MyGetDeviceState)(DWORD cbData,LPVOID lpvData);
typedef FARPROC (*MyGetProcAddress)(HMODULE hModule,LPCSTR lpProcName);

typedef unsigned (*MySleep)(unsigned seconds);

DWORD oldfun=0;
LPVOID oldfunadd=0;
DWORD oldfun2=0;
LPVOID oldfunadd2=0;

HRESULT MyGetDeviceStateFun(DWORD cbData,LPVOID lpvData)
{
	MyGetDeviceState old=(MyGetDeviceState)oldfun2;
	HRESULT ret=old(cbData,lpvData);
	::MessageBox(NULL,L"MyDirectInput8CreateFun",L"",MB_OK);
	int buffsize=cbData;
	if (buffsize==256)
	{
		//((char*)lpvData)[13]=1;
	}
	return ret;
}

HRESULT MyDirectInput8CreateFun(HINSTANCE hinst,DWORD dwVersion,
	REFIID riidltf, LPVOID *ppvOut, LPUNKNOWN punkOuter)
{
	if (oldfun2==0)
	{
		DWORD dwOldProtect = 0;
		oldfunadd2=ppvOut+0x0C;
		oldfun2=*((DWORD*)oldfunadd2);
		VirtualProtect(oldfunadd2, 4, PAGE_READWRITE, &dwOldProtect);
		*((DWORD*)oldfunadd2) = (DWORD)MyGetDeviceStateFun;
		VirtualProtect(oldfunadd2, 4, PAGE_READWRITE, &dwOldProtect);
	}
	CString tmpstr;
	tmpstr.Format(L"%d,%d",oldfun2,oldfunadd2);
	::MessageBox(NULL,L"MyDirectInput8CreateFun",tmpstr,MB_OK);
	MyDirectInput8Create old=(MyDirectInput8Create)oldfun;
	return old(hinst,dwVersion,riidltf,ppvOut,punkOuter);
}

FARPROC MyGetProcAddressFun(HMODULE hModule,LPCSTR lpProcName)
{
	MyGetProcAddress mgp=(MyGetProcAddress)oldfun;
	::MessageBox(NULL,L"MyGetProcAddressFun",(LPCWSTR)lpProcName,MB_OK);
	return mgp(hModule,lpProcName);
}

unsigned MySleepFun(unsigned seconds)
{
	MySleep mgp=(MySleep)oldfun;
	::MessageBox(NULL,L"MySleepFun",L"",MB_OK);
	return mgp(seconds);
}

int Hook(void)
{
	HANDLE hMap = OpenFileMapping(FILE_MAP_ALL_ACCESS,false,L"HookShare"); 
	share_data = (HookShare*)MapViewOfFile(hMap,FILE_MAP_ALL_ACCESS,0 ,0 ,0); 
	CString tmpstr;
	FileHelper *fh=new FileHelper();
	ConvertHelper *ch=new ConvertHelper();
	int id= fh->OpenFile(L"F:\\log.txt",0);
	tmpstr.Format(L"%d",id);
	::MessageBox(NULL,L"Hook",tmpstr,MB_OK);
	DWORD ImageBase = (DWORD)::GetModuleHandle(NULL);
	IMAGE_DOS_HEADER *pdosHeader = (IMAGE_DOS_HEADER*)ImageBase;
	//首部地址偏移
	IMAGE_NT_HEADERS *pntHeaders = (IMAGE_NT_HEADERS*)((DWORD)ImageBase + pdosHeader->e_lfanew);
	if (pntHeaders->Signature==IMAGE_NT_SIGNATURE)
	{
		//32位影像文件
		if (pntHeaders->OptionalHeader.Magic==IMAGE_NT_OPTIONAL_HDR32_MAGIC)
		{
			//数组第一个为导出表，第二个为导入表
			IMAGE_DATA_DIRECTORY *pSymbolTable = &pntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
			IMAGE_IMPORT_DESCRIPTOR *piid = (IMAGE_IMPORT_DESCRIPTOR*)((DWORD)ImageBase + pSymbolTable->VirtualAddress);
			while(piid->FirstThunk)
			{
				BYTE* dllName=(BYTE*)((DWORD)ImageBase +piid->Name);
				CString dllNameStr=ch->BytesToANSIString(dllName);
				fh->WriteLineString(id,dllNameStr);
				IMAGE_THUNK_DATA *pitd=(IMAGE_THUNK_DATA*)((DWORD)ImageBase + piid->FirstThunk);
				IMAGE_THUNK_DATA *pitd2=(IMAGE_THUNK_DATA*)((DWORD)ImageBase + piid->OriginalFirstThunk);
				while(pitd->u1.Function)
				{
					if ((*((DWORD*)pitd2)&0x80000000)==0)
					{
						IMAGE_IMPORT_BY_NAME *piibn=(IMAGE_IMPORT_BY_NAME*)((DWORD)ImageBase + pitd2->u1.AddressOfData);
						BYTE* funName=(BYTE*)piibn->Name;
						CString funNameStr;
						funNameStr.Format(L"\t%d,%s",piibn->Hint,ch->BytesToANSIString(funName));
						fh->WriteLineString(id,funNameStr);
						funNameStr.Format(L"\t%d,%d",pitd->u1.Function,pitd2->u1.Function);
						fh->WriteLineString(id,funNameStr);
						if (oldfun==0 && strcmpi((char*)dllName,"KERNEL32.dll")==0 && strcmpi((char*)funName,"Sleep")==0)
						{
							/*oldfun= pitd->u1.Function;
							DWORD dwOldProtect = 0;
							VirtualProtect(&(pitd->u1.Function),4,PAGE_READWRITE, &dwOldProtect);
							pitd->u1.Function=(DWORD)MySleepFun;
							VirtualProtect(&(pitd->u1.Function),4,dwOldProtect, &dwOldProtect);*/
							//::WriteProcessMemory(GetCurrentProcess(),&(pitd->u1.Function),MyGetProcAddressFun,4,NULL);
						}
					}
					pitd++;
					pitd2++;
				}
				piid++;
			}
		}
	}
	fh->CloseFile(id);
	::MessageBox(NULL,L"Hook",L"Close",MB_OK);
	share_data->unHookOk=1;
	return 0;
}

DWORD HookWinAPI(char* findDllName,char* findFunName,DWORD newfun)
{
	DWORD oldFunVal=0;
	DWORD ImageBase = (DWORD)::GetModuleHandle(NULL);
	IMAGE_DOS_HEADER *pdosHeader = (IMAGE_DOS_HEADER*)ImageBase;
	//首部地址偏移
	IMAGE_NT_HEADERS *pntHeaders = (IMAGE_NT_HEADERS*)((DWORD)ImageBase + pdosHeader->e_lfanew);
	if (pntHeaders->Signature==IMAGE_NT_SIGNATURE)
	{
		//32位影像文件
		if (pntHeaders->OptionalHeader.Magic==IMAGE_NT_OPTIONAL_HDR32_MAGIC)
		{
			//数组第一个为导出表，第二个为导入表
			IMAGE_DATA_DIRECTORY *pSymbolTable = &pntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
			IMAGE_IMPORT_DESCRIPTOR *piid = (IMAGE_IMPORT_DESCRIPTOR*)((DWORD)ImageBase + pSymbolTable->VirtualAddress);
			while(piid->FirstThunk)
			{
				BYTE* dllName=(BYTE*)((DWORD)ImageBase +piid->Name);
				IMAGE_THUNK_DATA *pitd=(IMAGE_THUNK_DATA*)((DWORD)ImageBase + piid->FirstThunk);
				IMAGE_THUNK_DATA *pitd2=(IMAGE_THUNK_DATA*)((DWORD)ImageBase + piid->OriginalFirstThunk);
				while(pitd->u1.Function)
				{
					if ((*((DWORD*)pitd2)&0x80000000)==0)
					{
						IMAGE_IMPORT_BY_NAME *piibn=(IMAGE_IMPORT_BY_NAME*)((DWORD)ImageBase + pitd2->u1.AddressOfData);
						BYTE* funName=(BYTE*)piibn->Name;
						if (oldfun==0 && strcmpi((char*)dllName,findDllName)==0 && strcmpi((char*)funName,findFunName)==0)
						{
							oldFunVal= pitd->u1.Function;
							DWORD dwOldProtect = 0;
							//VirtualProtect(&(pitd->u1.Function),4,PAGE_READWRITE, &dwOldProtect);
							//pitd->u1.Function=newfun;
							//VirtualProtect(&(pitd->u1.Function),4,dwOldProtect, &dwOldProtect);
							//::WriteProcessMemory(GetCurrentProcess(),&(pitd->u1.Function),MyGetProcAddressFun,4,NULL);
						}
					}
					pitd++;
					pitd2++;
				}
				piid++;
			}
		}
	}
	return oldFunVal;
}

int UnHook(void)
{
	CString str;
	str.Format(L"%d",share_data->unHookOk);
	::MessageBoxW(NULL,L"UnHook",str,MB_OK);
	*((DWORD*)oldfunadd)=oldfun;
	*((DWORD*)oldfunadd2)=oldfun2;
	share_data->unHookOk=1;
	return 0;
}

LRESULT CALLBACK GetMsgProc(int nCode,WPARAM wParam, LPARAM lParam) {
	if (nCode == HC_ACTION) {
		MSG *msg = (MSG *)lParam;
		if (msg->message == WM_ENABLEAPIHOOK) {
			Hook();
		}else if(msg->message== WM_DISABLEAPIHOOK){
			UnHook();
		}
	}
	return CallNextHookEx(hhk1,nCode,wParam,lParam);
}

LONG HookHepler::SetHook(LONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	while(share_data->unHookOk!=0){}
	tid=::GetWindowThreadProcessId((HWND)hwnd,&pid);
	hhk1=::SetWindowsHookEx(WH_GETMESSAGE,GetMsgProc,theApp->m_hInstance,tid);
	::PostThreadMessage(tid,WM_ENABLEAPIHOOK,0,0);
	while(share_data->unHookOk==0){}
	share_data->unHookOk=0;
	return 0;
}


LONG HookHepler::RemoveHook(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	while(share_data->unHookOk!=0){}
	::PostThreadMessage(tid,WM_DISABLEAPIHOOK,0,0);
	while(share_data->unHookOk==0){}
	CString str;
	str.Format(L"%d:%d",share_data->unHookOk,hhk1);
	::MessageBoxW(NULL,L"RemoveHook",str,MB_OK);
	::UnhookWindowsHookEx(hhk1);
	share_data->unHookOk=0;
	return 0;
}
