

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Apr 28 23:47:08 2012
 */
/* Compiler settings for PPHT_Helper_C.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_PPHT_Helper_C,0x74BDDAB6,0x04B3,0x40F7,0x8D,0xED,0xAD,0x92,0xE5,0x4F,0x1B,0x46);


MIDL_DEFINE_GUID(IID, DIID_IonvertHelper,0xBC39A831,0xE868,0x48B6,0xAC,0xD3,0x4C,0xB0,0x34,0x1B,0x53,0x1F);


MIDL_DEFINE_GUID(CLSID, CLSID_onvertHelper,0x8B462A43,0x4FC8,0x493C,0x9E,0x11,0x41,0xCE,0x8B,0x2A,0x81,0xAB);


MIDL_DEFINE_GUID(IID, DIID_IolorHelper,0x125E83E6,0xE1D4,0x4021,0x92,0xE5,0x99,0xEC,0x29,0x75,0xEF,0x4D);


MIDL_DEFINE_GUID(CLSID, CLSID_olorHelper,0x4F3E8376,0x2863,0x461C,0x8A,0x02,0x31,0x9A,0x19,0x8A,0xBB,0xB8);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



