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
    binaryTree.NonRecurPreOrder();

    // In-order traversal
    binaryTree.RecurInOrder();
    binaryTree.NonRecurInOrder();

    // Post-order traversal
    binaryTree.RecurPostOrder();
    binaryTree.NonRecurPostOrder();

    // level order traversal
    binaryTree.LevelOrder();
}