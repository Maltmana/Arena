#pragma once

#include <string>
#include <Windows.h>

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

std::string s;

#ifdef UNICODE
std::wstring stemp = s2ws(s); // Temporary buffer is required
LPCWSTR result = stemp.c_str();
#else
LPCWSTR result = s.c_str();
#endif