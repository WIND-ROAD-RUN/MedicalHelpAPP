//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

#include"ILS_IntLanguageDataAbstract.h"
#include"ILS_IntLanguageDataXML.h"

namespace HiddenButNotExposed {
namespace ILS {

    const static IntLanguageDataAbstract::String DEFAULT_PATH = R"(.\database\dataFile.xml)";

}//package
}//company