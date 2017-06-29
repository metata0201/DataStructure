#include <iostream>
#include "BinaryTree.h"

using namespace std;

void main()
{
    char c[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

    BiTree binaryTree;
    binaryTree.CreateFromLevelOrder(c, 9);

    // Pre-order traversal
    binaryTree.RecurPreOrder();

    // In-order traversal
    binaryTree.RecurInOrder();

    // Post-order traversal
    binaryTree.RecurPostOrder();
}