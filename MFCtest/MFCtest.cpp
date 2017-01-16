// MFCtest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MFCtest.h"
#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	ULONG hwnd, x, y, width, height, beginSize, endSize, color, offset, iscut;
	LPCTSTR direction;
	hwnd=199216;
	x=148, y=68, width=200, height=12, direction=L"y", beginSize=10, endSize=5, color=0xF7FFFF, offset=10,iscut=1;
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
			_tprintf(_T("%d,%d,%d|"),bytes[(j+i*bmax)*4],bytes[(j+i*bmax)*4+1],bytes[(j+i*bmax)*4+2]);
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
	return 0;
}
