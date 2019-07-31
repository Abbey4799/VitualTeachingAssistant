#ifndef IAT_RECORD_SAMPLE_H
#define IAT_RECORD_SAMPLE_H

#include <windows.h>

BOOL MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize);
int text_to_speech(const char* src_text, const char* des_path, const char* params);

#endif // IAT_RECORD_SAMPLE_H
