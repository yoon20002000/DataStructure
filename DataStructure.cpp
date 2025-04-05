#include <iostream>

#include "Stack/DT_Stack.h"

int main(int argc, char* argv[])
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


    return 0;
}
