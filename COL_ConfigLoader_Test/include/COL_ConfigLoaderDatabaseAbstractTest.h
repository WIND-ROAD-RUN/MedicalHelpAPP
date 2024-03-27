#pragma once

#ifndef COL_CONFIGLOADERDATABASEABSTRACTTEST_H_
#define COL_CONFIGLOADERDATABASEABSTRACTTEST_H_

#include "pch.h"

#include "COL_ConfigLoaderDatabaseAbstract.h"
#include "COL_ConfigLoaderUtility.h"
#include "COL_ConfigLoader.h"

namespace HiddenButNotExposed {
	namespace COL {
		const static ConfigLoaderDatabaseAbstract::String DEFAULT_PATH = R"(G:\project\code_place\vs_code_place\MedicalHelp\COL_ConfigLoader_Test\database\datafile.xml)";
	
		class ConfigLoaderDatabaseXMLTest {
		private:
			ConfigLoaderDatabaseAbstract* m_intconfigloader{ nullptr };
		public:
			ConfigLoaderDatabaseXMLTest()
			{
				m_intconfigloader = new ConfigLoaderDatabaseXML(DEFAULT_PATH);
			}

			~ConfigLoaderDatabaseXMLTest()
			{
				delete m_intconfigloader;
			}

		public:
			ConfigLoaderDatabaseAbstract* getTestObject()
			{
				return m_intconfigloader;
			}
		};
	}
}

#endif // !COL_CONFIGLOADERDATABASEABSTRACTTEST_H_



