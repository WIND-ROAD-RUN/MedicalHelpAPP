#include<iostream>
#include<COL_ConfigLoaderDatabaseXML.h>
#include<COL_ConfigLoader.h>

using namespace HiddenButNotExposed;
using namespace COL;


int main()
{
	ConfigLoader* xmlLoader;
	std::string DEFAULT_PATH = R"(C:\Users\86158\Desktop\Repo\COL_ConfigLoader\database\XMLFile.xml)";
	xmlLoader = ConfigLoader::getInstance(
		new HiddenButNotExposed::COL::ConfigLoaderDatabaseXML(DEFAULT_PATH));
	xmlLoader->iniCom();
	xmlLoader->addConfig("CHN", "china");
	xmlLoader->saveData();
	xmlLoader->desCom();
	
	return 0;
}