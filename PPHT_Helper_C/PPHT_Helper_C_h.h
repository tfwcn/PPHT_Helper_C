

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __PPHT_Helper_C_h_h__
#define __PPHT_Helper_C_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IonvertHelper_FWD_DEFINED__
#define __IonvertHelper_FWD_DEFINED__
typedef interface IonvertHelper IonvertHelper;
#endif 	/* __IonvertHelper_FWD_DEFINED__ */


#ifndef __onvertHelper_FWD_DEFINED__
#define __onvertHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class onvertHelper onvertHelper;
#else
typedef struct onvertHelper onvertHelper;
#endif /* __cplusplus */

#endif 	/* __onvertHelper_FWD_DEFINED__ */


#ifndef __IolorHelper_FWD_DEFINED__
#define __IolorHelper_FWD_DEFINED__
typedef interface IolorHelper IolorHelper;
#endif 	/* __IolorHelper_FWD_DEFINED__ */


#ifndef __olorHelper_FWD_DEFINED__
#define __olorHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class olorHelper olorHelper;
#else
typedef struct olorHelper olorHelper;
#endif /* __cplusplus */

#endif 	/* __olorHelper_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __PPHT_Helper_C_LIBRARY_DEFINED__
#define __PPHT_Helper_C_LIBRARY_DEFINED__

/* library PPHT_Helper_C */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_PPHT_Helper_C;

#ifndef __IonvertHelper_DISPINTERFACE_DEFINED__
#define __IonvertHelper_DISPINTERFACE_DEFINED__

/* dispinterface IonvertHelper */
/* [uuid] */ 


EXTERN_C const IID DIID_IonvertHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BC39A831-E868-48B6-ACD3-4CB0341B531F")
    IonvertHelper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IonvertHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IonvertHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IonvertHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IonvertHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IonvertHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IonvertHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IonvertHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IonvertHelper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IonvertHelperVtbl;

    interface IonvertHelper
    {
        CONST_VTBL struct IonvertHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IonvertHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IonvertHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IonvertHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IonvertHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IonvertHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IonvertHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IonvertHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IonvertHelper_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_onvertHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("8B462A43-4FC8-493C-9E11-41CE8B2A81AB")
onvertHelper;
#endif

#ifndef __IolorHelper_DISPINTERFACE_DEFINED__
#define __IolorHelper_DISPINTERFACE_DEFINED__

/* dispinterface IolorHelper */
/* [uuid] */ 


EXTERN_C const IID DIID_IolorHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("125E83E6-E1D4-4021-92E5-99EC2975EF4D")
    IolorHelper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IolorHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IolorHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IolorHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IolorHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IolorHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IolorHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IolorHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IolorHelper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IolorHelperVtbl;

    interface IolorHelper
    {
        CONST_VTBL struct IolorHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IolorHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IolorHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IolorHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IolorHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IolorHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IolorHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IolorHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IolorHelper_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_olorHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("4F3E8376-2863-461C-8A02-319A198ABBB8")
olorHelper;
#endif
#endif /* __PPHT_Helper_C_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


