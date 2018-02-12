#include <iostream>
#include <string>
#include <sstream>
#include "windows.h"
#include "TraverseFolder.h"
#include "Utf8CharSet.h"

using namespace std;


void ReplaceName(const std::string &folderName, const std::string &fileName)
{
	CUtf8CharSet utf8Tool;
	utf8Tool.Read(fileName.c_str());

	std::wstring wsNative;
	utf8Tool.WriteNative(wsNative);

	std::string sPath = utf8Tool.ws2s(wsNative);

	std::string oldFileName = folderName + fileName;
	std::string newFileName = folderName + sPath;
	MoveFileA(oldFileName.c_str(), newFileName.c_str());

	cout << sPath << endl;

	// 如果输出宽字符串需要进行转换
	//auto curLoc = wcout.imbue(std::locale("chs"));
	//wcout << wsNative << endl;
	//wcout.imbue(curLoc);
}


// 使用C++的locale来进行无缝的字符集转换
void ReplaceNameVS2015(const std::string &folderName, const std::string &fileName)
{
	string sPath;
	std::istringstream is(fileName);
	is.imbue(std::locale("utf8")); // VS2015上名字不一定是“utf8”

	std::string oldFileName = folderName + fileName;
	std::string newFileName = folderName + sPath;
	MoveFileA(oldFileName.c_str(), newFileName.c_str());

	cout << sPath << endl;
}



int main()
{
	string dir;
	std::getline(cin, dir);

	if(!dir.empty() && *(dir.end() -1)!= '\\'){
		dir.push_back('\\');
	}

	//char lpPath[MAX_PATH] = {};
	//strcpy(lpPath, dir.c_str());

	traverseFoler(dir, &ReplaceName);

	cin.get();
	return 0;
}









// 测试读取UTF-8的文档
void ReadUtf8File()
{
	cout << "请输入utf8文件名：";
	string filePath;
	getline(cin, filePath);
	
	string fileContent;
	readFile(filePath, fileContent);

	CUtf8CharSet utf8Tool;
	utf8Tool.Read(fileContent.c_str());
	
	wstring wsNative;
	utf8Tool.WriteNative(wsNative);

	cout << utf8Tool.ws2s(wsNative) << endl;
}