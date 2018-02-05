#pragma once
#include <string>

typedef void (*doSomething)(const std::string &folderName, const std::string &fileName);

// 遍历文件夹dir，并对其中每个文件调用func函数
void traverseFoler(const std::string &dir, const doSomething &func);