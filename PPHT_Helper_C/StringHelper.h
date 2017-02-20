#pragma once


// StringHelper

class StringHelper : public CWnd
{
	DECLARE_DYNCREATE(StringHelper)

public:
	StringHelper();
	virtual ~StringHelper();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(StringHelper)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	enum 
	{
		dispidRegexFindSubString = 17L,
		dispidRegexLastIndexOf = 16L,
		dispidRegexIndexOf = 15L,
		dispidRegexReplace = 14L,
		dispidRegexMatch = 13L,
		dispidToUpper = 12L,
		dispidToLower = 11L,
		dispidLastIndexOf = 10L,
		dispidIndexOf = 9L,
		dispidReplace = 8L,
		dispidRTrim = 7L,
		dispidLTrim = 6L,
		dispidTrim = 5L,
		dispidRight = 4L,
		dispidLeft = 3L,
		dispidSubString = 2L,
		dispidLength = 1L
	};

public:
	ULONG Length(LPCTSTR val);
	BSTR SubString(LPCTSTR val, ULONG start, LONG len);
	BSTR Left(LPCTSTR val, ULONG len);
	BSTR Right(LPCTSTR val, ULONG len);
	BSTR Trim(LPCTSTR val);
	BSTR LTrim(LPCTSTR val);
	BSTR RTrim(LPCTSTR val);
	BSTR Replace(LPCTSTR val, LPCTSTR oldVal, LPCTSTR newVal);
	LONG IndexOf(LPCTSTR val, LPCTSTR selectVal);
	LONG LastIndexOf(LPCTSTR val, LPCTSTR selectVal);
	BSTR ToLower(LPCTSTR val);
	BSTR ToUpper(LPCTSTR val);
	LONG RegexMatch(LPCTSTR str, LPCTSTR regex);
	BSTR RegexReplace(LPCTSTR str, LPCTSTR newVal, LPCTSTR regex);
	LONG RegexIndexOf(LPCTSTR str, LPCTSTR regex);
	LONG RegexLastIndexOf(LPCTSTR str, LPCTSTR regex);
	BSTR RegexFindSubString(LPCTSTR str, LPCTSTR regex);
};


