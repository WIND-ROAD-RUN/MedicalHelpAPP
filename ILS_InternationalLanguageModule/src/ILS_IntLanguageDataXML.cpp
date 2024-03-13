#include "ILS_IntLanguageDataXML.h"
#include <iostream>

#include"pugixml.hpp"

IntLanguageDataXML::IntLanguageDataXML(const String& filePath)
    :m_filePath(filePath),m_operatorDoc(nullptr)
{
}

IntLanguageDataXML::~IntLanguageDataXML()
{
}

IntLanguageDataAbstract::ErrorInfo
IntLanguageDataXML::iniCom()
{
    m_operatorDoc = new pugi::xml_document;
    auto result = m_operatorDoc->load_file(m_filePath.c_str());
    /*if (!result) {
        return IntLanguageDataAbstract::ErrorInfo::INI_ERROR;
    }*/
    if (!(m_operatorDoc->child("LanguageTranslate"))) {
        m_operatorDoc->append_child("LanguageTranslate");
    }
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}

IntLanguageDataAbstract::ErrorInfo
IntLanguageDataXML::desCom()
{
    if (m_operatorDoc != NULL) {
        //std::cout << "YES" << '\n';
        m_operatorDoc->save_file(m_filePath.c_str());
        delete m_operatorDoc;
    }
    m_filePath.clear();
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}

IntLanguageDataAbstract::ErrorInfo
IntLanguageDataXML::searchString
(const IntLanguageDataAbstract::String& id,
    const IntLanguageDataAbstract::String& language,
    IntLanguageDataAbstract::String& s)const
{
    for (pugi::xml_node& tool : m_operatorDoc->child("LanguageTranslate")) {
        if (tool.first_attribute().value() == id) {
            for (pugi::xml_node& tools : tool.child("Country").children()) {
                if (tools.first_attribute().value() == language) {
                    s = tools.text().get();
                    return ErrorInfo::SUCCESS;
                }
            }
            return ErrorInfo::SEARCH_STRING_ERROR_LANGUAGE;
        }
    }
    return IntLanguageDataAbstract::ErrorInfo::SEARCH_STRING_ERROR_ID;
}

IntLanguageDataAbstract::ErrorInfo
IntLanguageDataXML::storeString
(const IntLanguageDataAbstract::String& id,
    const IntLanguageDataAbstract::String& language,
    const IntLanguageDataAbstract::String& s)
{
    for (pugi::xml_node& tool : m_operatorDoc->child("LanguageTranslate")) {
        if (tool.first_attribute().value() == id) {
            for (pugi::xml_node& tools : tool.child("Country").children()) {
                if (tools.first_attribute().value() == language) {
                    if (tools.text().get() == s)return ErrorInfo::SUCCESS;
                    else return ErrorInfo::STORE_STRING_ERROR_LANGUAGE;
                }
            }
            auto node = tool.child("Country");
            node.append_child("language").append_attribute("language");
            node.last_child().first_attribute().set_value(language.c_str());
            node.last_child().text().set(s.c_str());
            return ErrorInfo::SUCCESS;
        }
    }
    auto node = m_operatorDoc->child("LanguageTranslate");
    node.append_child("String");
    node.last_child().append_attribute("id").set_value(id.c_str());
    node = node.last_child();
    node = node.append_child("Country");
    node.append_child("language").append_attribute("language").set_value(language.c_str());
    node.last_child().text().set(s.c_str());
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}

IntLanguageDataAbstract::ErrorInfo
IntLanguageDataXML::changeString
(const IntLanguageDataAbstract::String& id,
    const IntLanguageDataAbstract::String& language,
    const IntLanguageDataAbstract::String& s)
{
    for (pugi::xml_node& tool : m_operatorDoc->child("LanguageTranslate")) {
        if (tool.first_attribute().value() == id) {
            for (pugi::xml_node& tools : tool.child("Country").children()) {
                if (tools.first_attribute().value() == language) {
                    tools.text().set(s.c_str());
                    return ErrorInfo::SUCCESS;
                }
            }
            return ErrorInfo::CHANGE_STRING_ERROR_LANGUAGE;
        }
    }
    return IntLanguageDataAbstract::ErrorInfo::CHANGE_STRING_ERROR_ID;
}

IntLanguageDataAbstract::ErrorInfo
IntLanguageDataXML::delString
(const IntLanguageDataAbstract::String& id, const IntLanguageDataAbstract::String& language)
{
    for (pugi::xml_node& tool : m_operatorDoc->child("LanguageTranslate")) {
        if (tool.first_attribute().value() == id) {
            for (pugi::xml_node& tools : tool.child("Country").children()) {
                if (tools.first_attribute().value() == language) {
                    tool.child("Country").remove_child(tools);
                    return ErrorInfo::SUCCESS;
                }
            }
            return ErrorInfo::DEL_STRING_ERROR_LANGUAGE;
        }
    }
    return IntLanguageDataAbstract::ErrorInfo::DEL_STRING_ERROR_ID;
}

IntLanguageDataAbstract::ErrorInfo
IntLanguageDataXML::getMap
(IntLanguageDataAbstract::IntLanMap* intLanMap)const
{
    if (!intLanMap)intLanMap = new IntLanMap;
    intLanMap->clear();
    for (pugi::xml_node tool : m_operatorDoc->child("LanguageTranslate")) {
        String id = tool.first_attribute().value();
        for (pugi::xml_node tools : tool.child("Country")) {
            String language = tools.first_attribute().value();
            (*intLanMap)[id][language] = tools.text().get();
        }
    }
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}

IntLanguageDataAbstract::ErrorInfo
IntLanguageDataXML::getMap
(const IntLanguageDataAbstract::String& language,
    IntLanguageDataAbstract::LanStringMap* lanStringMap)const
{
    if (!lanStringMap)lanStringMap = new LanStringMap;
    lanStringMap->clear();
    for (pugi::xml_node tool : m_operatorDoc->child("LanguageTranslate")) {
        String id = tool.first_attribute().value();
        for (pugi::xml_node tools : tool.child("Country")) {
            String language_ = tools.first_attribute().value();
            if (language_ == language)(*lanStringMap)[id] = tools.text().get();
        }
    }
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}

IntLanguageDataAbstract::ErrorInfo
IntLanguageDataXML::clearData()
{
    m_operatorDoc->remove_children();
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}
