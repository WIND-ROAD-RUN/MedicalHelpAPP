#pragma once

#ifndef COL_CONFIGLOADERDATABASEABSTRACTTEST_H_
#define COL_CONFIGLOADERDATABASEABSTRACTTEST_H_

#include "pch.h"

#include "COL_ConfigLoaderDatabaseAbstract.h"
#include "COL_ConfigLoaderUtility.h"
#include "COL_ConfigLoader.h"

namespace HiddenButNotExposed {
	namespace COL {
		const static ConfigLoaderDatabaseAbstract::String DEFAULT_PATH = R"(D:\code\repo1\COL_ConfigLoader\database\XMLFile.xml)";
	
		class ConfigLoaderDatabaseXMLTest {
		private:
			ConfigLoaderDatabaseAbstract* m_intconfigloader{ nullptr };
		public:
			ConfigLoaderDatabaseXMLTest()
			{
				m_intconfigloader = new ConfigLoaderDatabaseXML();
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

		/*class ConfigLoaderTest {
		private:
			ConfigLoaderDatabaseAbstract* m_intconfigloader{ nullptr };
		public:
			ConfigLoaderTest()
			{
				m_intconfigloader = new ConfigLoader(new ConfigLoaderDatabaseXML(DEFAULT_PATH));
			}
			~ConfigLoaderTest() { delete m_intconfigloader; }
		public:
			ConfigLoader* getTestObject()
			{
				return m_intconfigloader;
			}
		};*/
	}
}

#endif // !COL_CONFIGLOADERDATABASEABSTRACTTEST_H_



