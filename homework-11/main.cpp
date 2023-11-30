/*****************************************************************************
 * Author:       Cody Vig
 * Assignment:   Homework 11
 * Due Date:     November 29, 2023.
 *****************************************************************************/

#include "binarySearchTree.h"
#include "binaryTree.h"
#include <iostream>

template <class elemType>                                       // Visualization
void printBT(const string &, const nodeType<elemType> *, bool); // Visualization
template <class elemType>                                       // Visualization
void printBT(const nodeType<elemType> *);                       // Visualization

using namespace std;

/**
 * Homework 11, Problem 5.
 *
 * Creates a binary search tree of type int, add nodes to it (using the
 * `insert()` function), and demonstrate usage of `treeNodeCount()`,
 * `treeLeaveCount()`, and `treeHeight()`.
 */
int main()
{
    // Set a seed for random number generation (used to fill tree with data)
    srand((unsigned)time(NULL));

    bSearchTreeType<int> tree;

    // Fill the three with data
    for (int idx = 0; idx < 10; idx++)
    {
        // Insert a random number between 10 and 99
        tree.insert(rand() % 90 + 10);
    }

    cout << "Tree: \n";      // Visualization
    printBT(tree.getRoot()); // Visualization
    cout << endl;            // Visualization

    cout << "Inorder traversal:   [";
    tree.inorderTraversal();
    cout << "]." << endl;

    cout << "Preorder traversal:  [";
    tree.preorderTraversal();
    cout << "]." << endl;

    cout << "Postorder traversal: [";
    tree.postorderTraversal();
    cout << "]." << endl;

    cout << endl;
    cout << "* There are " << tree.treeNodeCount() << " nodes in the tree."
         << endl;

    cout << "* There are " << tree.treeLeavesCount() << " leaves in the tree."
         << endl;

    cout << "* The height of the tree is " << tree.treeHeight() << "." << endl;

    return 0;
}

/**
 * Prints the binary tree to the console as depth-indented text. This is
 * primarily used to ensure `treeNodeCount()` and `treeLeavesCount()` are
 * working properly.
 *
 * Source:
 * =======
 * https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
 */
template <class elemType>
void printBT(const string &prefix, const nodeType<elemType> *node, bool isLeft)
{
    if (node != nullptr)
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──");

        // print the value of the node
        cout << node->info << endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "│   " : "    "), node->lLink, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->rLink, false);
    }
}

/**
 * Prints the binary tree to the console as depth-indented text. This is
 * primarily used to ensure `treeNodeCount()` and `treeLeavesCount()` are
 * working properly.
 *
 * Source:
 * =======
 * https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
 */
template <class elemType> void printBT(const nodeType<elemType> *node)
{
    printBT("", node, false);
}
