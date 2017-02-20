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
		dispidBytesToDouble = 10L,
		dispidBytesToInt = 9L,
		dispidBytesToUTF8String = 8L,
		dispidBytesToANSIString = 7L,
		dispidBytesToUnicodeString = 6L,
		dispidStringToUTF8Bytes = 5L,
		dispidStringToANSIBytes = 4L,
		dispidStringToUnicodeBytes = 3L,
		dispidHexToInt = 2L,
		dispidIntToHex = 1L
	};
public:
	BSTR IntToHex(ULONG val,ULONG len);
	ULONG HexToInt(LPCTSTR val);
	ULONG StringToUnicodeBytes(LPCTSTR val,BYTE** bytes);
	ULONG StringToANSIBytes(LPCTSTR val,BYTE** bytes);
	ULONG StringToUTF8Bytes(LPCTSTR val,BYTE** bytes);
	BSTR BytesToUnicodeString(BYTE* val);
	BSTR BytesToANSIString(BYTE* val);
	BSTR BytesToUTF8String(BYTE* val);
	LONG BytesToInt(BYTE* val);
	DOUBLE BytesToDouble(BYTE* val);
};


