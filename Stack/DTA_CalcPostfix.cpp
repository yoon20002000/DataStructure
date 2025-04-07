#include "DTA_CalcPostfix.h"

#include "DT_LLStack.h"

int DTA_CalcPostfix::result(const std::string& postfix)
{
    if (postfix.length() == 0)
    {
        return -1;
    }

    DT_LLStack<int> stack;
    
    for (size_t i = 0; i < postfix.length(); i++)
    {
        if (isdigit(postfix[i]))
        {
            stack.push(postfix[i] - '0');
        }
        else if (isOperator(postfix[i]))
        {
            int op2 = stack.pop();
            int op1 = stack.pop();
            
            switch (postfix[i])
            {
                case '+':
                    {
                        op1 += op2;
                        break;
                    }
                case '-':
                    {
                        op1 -= op2;
                        break;
                    }
                case '*':
                    {
                        op1 *= op2;
                        break;
                    }
                case '/':
                    {
                        op1 /= op2;
                        break;
                    }
                default:
                    {
                        std::cout << "error occured" << "\n";
                        break;
                    }
            }
            stack.push(op1);
        }
    }

    return stack.pop();
}

bool DTA_CalcPostfix::isOperator(const char inChar)
{
    return inChar == '+' || inChar == '-' || inChar == '*' || inChar == '/';
}
