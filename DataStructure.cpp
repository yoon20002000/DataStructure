#include <iostream>
#include <vector>

#include "Stack/DTA_ChangePostfix.h"
#include "Stack/DTA_CheckSymbolPair.h"
#include "Stack/DT_LLStack.h"
#include "Stack/DT_Stack.h"

void normalStack()
{
    DT_Stack stack(2);

    while (true)
    {
        std::cout << " 0 : push, 1 : pop, 2 : peek, 3 : capacity,size, 4 : printStack" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            {
                std::cout << "Input int data : ";
                int val;
                std::cin >> val;
                stack.push(val);
                break;
            }
        case 1:
            {
                std::cout << "Pop : " << stack.pop() << std::endl;
                break;
            }
        case 2:
            {
                std::cout << "Peek : " << stack.peek() << std::endl;
                break;
            }
        case 3:
            {
                std::cout << "Capacity : " << stack.getCapacity() << " Size : " << stack.getSize() << std::endl;
                break;
            }
        case 4:
            {
                stack.printStack();
                break;
            }
        default:
            {
                std::cout << "Error retry";
                break;
            }
        }
    }
}

void linkedlistStack()
{
    DT_LLStack<int> stack;
    while (true)
    {
        std::cout << " 0 : push, 1 : pop, 2 : peek, 3 : printStack" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            {
                std::cout << "Input int data : ";
                int val;
                std::cin >> val;
                stack.push(val);
                break;
            }
        case 1:
            {
                std::cout << "Pop : " << stack.pop() << std::endl;
                break;
            }
        case 2:
            {
                std::cout << "Peek : " << stack.peek() << std::endl;
                break;
            }
        case 3:
            {
                stack.printStack();
                break;
            }
        default:
            {
                std::cout << "Error retry";
                break;
            }
        }
    }
}

void llsSymbolCheck()
{
    DTA_CheckSymbolPair checker;
    
    std::vector<std::string> testCases = {
        "",           // 빈 문자열
        "(",          // 짝 없는 여는 괄호
        ")",          // 짝 없는 닫는 괄호
        "()",         // 올바른 짝
        "([]{})",     // 복합 괄호, 올바른 짝
        "({[)]}",     // 틀린 짝
        "{([])}",     // 올바른 중첩
        "{([}",       // 짝 없음
        "abc(def)",   // 괄호만 검사: 올바름
        "(a+b)*(c-d)",// 수식 포함 괄호: 올바름
        "(()",        // 닫히지 않음
        "())",        // 열리지 않고 닫힘
    };

    for (const std::string& expr : testCases)
    {
        bool result = checker.checkSymbolPair(expr);
        std::cout << "\"" << expr << "\" => " << (result ? "✔ true" : "✘ false") << "\n";
    }
}

void postfix()
{
    std::vector<std::string> infixExpressions = {
        "A+B",
        "A+B*C",
        "(A+B)*C",
        "A*B+C",
        "A*(B+C)",
        "A+(B*C)",
        "(A+B)*(C+D)",
        "A+B+C+D",
        "A*(B+C*(D+E))",
        "((A+B)*C)-(D-E)",
        "A+B*C-D/E",
        "((A*B)-(C/D))",
    };

    DTA_ChangePostfix changePostfix;
    
    for (const std::string& expr : infixExpressions)
    {
        changePostfix.solve(expr);
    }
}

int main(int argc, char* argv[])
{
    postfix();
    return 0;
}
