/* Tests if an input string is a palindrome. */

#include "queues/linkedQueue.h" // For problem 2
#include "queues/listQueue.h"   // #include "queueAsArray.h"
#include "stacks/listStack.h"   // #include "myStack.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    listQueue<char> queue(200);
    listStack<char> stack(200);

    string sentence;

    int len, i, spaces;
    char ch;
    bool isPalindrome;

    cout << "Enter in a sentence:" << endl;

    /***
     * I think this is operating system dependent. I am using Fedora Linux, and
     * `getline(cin, sentence)` fails to accept any string that includes a
     * space. For instance, if I type `was it a dog or cat i saw`, followed by
     * Enter, the program halts and will not accept the input. I have to
     * interrupt the console to end the program.
     ***/
    getline(cin, sentence);
    len = sentence.length();
    i = 0;
    spaces = 0;

    // Add each char in the input sentence to the stack and the queue
    while (i < len)
    {
        /* TODO add your code here */
        if (sentence[i] == ' ') // Get rid of spaces
        {
            spaces++;
            continue;
        }

        else if (!isalpha(sentence[i]))
        {
            // Don't comment on whether or not the sentence was a palindrome if
            // the sentence is not alphabetical to begin with.
            cout << "The input must be alphabetical." << endl;
            return 1;
        }

        else
        {
            // Store the lowercase version of the number.
            stack.push(tolower(sentence[i]));
            queue.addQueue(tolower(sentence[i]));

            i++;
        }
    }

    isPalindrome = true;

    i = 0;
    /* TODO add your code here to check if sentence is a palindrome */
    while (i < len - spaces)
    {
        // A sentence is a palindrome if the element at index `i` is equal to
        // the element at index `end - i`
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

    cout << endl;

    return 0;
}

/**
 * (For problem 2)
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
