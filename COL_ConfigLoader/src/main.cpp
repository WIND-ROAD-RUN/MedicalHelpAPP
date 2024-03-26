#include<iostream>
#include<COL_ConfigLoaderDatabaseXML.h>

using namespace HiddenButNotExposed;
using namespace COL;


int main()
{
	ConfigLoaderDatabaseXML* xmlLoader;
	xmlLoader = new ConfigLoaderDatabaseXML(R"(.\database\XMLFile.xml)");
	xmlLoader->iniCom();
	xmlLoader->desCom();
	
	return 0;
}