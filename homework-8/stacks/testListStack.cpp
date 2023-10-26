/* Program to test various operations of a stack. */

#include "listStack.h"
#include <iostream>

using namespace std;

int main()
{
    listStack<int> stack(4);

    stack.push(10);
    stack.push(100);
    stack.push(3);
    stack.push(32);

    for (int idx = 0; idx < 4; idx++)
    {
        cout << "Is the stack full? " << stack.isFullStack() << endl;
        cout << "The number at the top of the stack is " << stack.top() << endl;
        stack.pop();
        cout << "Is the stack empty? " << stack.isEmptyStack() << endl << endl;
    }

    return 0;
}