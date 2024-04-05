#include<iostream>
#include<COL_ConfigLoaderDatabaseXML.h>
#include<COL_ConfigLoader.h>

using namespace HiddenButNotExposed;
using namespace COL;


int main()
{
	ConfigLoader* xmlLoader;
	xmlLoader = ConfigLoader::getInstance();
	xmlLoader->iniCom();
	xmlLoader->desCom();
	
	return 0;
}