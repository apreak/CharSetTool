#include <iostream>
#include <string>
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

	cout << newFileName << endl;
}

int main()
{
	string dir;
	std::getline(cin, dir);

	if(!dir.empty() && dir.back() != '\\'){
		dir.push_back('\\');
	}

	//char lpPath[MAX_PATH] = {};
	//strcpy(lpPath, dir.c_str());

	traverseFoler(dir, &ReplaceName);

	cin.get();
	return 0;
}