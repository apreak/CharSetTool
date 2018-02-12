#pragma once
#include "ICharSet.h"

class CUtf8CharSet : public ICharSet
{
public:
	// 读取utf8编码的字符串
	virtual void Read(const char *pstr);

	// 以utf8编码输出字符串
	virtual void Write(char *pstr);

public:
	// 工具函数
	static std::wstring UTF8ToUnicode(const std::string& str);
};