#include <iostream>
#include <vector>

#include "Pracs/Prac02/DataStructures/Stack/StackPrac02.h"
#include "Pracs/Prac07/Sort/QuickSort/QuickSort07.h"
#include "Queue/DT_CycleQueue.h"
#include "Stack/DTA_ChangePostfix.h"
#include "Stack/DTA_CheckSymbolPair.h"
#include "Stack/DTA_CalcPostfix.h"
#include "Stack/DT_LLStack.h"
#include "Tree/DT_CalcFolderSize.h"

void normalStack()
{
    StackPrac02 stack(2);

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
                std::cout << "Peek : " << stack.top() << std::endl;
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

void postfixCalc()
{
    struct TestCase {
        std::string expression;
        int expected;
    };

    std::vector<TestCase> testCases = {
        {"34+", 7},       // 3 + 4
        {"52-", 3},       // 5 - 2
        {"23*", 6},       // 2 * 3
        {"84/", 2},       // 8 / 4
        {"34+2*", 14},    // (3 + 4) * 2
        {"93-2/", 3},     // (9 - 3) / 2
        {"52+83-*", 35},  // (5 + 2) * (8 - 3)
        {"93*42/+1-", 28}  // (9 * 3) + (4 / 2) - 1
    };

    DTA_CalcPostfix calc_postfix;
    for (const TestCase& expr : testCases)
    {
        int result = calc_postfix.result(expr.expression);
        if (result == expr.expected)
        {
            std::cout << "정답 !! " << result << '\n';
        }
        else
        {
            std::cout << "오답 !! " << "내 답 : "<<result << " // " << "정답 : " << expr.expected << '\n';
        }
    }
}
void cycleQueue()
{
    DT_CycleQueue cycleQueue;
    
    for (int i = 0 ; i < 10;++i)
    {
        cycleQueue.enQueue(i);
    }

    std::cout<< cycleQueue.deQueue() << '\n';
    std::cout<< cycleQueue.deQueue() << '\n';
    cycleQueue.printQueue();
}

void print(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
class Base {
public:
    int a;
};

class Derived : virtual public Base {
public:
    int b;
};



int main(int argc, char* argv[])
{
    // Derived d;
    // Derived* pd = &d;
    // Base* pb = &d;
    // d.a = 01;
    // d.b= INT_MAX;
    //
    // std::cout << pd << std::endl;
    // std::cout << pb << std::endl;

    int arr[8] = {69,10,30,2,16,8,31,22};
    QuickSort07::quickSort(arr,0,7);
    print(arr,8);
    
    return 0;
}
