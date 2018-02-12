#include "Utf8CharSet.h"
#include "windows.h"

// 检查num的第n位是否为0
#define CHECK_BIT(num, n) (((unsigned long)(num) & (1UL << (n))) == 0UL)

void CUtf8CharSet::Read(const char *pstr)
{
	std::wstring wstr;
	for (int i = 0; pstr[i]; ++i)
	{
		unsigned char prefix = pstr[i];
		if(CHECK_BIT(prefix, 7))
		{
			wstr.push_back(wchar_t(prefix));
			continue;
		}

		// 最长六个字节
		int pos = 2;
		while(pos < 6 && !CHECK_BIT(prefix, 7-pos)) ++pos;

		unsigned long ulong = (unsigned char)(prefix << (pos + 1)) >> (pos + 1);
		for(int idx = 2; idx <= pos; ++idx)
		{
			ulong <<= 6;
			ulong += (unsigned char)pstr[++i] & 0x3f;
		}

		wstr.push_back(wchar_t(ulong));
	}

	wsNative = wstr;
}



void CUtf8CharSet::Write(char *pstr)
{
	// 暂不支持
}


//UTF-8 to Unicode
std::wstring CUtf8CharSet::UTF8ToUnicode(const std::string& str)
{
	int unicodeLen = ::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	if (unicodeLen <= 0)
	{
		return L"";
	}

	wchar_t* pUnicode = new  wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1)*sizeof(wchar_t));

	::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, (LPWSTR)pUnicode, unicodeLen);

	std::wstring  rt = pUnicode;

	delete[] pUnicode;
	pUnicode = NULL;

	return rt;

}