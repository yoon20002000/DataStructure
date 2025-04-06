#include "DTA_ChangePostfix.h"

#include "DT_LLStack.h"

int DTA_ChangePostfix::precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void DTA_ChangePostfix::solve(const std::string& str)
{
    DT_LLStack<char> stack;

    std::cout << str << " to : ";
    for (char token : str)
    {
        if (std::isalpha(token))  // 피연산자
        {
            std::cout << token;
        }
        else if (token == '(')
        {
            stack.push(token);
        }
        else if (token == ')')
        {
            while (!stack.isEmpty() && stack.peek() != '(')
            {
                std::cout << stack.pop();
            }
            if (!stack.isEmpty()) stack.pop(); // '(' 제거
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(token))
            {
                std::cout << stack.pop();
            }
            stack.push(token);
        }
    }

    while (!stack.isEmpty())
    {
        std::cout << stack.pop();
    }

    std::cout << '\n';
}
