#include "TraverseFolder.h"
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
				if(_A_SUBDIR & fileDir.attrib)
					traverseFoler(dir + fileDir.name + "\\", func);
				else{
					//printf("%s\n", fileDir.name);
					func(dir, fileDir.name);
				}
		}while( _findnext( lfDir, &fileDir ) == 0 );
	}
	_findclose(lfDir);
}
