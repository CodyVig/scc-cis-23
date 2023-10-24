/* Tests if an input string is a palindrome. */

#include "queues/linkedQueue.h"
#include "queues/listQueue.h" // #include "queueAsArray.h"
#include "stacks/listStack.h" // #include "myStack.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    listQueue<char> queue(200);
    listStack<char> stack(200);

    string sentence;

    int len, i;
    char ch;
    bool isPalindrome;

    cout << "Enter in a sentence:" << endl;

    getline(cin, sentence);
    len = sentence.length();
    i = 0;

    // Add each char in the input sentence to the stack and the queue
    while (i < len)
    {
        /* TODO add your code here */

        i++;
    }

    isPalindrome = true;

    /* TODO add your code here to check if sentence is a palindrome */

    if (isPalindrome)
        cout << "The input sentence is a palindrome!" << endl;
    else
        cout << "The input sentence is not a palindrome." << endl;

    cout << endl;

    return 0;
}

/**
 * Uses a queue to reverse a stack in-place.
 *
 * @param `s`: An integer `listStack` object to be reversed.
 * @return The same stack object with its elements reversed.
 */
template <class Type> void reverseStack()
{
    linkedQueue<Type> q;
    Type elem;

    /* your code here */
}
