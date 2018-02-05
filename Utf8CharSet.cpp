#include "Utf8CharSet.h"

// 检查num的第n位是否为0
#define CHECK_BIT(num, n) ((unsigned long(num) & (1UL << (n))) == 0UL)

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

		unsigned long ulong = unsigned char(prefix << (pos + 1)) >> (pos + 1);
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