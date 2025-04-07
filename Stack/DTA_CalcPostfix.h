#pragma once
#include <string>

class DTA_CalcPostfix
{
public:
    int result(const std::string& postfix);
private:
    bool isOperator(const char inChar);
};
