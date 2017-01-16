// ColorHelper.cpp : 实现文件
//

#include "stdafx.h"
#include "PPHT_Helper_C.h"
#include "ColorHelper.h"
#include <atlimage.h>


// ColorHelper

IMPLEMENT_DYNCREATE(ColorHelper, CWnd)

ColorHelper::ColorHelper()
{

	EnableAutomation();
	
	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	
	AfxOleLockApp();
}

ColorHelper::~ColorHelper()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	
	AfxOleUnlockApp();
}

void ColorHelper::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(ColorHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(ColorHelper, CWnd)
	DISP_FUNCTION_ID(ColorHelper, "GetPixelColor", dispidGetPixelColor, GetPixelColor, VT_UI4, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ColorHelper, "CheckColor", dispidCheckColor, CheckColor, VT_I4, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ColorHelper, "CheckColorOfPosition", dispidCheckColorOfPosition, CheckColorOfPosition, VT_I4, VTS_UI4 VTS_I4 VTS_I4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ColorHelper, "FindPic", dispidFindPic, FindPic, VT_BSTR, VTS_UI4 VTS_BSTR VTS_I4 VTS_I4 VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ColorHelper, "GetColorStr", dispidGetColorStr, GetColorStr, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(ColorHelper, "GetColorPositions", dispidGetColorPositions, GetColorPositions, VT_BSTR, VTS_UI4 VTS_I4 VTS_I4 VTS_UI4 VTS_UI4 VTS_BSTR VTS_UI4 VTS_UI4 VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ColorHelper, "CheckIn", dispidCheckIn, CheckIn, VT_I4, VTS_BSTR VTS_BSTR)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IolorHelper 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {125E83E6-E1D4-4021-92E5-99EC2975EF4D}
static const IID IID_IolorHelper =
{ 0x125E83E6, 0xE1D4, 0x4021, { 0x92, 0xE5, 0x99, 0xEC, 0x29, 0x75, 0xEF, 0x4D } };

BEGIN_INTERFACE_MAP(ColorHelper, CWnd)
	INTERFACE_PART(ColorHelper, IID_IolorHelper, Dispatch)
END_INTERFACE_MAP()

// {4F3E8376-2863-461C-8A02-319A198ABBB8}
IMPLEMENT_OLECREATE(ColorHelper, "PPHT_Helper_C.ColorHelper", 0x4f3e8376, 0x2863, 0x461c, 0x8a, 0x2, 0x31, 0x9a, 0x19, 0x8a, 0xbb, 0xb8)


// ColorHelper 消息处理程序

ULONG ColorHelper::GetPixelColor(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HDC hdc=::GetDC((HWND)hwnd);
	ULONG color=::GetPixel(hdc,x,y);
	::ReleaseDC((HWND)hwnd,hdc);
	return color;
}


LONG ColorHelper::CheckColor(ULONG color1, ULONG color2, ULONG offset)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	byte r1,g1,b1;
	byte r2,g2,b2;
	r1 = (color1 & 0xFF0000) >> 16;
	g1 = (color1 & 0xFF00) >> 8;
	b1 = color1 & 0xFF;
	r2 = (color2 & 0xFF0000) >> 16;
	g2 = (color2 & 0xFF00) >> 8;
	b2 = color2 & 0xFF;
	if (offset<0)
	{
		offset=0;
	}
	if (abs(r1-r2)>offset || abs(g1-g2)>offset || abs(b1-b2)>offset)
	{
		return 0;
	}
	else if (r1==r2 && g1==g2 && b1==b2)
	{
		return 1;
	}
	return 2;
}


LONG ColorHelper::CheckColorOfPosition(ULONG hwnd, LONG x, LONG y, ULONG color, ULONG offset)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return CheckColor(GetPixelColor(hwnd, x, y), color, offset);
}


