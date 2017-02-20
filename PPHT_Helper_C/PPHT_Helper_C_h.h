

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Feb 12 22:36:08 2014
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

#ifndef __IConvertHelper_FWD_DEFINED__
#define __IConvertHelper_FWD_DEFINED__
typedef interface IConvertHelper IConvertHelper;
#endif 	/* __IConvertHelper_FWD_DEFINED__ */


#ifndef __ConvertHelper_FWD_DEFINED__
#define __ConvertHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class ConvertHelper ConvertHelper;
#else
typedef struct ConvertHelper ConvertHelper;
#endif /* __cplusplus */

#endif 	/* __ConvertHelper_FWD_DEFINED__ */


#ifndef __IColorHelper_FWD_DEFINED__
#define __IColorHelper_FWD_DEFINED__
typedef interface IColorHelper IColorHelper;
#endif 	/* __IColorHelper_FWD_DEFINED__ */


#ifndef __ColorHelper_FWD_DEFINED__
#define __ColorHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class ColorHelper ColorHelper;
#else
typedef struct ColorHelper ColorHelper;
#endif /* __cplusplus */

#endif 	/* __ColorHelper_FWD_DEFINED__ */


#ifndef __IControlHelper_FWD_DEFINED__
#define __IControlHelper_FWD_DEFINED__
typedef interface IControlHelper IControlHelper;
#endif 	/* __IControlHelper_FWD_DEFINED__ */


#ifndef __ControlHelper_FWD_DEFINED__
#define __ControlHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class ControlHelper ControlHelper;
#else
typedef struct ControlHelper ControlHelper;
#endif /* __cplusplus */

#endif 	/* __ControlHelper_FWD_DEFINED__ */


#ifndef __IMemoryHelper_FWD_DEFINED__
#define __IMemoryHelper_FWD_DEFINED__
typedef interface IMemoryHelper IMemoryHelper;
#endif 	/* __IMemoryHelper_FWD_DEFINED__ */


#ifndef __MemoryHelper_FWD_DEFINED__
#define __MemoryHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class MemoryHelper MemoryHelper;
#else
typedef struct MemoryHelper MemoryHelper;
#endif /* __cplusplus */

#endif 	/* __MemoryHelper_FWD_DEFINED__ */


#ifndef __IFileHelper_FWD_DEFINED__
#define __IFileHelper_FWD_DEFINED__
typedef interface IFileHelper IFileHelper;
#endif 	/* __IFileHelper_FWD_DEFINED__ */


#ifndef __FileHelper_FWD_DEFINED__
#define __FileHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileHelper FileHelper;
#else
typedef struct FileHelper FileHelper;
#endif /* __cplusplus */

#endif 	/* __FileHelper_FWD_DEFINED__ */


#ifndef __IXmlHelper_FWD_DEFINED__
#define __IXmlHelper_FWD_DEFINED__
typedef interface IXmlHelper IXmlHelper;
#endif 	/* __IXmlHelper_FWD_DEFINED__ */


#ifndef __XmlHelper_FWD_DEFINED__
#define __XmlHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class XmlHelper XmlHelper;
#else
typedef struct XmlHelper XmlHelper;
#endif /* __cplusplus */

#endif 	/* __XmlHelper_FWD_DEFINED__ */


#ifndef __IStringHelper_FWD_DEFINED__
#define __IStringHelper_FWD_DEFINED__
typedef interface IStringHelper IStringHelper;
#endif 	/* __IStringHelper_FWD_DEFINED__ */


#ifndef __StringHelper_FWD_DEFINED__
#define __StringHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class StringHelper StringHelper;
#else
typedef struct StringHelper StringHelper;
#endif /* __cplusplus */

#endif 	/* __StringHelper_FWD_DEFINED__ */


#ifndef __IWindowHelper_FWD_DEFINED__
#define __IWindowHelper_FWD_DEFINED__
typedef interface IWindowHelper IWindowHelper;
#endif 	/* __IWindowHelper_FWD_DEFINED__ */


#ifndef __WindowHelper_FWD_DEFINED__
#define __WindowHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class WindowHelper WindowHelper;
#else
typedef struct WindowHelper WindowHelper;
#endif /* __cplusplus */

#endif 	/* __WindowHelper_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __PPHT_Helper_C_LIBRARY_DEFINED__
#define __PPHT_Helper_C_LIBRARY_DEFINED__

/* library PPHT_Helper_C */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_PPHT_Helper_C;

#ifndef __IConvertHelper_DISPINTERFACE_DEFINED__
#define __IConvertHelper_DISPINTERFACE_DEFINED__

/* dispinterface IConvertHelper */
/* [uuid] */ 


