#include "TraverseFolder.h"
#include <fstream>
#include "io.h"

void traverseFoler(const std::string &dir, const doSomething &func)
{
	_finddata_t fileDir;
	long lfDir;

	if((lfDir = _findfirst((dir + "*.*").c_str(), &fileDir))==-1l)
		;//printf("No file is found\n");
	else{
		;//printf("file list:\n");
		do{
			if(fileDir.name != std::string(".")
				&& fileDir.name != std::string(".."))
			{
			    if(_A_SUBDIR & fileDir.attrib)
					traverseFoler(dir + fileDir.name + "\\", func);
				else{
					//printf("%s\n", fileDir.name);
					func(dir, fileDir.name);
				}
			}
		}while( _findnext( lfDir, &fileDir ) == 0 );
	}
	_findclose(lfDir);
}



bool readFile(const std::string &file, std::string &content)
{
	bool bReadSuccess = false;
	// read a file into memory

	std::ifstream is (file, std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg (0, is.end);
		int length = is.tellg();
		is.seekg (0, is.beg);

		char * buffer = new char [length];
		// read data as a block:
		is.read (buffer,length);

		if (is)
			bReadSuccess = true; //std::cout << "all characters read successfully.";
		else
			bReadSuccess = false; //std::cout << "error: only " << is.gcount() << " could be read";
		is.close();

		// ...buffer contains the entire file...
		content = buffer;
		delete[] buffer;
	}

	return bReadSuccess;
}
