#pragma once
#include "ICharSet.h"

class CUtf8CharSet : public ICharSet
{
public:
	// ¶ÁÈ¡utf8±àÂëµÄ×Ö·û´®
	virtual void Read(const char *pstr);

	// ÒÔutf8±àÂëÊä³ö×Ö·û´®
	virtual void Write(char *pstr);
};