BSTR ColorHelper::FindPic(ULONG hwnd, LPCTSTR path, LONG x, LONG y, ULONG width, ULONG height, ULONG offset)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString strResult;
	strResult="";
	CWnd *cwnd;
	if (hwnd==0)
	{
		cwnd=CWnd::GetDesktopWindow();
	} 
	else
	{
		cwnd=CWnd::FromHandle((HWND)hwnd);
	}
	if (cwnd!=NULL)
	{
		//获取截图数据
		CDC *cdc=cwnd->GetDC();
		CDC subCdc;
		subCdc.CreateCompatibleDC(cdc);
		CBitmap subBit;
		subBit.CreateCompatibleBitmap(cdc,width,height);
		subCdc.SelectObject(&subBit);
		subCdc.BitBlt(0,0,width,height,cdc,x,y,SRCCOPY);
		BYTE *subBits=new BYTE[width*height*4];//截图数组
		BITMAPINFO bitInfo;
		bitInfo.bmiHeader.biBitCount=32;
		bitInfo.bmiHeader.biCompression=BI_RGB;
		bitInfo.bmiHeader.biPlanes=1;
		bitInfo.bmiHeader.biSize=sizeof(bitInfo.bmiHeader);
		bitInfo.bmiHeader.biWidth=width;
		bitInfo.bmiHeader.biHeight=-height;
		GetDIBits(subCdc.GetSafeHdc(),(HBITMAP)subBit.GetSafeHandle(),0,height,subBits,&bitInfo,DIB_RGB_COLORS);
		subBit.DeleteObject();
		subCdc.DeleteDC();
		cwnd->ReleaseDC(cdc);

		LONG retX,retY,hasPic;
		retX=0,retY=0,hasPic=0;
		ULONG picW,picH,startX,startY;
		//获取图片数据
		HBITMAP hbit=(HBITMAP)LoadImage(NULL,path,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		CBitmap *picCbit=CBitmap::FromHandle(hbit);
		BITMAP picBit;
		picCbit->GetBitmap(&picBit);
		BYTE *picBits=new BYTE[picBit.bmWidth*picBit.bmHeight*(int)(picBit.bmWidthBytes/picBit.bmWidth)];//图片数组
		BITMAPINFO picBitInfo;
		picBitInfo.bmiHeader.biBitCount=picBit.bmBitsPixel;
		picBitInfo.bmiHeader.biCompression=picBit.bmType;
		picBitInfo.bmiHeader.biPlanes=picBit.bmPlanes;
		picBitInfo.bmiHeader.biSize=sizeof(picBitInfo.bmiHeader);
		picBitInfo.bmiHeader.biWidth=picBit.bmWidth;
		picBitInfo.bmiHeader.biHeight=-picBit.bmHeight;
		picW=picBit.bmWidth;
		picH=picBit.bmHeight;
		CDC picCdc;
		picCdc.CreateCompatibleDC(0);
		picCdc.SelectObject(picCbit);
		GetDIBits(picCdc.GetSafeHdc(),(HBITMAP)picCbit->GetSafeHandle() ,0,picBit.bmHeight,picBits,&picBitInfo,DIB_RGB_COLORS);
		picCbit->DeleteObject();
		picCdc.DeleteDC();

		for (int i=0;i<picH;i++)
		{
			for (int j=0;j<picW;j++)
			{
				if (!(picBits[(j+i*picW)*4]==0xFF && picBits[(j+i*picW)*4+1]==0x0 && picBits[(j+i*picW)*4+2]==0xFF))
				{
					startX=j;
					startY=i;
					goto findPic;
				}
			}
		}
findPic:;
		for (int i=0;i<height-picH+1;i++)
		{
			for (int j=0;j<width-picW+1;j++)
			{
				for (int k=startY;k<picH;k++)
				{
					for (int l=startX;l<picW;l++)
					{
						if (!(picBits[(l+k*picW)*4]==0xFF && picBits[(l+k*picW)*4+1]==0x0 && picBits[(l+k*picW)*4+2]==0xFF) &&
							(abs(picBits[(l+k*picW)*4]-subBits[((j+l)+(i+k)*width)*4])>offset ||
							abs(picBits[(l+k*picW)*4+1]-subBits[((j+l)+(i+k)*width)*4+1])>offset ||
							abs(picBits[(l+k*picW)*4+2]-subBits[((j+l)+(i+k)*width)*4+2])>offset))
						{
							retX=x+j;
							retY=y+i;
							goto noPic;
						}else if (k==picH-1 && l==picW-1)
						{
							hasPic=1;
							goto hPic;
						}
					}
				}
noPic:;
			}
		}
hPic:;
		if (hasPic==1)
		{
			strResult.Format(L"%d|%d",retX,retY);
		}
	}
	return strResult.AllocSysString();
}


