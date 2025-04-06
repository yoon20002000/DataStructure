#include "DTA_CheckSymbolPair.h"

#include "DT_LLStack.h"

bool DTA_CheckSymbolPair::checkSymbolPair(const std::string& express)
{
    size_t length = express.length();

    if (length < 2)
    {
        return false;
    }
    
    DT_LLStack<char> stack;

    for (size_t i = 0; i < length; i++)
    {
        switch (express[i])
        {
        case '(':
        case '[':
        case '{':
            {
                stack.push(express[i]);
                break;
            }
        case ')':
        case ']':
        case '}':
            {
                if (stack.isEmpty())
                {
                    return false;
                }
                else
                {
                    char c = stack.pop();
                    if (
                    ((c == '(') && express[i] != ')' )||
                    ((c == '[') && express[i] != ']')||
                    ((c == '{') && express[i] != '}'))
                    {
                        return false;
                    }
                }
                
                break;
            }
        default:
            {
                break;
            }
        }
    }

    bool isEmpty = stack.isEmpty();
    return isEmpty;
}
