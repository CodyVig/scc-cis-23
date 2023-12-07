#include "graph/graphType.h"

using namespace std;

int main()
{
    graphType pOneGraph(100);

    // Read in the graph from a file
    pOneGraph.createGraph();

    // Depth-first traversal
    cout << "Performing a depth-first traversal..." << endl;
    pOneGraph.depthFirstTraversal();

    // Breadth-first traversal
    cout << "\nPerforming a breadth-first traversal..." << endl;
    pOneGraph.breadthFirstTraversal();

    cout << endl;
    return 0;
}