BSTR ColorHelper::GetColorStr(ULONG color)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	
	strResult=convertHelper.IntToHex(color,6);

	return strResult.AllocSysString();
}


BSTR ColorHelper::GetColorPositions(ULONG hwnd, LONG x, LONG y, ULONG width, ULONG height, LPCTSTR direction, ULONG beginSize, ULONG endSize, ULONG color, ULONG offset, ULONG iscut)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	HDC hdc=::GetDC((HWND)hwnd);
	HDC subhdc=::CreateCompatibleDC(hdc);
	HBITMAP hbit=::CreateCompatibleBitmap(hdc,width,height);
	::SelectObject(subhdc,hbit);
	::BitBlt(subhdc,0,0,width,height,hdc,x,y,SRCCOPY);
	BYTE *bytes=new BYTE[width*height*4];
	BITMAPINFO bitinfo;
	bitinfo.bmiHeader.biBitCount=32;
	bitinfo.bmiHeader.biCompression=BI_RGB;
	bitinfo.bmiHeader.biPlanes=1;
	bitinfo.bmiHeader.biSize=sizeof(bitinfo.bmiHeader);
	bitinfo.bmiHeader.biWidth=width;
	bitinfo.bmiHeader.biHeight=-height;
	::GetDIBits(subhdc,hbit,0,height,bytes,&bitinfo,DIB_RGB_COLORS);
	::DeleteObject(hbit);
	::DeleteDC(subhdc);
	::ReleaseDC((HWND)hwnd,hdc);

	byte r1,g1,b1;
	r1 = (color & 0xFF0000) >> 16;
	g1 = (color & 0xFF00) >> 8;
	b1 = color & 0xFF;
	int amax, bmax, nc, nc2, isbegin;
	nc = 0;
	nc2 = 0;
	isbegin = 0;
	if (wcscmp(direction,L"y")==0)
	{
		amax = width;
		bmax = height;
	}
	else
	{
		amax = height;
		bmax = width;
	}

	for (int i=0;i<amax;i++)
	{
		nc = 0;
		for (int j=0;j<bmax;j++)
		{
			if (abs(bytes[(j+i*bmax)*4]-r1)<=offset && abs(bytes[(j+i*bmax)*4+1]-g1)<=offset && abs(bytes[(j+i*bmax)*4+2]-b1)<=offset && wcscmp(direction,L"y")!=0)
			{
				isbegin = 1;
				strResult += "1";
				nc = 1;
			}
			else if (abs(bytes[(j*amax+i)*4]-r1)<=offset && abs(bytes[(j*amax+i)*4+1]-g1)<=offset && abs(bytes[(j*amax+i)*4+2]-b1)<=offset && wcscmp(direction,L"y")==0)
			{
				isbegin = 1;
				strResult += "1";
				nc = 1;
			}
			else
			{
				strResult += "0";
			}
		}
		strResult += "|";
		if (isbegin==0 && iscut>0)
		{
			strResult="";
		}
		if (nc==0)
		{
			nc2+=1;
		} 
		else
		{
			nc2=0;
		}
		if (isbegin==0 && i==beginSize && iscut>0)
		{
			break;
		}
		if (isbegin==1 && nc2==endSize && iscut>0)
		{
			strResult=strResult.Left(strResult.GetLength()-(bmax+1)*endSize);
			break;
		}
	}
	if (strResult.GetLength()>0)
	{
		strResult=strResult.Left(strResult.GetLength()-1);
	}
	return strResult.AllocSysString();
}


LONG ColorHelper::CheckIn(LPCTSTR points1, LPCTSTR points2)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码

	return 0;
}
