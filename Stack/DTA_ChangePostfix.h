#pragma once
#include <string>

class DTA_ChangePostfix
{
public:
    void solve(const std::string& str);
private:
    int precedence(char op);
};
