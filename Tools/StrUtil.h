#pragma once



#include <string>

int Replace(std::string& source, const std::string& replaceThis, const std::string& replaceWith);


std::string ConvertWStringToString(std::wstring & src, const char* locale);


std::wstring ConvertStringToWString(std::string& src, const char* locale);
