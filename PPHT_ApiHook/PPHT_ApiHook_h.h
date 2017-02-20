

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Jan 18 21:26:35 2014
 */
/* Compiler settings for PPHT_ApiHook.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __PPHT_ApiHook_h_h__
#define __PPHT_ApiHook_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHookHepler_FWD_DEFINED__
#define __IHookHepler_FWD_DEFINED__
typedef interface IHookHepler IHookHepler;
#endif 	/* __IHookHepler_FWD_DEFINED__ */


#ifndef __HookHepler_FWD_DEFINED__
#define __HookHepler_FWD_DEFINED__

#ifdef __cplusplus
typedef class HookHepler HookHepler;
#else
typedef struct HookHepler HookHepler;
#endif /* __cplusplus */

#endif 	/* __HookHepler_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __PPHT_ApiHook_LIBRARY_DEFINED__
#define __PPHT_ApiHook_LIBRARY_DEFINED__

/* library PPHT_ApiHook */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_PPHT_ApiHook;

#ifndef __IHookHepler_DISPINTERFACE_DEFINED__
#define __IHookHepler_DISPINTERFACE_DEFINED__

/* dispinterface IHookHepler */
/* [uuid] */ 


EXTERN_C const IID DIID_IHookHepler;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9DD297A7-31C2-43BE-83C6-5024790CB870")
    IHookHepler : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IHookHeplerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHookHepler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHookHepler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHookHepler * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHookHepler * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHookHepler * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHookHepler * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHookHepler * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IHookHeplerVtbl;

    interface IHookHepler
    {
        CONST_VTBL struct IHookHeplerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHookHepler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHookHepler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHookHepler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHookHepler_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHookHepler_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHookHepler_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHookHepler_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IHookHepler_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_HookHepler;

#ifdef __cplusplus

class DECLSPEC_UUID("D609900D-F747-4FB4-974D-B9C49A6FD231")
HookHepler;
#endif
#endif /* __PPHT_ApiHook_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


