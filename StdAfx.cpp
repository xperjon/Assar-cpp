// stdafx.cpp : source file that includes just the standard includes
//	ASSAR.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information


#include "stdafx.h"

CString GetUserHomeDir()
{
	TCHAR szHomeDirBuf[MAX_PATH] = { 0 };

	// We need a process with query permission set
	HANDLE hToken = 0;
	VERIFY(OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken));

	// Returns a path like C:/Documents and Settings/nibu if my user name is nibu
	DWORD BufSize = MAX_PATH;
	VERIFY(GetUserProfileDirectory(hToken, szHomeDirBuf, &BufSize));

	// Close handle opened via OpenProcessToken
	CloseHandle(hToken);
	return CString(szHomeDirBuf);
}// End GetUserHomeDir