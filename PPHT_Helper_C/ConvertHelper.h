#pragma once


// ConvertHelper

class ConvertHelper : public CWnd
{
	DECLARE_DYNCREATE(ConvertHelper)

public:
	ConvertHelper();
	virtual ~ConvertHelper();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(ConvertHelper)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	enum 
	{
		dispidHexToInt = 2L,
		dispidIntToHex = 1L
	};
public:
	BSTR IntToHex(ULONG val,ULONG len);
	ULONG HexToInt(LPCTSTR val);
};


