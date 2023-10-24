// This program tests various operations of a linked stack

#include "linkedStack.h"
#include <iostream>

using namespace std;

int main()
{
    linkedStack<double> stack1;
    stack1.push(232.321);
    stack1.push(1.23);
    stack1.push(943.321);
    stack1.push(0.003);
    stack1.pop();
    stack1.pop();
    linkedStack<double> stack2 = stack1;
    stack1.push(3.14);
    cout << "The number at the top of the stack1 is " << stack1.top() << endl;
    cout << "The number at the top of the stack2 is " << stack2.top() << endl;
    cout << "Is the stack empty? " << stack2.isEmptyStack() << endl;
    return 0;
}