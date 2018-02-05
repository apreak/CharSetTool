#pragma once
#include <string>

class ICharSet
{
public:
	// 读取指定字符编码的字符串
	virtual void Read(const char *pstr) = 0;
	// 以指定字符编码输出字符串
	virtual void Write(char *pstr) = 0;

	// 默认格式：指当前C++流操作使用的格式
	// 读取默认格式字符串
	void ReadNative(const std::wstring &wstr);
	// 输出默认格式字符串
	void WriteNative(std::wstring &wstr);

	// 宽窄字符串转换函数
	static std::string ws2s(const std::wstring &ws);
	static std::wstring s2ws(const std::string &s);

protected:
	std::wstring wsNative;
};


// 一般使用方式：
// 1、Read -> WriteNative
// 2、ReadNative -> Write
