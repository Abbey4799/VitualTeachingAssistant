#ifndef MSP_CMN_H
#define MSP_CMN_H

#include "msp_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* C++ */
//#ifdef MSP_WCHAR_SUPPORT
/*
 * @fn		Wchar2Mbytes
 * @brief	wchar to mbytes
 *
 *  User login.
 *
 * @return	int MSPAPI				- Return 0 in success, otherwise return error code.
 * @param	const wchar_t* wcstr	- [in] Null-terminated source string(wchar_t *).
 * @param	char* mbstr				- [in] Destination string(char *).
 * @param   int len					- [in] The maximum number of bytes that can be stored in the multibyte output string.
 * @see
 */

char *Wchar2Mbytes(const wchar_t* wcstr);

wchar_t *Mbytes2Wchar(const char *mbstr);

int MSPAPI MSPLogin(const char* usr, const char* pwd, const char* params);
typedef int (MSPAPI *Proc_MSPLogin)(const char* usr, const char* pwd, const char* params);
//#ifdef MSP_WCHAR_SUPPORT
int MSPAPI MSPLoginW(const wchar_t* usr, const wchar_t* pwd, const wchar_t* params);
typedef int (MSPAPI *Proc_MSPLoginW)(const wchar_t* usr, const wchar_t* pwd, const wchar_t* params);

int MSPAPI MSPLogout();
typedef int (MSPAPI *Proc_MSPLogout)();

int MSPAPI MSPLogoutW();
typedef int (MSPAPI *Proc_MSPLogoutW)();

int MSPAPI MSPUpload( const char* dataName, const char* params, const char* dataID);
typedef int (MSPAPI* Proc_MSPUpload)( const char* dataName, const char* params, const char* dataID);

typedef int (*DownloadStatusCB)(int errorCode, long param1, const void *param2, void *userData);
typedef int (*DownloadResultCB)(const void *data, long dataLen, void *userData);
int MSPAPI MSPDownload(const char* dataName, const char* params, DownloadStatusCB statusCb, DownloadResultCB resultCb, void*userData);
typedef int (MSPAPI* Proc_MSPDownload)(const char* dataName, const char* params, DownloadStatusCB statusCb, DownloadResultCB resultCb, void*userData);
int MSPAPI MSPDownloadW(const wchar_t* wdataName, const wchar_t* wparams, DownloadStatusCB statusCb, DownloadResultCB resultCb, void*userData);
typedef int (MSPAPI* Proc_MSPDownloadW) (const wchar_t* wdataName, const wchar_t* wparams, DownloadStatusCB statusCb, DownloadResultCB resultCb, void*userData);

int MSPAPI MSPAppendData(void* data, unsigned int dataLen, unsigned int dataStatus);
typedef int (MSPAPI* Proc_MSPAppendData)(void* data, unsigned int dataLen, unsigned int dataStatus);

const char* MSPAPI MSPGetResult(unsigned int* rsltLen, int* rsltStatus, int *errorCode);
typedef const char * (MSPAPI *Proc_MSPGetResult)(unsigned int* rsltLen, int* rsltStatus, int *errorCode);

int MSPAPI MSPSetParam( const char* paramName, const char* paramValue );
typedef int (MSPAPI *Proc_MSPSetParam)(const char* paramName, const char* paramValue);

int MSPAPI MSPGetParam( const char *paramName, char *paramValue, unsigned int *valueLen );
typedef int (MSPAPI *Proc_MSPGetParam)( const char *paramName, char *paramValue, unsigned int *valueLen );

const char* MSPAPI MSPUploadData(const char* dataName, void* data, unsigned int dataLen, const char* params, int* errorCode);
typedef const char* (MSPAPI* Proc_MSPUploadData)(const char* dataName, void* data, unsigned int dataLen, const char* params, int* errorCode);

const void* MSPAPI MSPDownloadData(const char* params, unsigned int* dataLen, int* errorCode);
typedef const void* (MSPAPI* Proc_MSPDownloadData)(const char* params, unsigned int* dataLen, int* errorCode);

const void* MSPAPI MSPDownloadDataW(const wchar_t* params, unsigned int* dataLen, int* errorCode);
typedef const void* (MSPAPI* Proc_MSPDownloadDataW)(const wchar_t* params, unsigned int* dataLen, int* errorCode);

const char* MSPAPI MSPSearch(const char* params, const char* text, unsigned int* dataLen, int* errorCode);
typedef const char* (MSPAPI* Proc_MSPSearch)(const char* params, const char* text, unsigned int* dataLen, int* errorCode);

typedef int (*NLPSearchCB)(const char *sessionID, int errorCode, int status, const void* result, long rsltLen, void *userData);
const char* MSPAPI MSPNlpSearch(const char* params, const char* text, unsigned int textLen, int *errorCode, NLPSearchCB callback, void *userData);
typedef const char* (MSPAPI* Proc_MSPNlpSearch)(const char* params, const char* text, unsigned int textLen, int *errorCode, NLPSearchCB callback, void *userData);
int MSPAPI MSPNlpSchCancel(const char *sessionID, const char *hints);

typedef void ( *msp_status_ntf_handler)( int type, int status, int param1, const void *param2, void *userData );
int MSPAPI MSPRegisterNotify( msp_status_ntf_handler statusCb, void *userData );
typedef const char* (MSPAPI* Proc_MSPRegisterNotify)( msp_status_ntf_handler statusCb, void *userData );

const char* MSPAPI MSPGetVersion(const char *verName, int *errorCode);
typedef const char* (MSPAPI * Proc_MSPGetVersion)(const char *verName, int *errorCode);

#ifdef __cplusplus
} 
#endif

#endif
