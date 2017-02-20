#pragma once


// HookHepler

class HookHepler : public CWnd
{
	DECLARE_DYNCREATE(HookHepler)

public:
	HookHepler();
	virtual ~HookHepler();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(HookHepler)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	enum 
	{
		dispidRemoveHook = 2L,
		dispidSetHook = 1L
	};
public:
	int Hook(void);
	int UnHook(void);
	LONG SetHook(LONG hwnd);
	LONG RemoveHook(void);
	//HookShare *share_data;
	CPPHT_ApiHookApp *theApp;
};


