#pragma once
#include "ICharSet.h"

class CUtf8CharSet : public ICharSet
{
public:
	// ��ȡutf8������ַ���
	virtual void Read(const char *pstr);

	// ��utf8��������ַ���
	virtual void Write(char *pstr);

public:
	// ���ߺ���
	static std::wstring UTF8ToUnicode(const std::string& str);
};