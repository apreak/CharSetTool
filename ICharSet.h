#pragma once
#include <string>

class ICharSet
{
public:
	// ��ȡָ���ַ�������ַ���
	virtual void Read(const char *pstr) = 0;
	// ��ָ���ַ���������ַ���
	virtual void Write(char *pstr) = 0;

	// Ĭ�ϸ�ʽ��ָ��ǰC++������ʹ�õĸ�ʽ
	// ��ȡĬ�ϸ�ʽ�ַ���
	void ReadNative(const std::wstring &wstr);
	// ���Ĭ�ϸ�ʽ�ַ���
	void WriteNative(std::wstring &wstr);

	// ��խ�ַ���ת������
	static std::string ws2s(const std::wstring &ws);
	static std::wstring s2ws(const std::string &s);

protected:
	std::wstring wsNative;
};


// һ��ʹ�÷�ʽ��
// 1��Read -> WriteNative
// 2��ReadNative -> Write
