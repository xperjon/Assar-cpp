// stdafx.cpp : source file that includes just the standard includes
//	ASSAR.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information


#include "stdafx.h"

void HookTrace(const wchar_t* format, ...)
{
	const int TraceBufferSize = 1024;
	wchar_t buffer[TraceBufferSize];

	va_list argptr; va_start(argptr, format);
	vswprintf_s(buffer, format, argptr);
	va_end(argptr);

	::OutputDebugString(buffer);
}

void HookTrace(const char* format, ...)
{
	const int TraceBufferSize = 1024;
	char szBuf[TraceBufferSize];

	va_list argptr; va_start(argptr, format);
	vsprintf_s(szBuf, format, argptr);
	va_end(argptr);

	wchar_t wszBuf[TraceBufferSize] = { '\0' };

	if (MultiByteToWideChar(CP_ACP, 0, szBuf, -1, wszBuf, TraceBufferSize) == 0)
	{
		return;
	}

	::OutputDebugString(wszBuf);
}