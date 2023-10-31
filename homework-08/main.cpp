/*****************************************************************************
 * Author:       Cody Vig
 * Assignment:   Homework 8
 * Due Date:     October 26, 2023.
 *****************************************************************************/

#include "queues/linkedQueue.h" // For problem 2
#include "queues/listQueue.h"   // My `#include "queueAsArray.h"`
#include "stacks/listStack.h"   // My `#include "myStack.h"`
#include <iostream>
#include <string>

using namespace std;

template <class Type> void reverseStack(listStack<Type> &s);

/**
 * Pass `2` as a command line argument to run problem 2, or pass `3` as a
 * command line argument to run problem 3. If no command line argument is
 * passed, problem 3 is run.
 *
 * @param `argc`: The number of command line arguments.
 * @param `argv`: A pointer to the list of command line arguments.
 */
int main(int argc, char **argv)
{
    // If `2` is passed, run problem 2.
    if (argc == 2 && atof(argv[1]) == 2)
    {
        listStack<int> stack(10);

        // Fill the stack with arbitrary data
        stack.push(3);
        stack.push(1);
        stack.push(4);
        stack.push(1);
        stack.push(5);
        stack.push(9);

        cout << "The old stack is: [ ";
        while (!stack.isEmptyStack())
        {
            cout << stack.top() << " ";
            stack.pop();
        }

        cout << "]" << endl;

        // Refill the stack with the same data.
        stack.push(3);
        stack.push(1);
        stack.push(4);
        stack.push(1);
        stack.push(5);
        stack.push(9);

        // Reverse the stack:
        reverseStack(stack);

        cout << "The new stack is: [ ";
        while (!stack.isEmptyStack())
        {
            cout << stack.top() << " ";
            stack.pop();
        }

        cout << "]" << endl;

        return 0;
    }

    // If `3` is passed or if nothing is passed, run problem 3.
    if ((argc == 2 && atof(argv[1]) == 3) || argc == 1)
    {
        listQueue<char> queue(200);
        listStack<char> stack(200);

        string sentence;

        int len, i, spaces;
        bool isPalindrome;

        cout << "Enter in a sentence:" << endl;

        getline(cin, sentence);
        len = sentence.length();
        i = 0;
        spaces = 0;

        // Add each char in the input sentence to the stack and the queue
        while (i < len)
        {
            /* TODO add your code here */
            if (isspace(sentence[i])) // Get rid of spaces
            {
                spaces++;
            }

            else if (!isalpha(sentence[i]))
            {
                // Don't comment on whether the sentence was a palindrome
                // if the sentence is not alphabetical to begin with.
                cout << "The input must be alphabetical." << endl;
                return 1;
            }

            else
            {
                // Store the lowercase version of the number.
                stack.push(tolower(sentence[i]));
                queue.addQueue(tolower(sentence[i]));
            }

            i++;
        }

        isPalindrome = true;
        i = 0;

        /* TODO add your code here to check if sentence is a palindrome */
        while (i < len - spaces)
        {
            // A sentence is a palindrome if the front of the queue is equal to
            // the end of the stack.
            if (stack.top() != queue.front())
            {
                isPalindrome = false;
                break;
            }

            stack.pop();
            queue.deleteQueue();
            i++;
        }

        if (isPalindrome)
            cout << "The input sentence is a palindrome!" << endl;
        else
            cout << "The input sentence is not a palindrome." << endl;

        return 0;
    }

    else
    {
        cout << "Invalid arguments. ";
        cout << "Pass `2` for problem 2 or `3` for problem 3." << endl;
        return -1;
    }
}

/**
 * (For problem 2)
 * Uses a queue to reverse a stack in-place.
 *
 * @param `s`: An integer `listStack` object to be reversed.
 * @return The same stack object with its elements reversed.
 */
template <class Type> void reverseStack(listStack<Type> &s)
{
    linkedQueue<Type> q;
    Type elem;

    /* your code here */
    // Fill the queue with the elements of the stack
    while (!s.isEmptyStack())
    {
        elem = s.top();
        s.pop();
        q.addQueue(elem);
    }

    // Fill the empty stack with the elements of the queue
    while (!q.isEmptyQueue())
    {
        s.push(q.front());
        q.deleteQueue();
    }
}
