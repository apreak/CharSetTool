#pragma once
#include <string>

typedef void (*doSomething)(const std::string &folderName, const std::string &fileName);

// �����ļ���dir����������ÿ���ļ�����func����
void traverseFoler(const std::string &dir, const doSomething &func);