EXTERN_C const IID DIID_IConvertHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BC39A831-E868-48B6-ACD3-4CB0341B531F")
    IConvertHelper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IConvertHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConvertHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConvertHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConvertHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IConvertHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IConvertHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IConvertHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IConvertHelper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IConvertHelperVtbl;

    interface IConvertHelper
    {
        CONST_VTBL struct IConvertHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConvertHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IConvertHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IConvertHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IConvertHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IConvertHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IConvertHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IConvertHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IConvertHelper_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ConvertHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("8B462A43-4FC8-493C-9E11-41CE8B2A81AB")
ConvertHelper;
#endif

#ifndef __IColorHelper_DISPINTERFACE_DEFINED__
#define __IColorHelper_DISPINTERFACE_DEFINED__

/* dispinterface IColorHelper */
/* [uuid] */ 


EXTERN_C const IID DIID_IColorHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("125E83E6-E1D4-4021-92E5-99EC2975EF4D")
    IColorHelper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IColorHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IColorHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IColorHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IColorHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IColorHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IColorHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IColorHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IColorHelper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IColorHelperVtbl;

    interface IColorHelper
    {
        CONST_VTBL struct IColorHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IColorHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IColorHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IColorHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IColorHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IColorHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IColorHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IColorHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IColorHelper_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ColorHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("4F3E8376-2863-461C-8A02-319A198ABBB8")
ColorHelper;
#endif

#ifndef __IControlHelper_DISPINTERFACE_DEFINED__
#define __IControlHelper_DISPINTERFACE_DEFINED__

/* dispinterface IControlHelper */
/* [uuid] */ 


EXTERN_C const IID DIID_IControlHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9C3DC0C5-927B-400E-81EC-2A7BFAB02B62")
    IControlHelper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IControlHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IControlHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IControlHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IControlHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IControlHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IControlHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IControlHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IControlHelper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IControlHelperVtbl;

    interface IControlHelper
    {
        CONST_VTBL struct IControlHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IControlHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IControlHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IControlHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IControlHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IControlHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IControlHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IControlHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IControlHelper_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ControlHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("D815E262-ABFA-4437-BFBB-EFB316F4A31E")
ControlHelper;
#endif

#ifndef __IMemoryHelper_DISPINTERFACE_DEFINED__
#define __IMemoryHelper_DISPINTERFACE_DEFINED__

/* dispinterface IMemoryHelper */
/* [uuid] */ 


EXTERN_C const IID DIID_IMemoryHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DBA955B9-0175-4087-A36B-D47D43FD7DA9")
    IMemoryHelper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMemoryHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMemoryHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMemoryHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMemoryHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMemoryHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMemoryHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMemoryHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMemoryHelper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IMemoryHelperVtbl;

    interface IMemoryHelper
    {
        CONST_VTBL struct IMemoryHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMemoryHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMemoryHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMemoryHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMemoryHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMemoryHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMemoryHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMemoryHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMemoryHelper_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MemoryHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("45CB3674-3B8B-4F59-8EF1-DA1566AB5B3B")
MemoryHelper;
#endif

#ifndef __IFileHelper_DISPINTERFACE_DEFINED__
#define __IFileHelper_DISPINTERFACE_DEFINED__

/* dispinterface IFileHelper */
/* [uuid] */ 


EXTERN_C const IID DIID_IFileHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F6C73760-EAA2-4525-A85B-7C56E370F859")
    IFileHelper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFileHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileHelper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFileHelperVtbl;

    interface IFileHelper
    {
        CONST_VTBL struct IFileHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFileHelper_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FileHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("0E270940-C4D7-4F5D-98A2-3FB00F0080F2")
FileHelper;
#endif

#ifndef __IXmlHelper_DISPINTERFACE_DEFINED__
#define __IXmlHelper_DISPINTERFACE_DEFINED__

/* dispinterface IXmlHelper */
/* [uuid] */ 


EXTERN_C const IID DIID_IXmlHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C620CE0F-8578-4405-805E-A8AEFFE07F87")
    IXmlHelper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IXmlHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXmlHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXmlHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXmlHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXmlHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXmlHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXmlHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXmlHelper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IXmlHelperVtbl;

    interface IXmlHelper
    {
        CONST_VTBL struct IXmlHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXmlHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXmlHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXmlHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXmlHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IXmlHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IXmlHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IXmlHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IXmlHelper_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_XmlHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("347858BE-4736-4FA7-9B0C-E6F01FCDE9D6")
XmlHelper;
#endif

#ifndef __IStringHelper_DISPINTERFACE_DEFINED__
#define __IStringHelper_DISPINTERFACE_DEFINED__

/* dispinterface IStringHelper */
/* [uuid] */ 


EXTERN_C const IID DIID_IStringHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("59408ABD-8597-4678-80EE-B359EE192984")
    IStringHelper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IStringHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStringHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStringHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStringHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IStringHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IStringHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IStringHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IStringHelper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IStringHelperVtbl;

    interface IStringHelper
    {
        CONST_VTBL struct IStringHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStringHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStringHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStringHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStringHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IStringHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IStringHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IStringHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IStringHelper_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_StringHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("A1F09381-8B0A-4587-B8FF-2B490EA8E437")
StringHelper;
#endif

#ifndef __IWindowHelper_DISPINTERFACE_DEFINED__
#define __IWindowHelper_DISPINTERFACE_DEFINED__

/* dispinterface IWindowHelper */
/* [uuid] */ 


EXTERN_C const IID DIID_IWindowHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0F49A766-672F-4D97-BE2A-487D32C569EE")
    IWindowHelper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IWindowHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWindowHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWindowHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWindowHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWindowHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWindowHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWindowHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWindowHelper * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IWindowHelperVtbl;

    interface IWindowHelper
    {
        CONST_VTBL struct IWindowHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWindowHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWindowHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWindowHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWindowHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWindowHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWindowHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWindowHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IWindowHelper_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_WindowHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("2539E6F3-C471-4340-8AE1-914269F7BE66")
WindowHelper;
#endif
#endif /* __PPHT_Helper_C_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


