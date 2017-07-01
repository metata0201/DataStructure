#include <iostream>
#include "BinaryTree.h"

using namespace std;

void main()
{
    //char c[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

    //BiTree binaryTree;
    //binaryTree.CreateFromLevelOrder(c, 9);

    //// Pre-order traversal
    //binaryTree.RecurPreOrder();
    //binaryTree.NonRecurPreOrder();
    //binaryTree.NonRecurPreOrderNew();

    //// In-order traversal
    //binaryTree.RecurInOrder();
    //binaryTree.NonRecurInOrder();
    //binaryTree.NonRecurInOrderNew();

    //// Post-order traversal
    //binaryTree.RecurPostOrder();
    //binaryTree.NonRecurPostOrder();
    //binaryTree.NonRecurPostOrderNew();

    //// level order traversal
    //binaryTree.LevelOrder();

    string sPostFix = "34+5*6-";
    string sPrefix  = "-*+3457";

    BiTree ExpressionTreeA, ExpressionTreeB;
    ExpressionTreeA.CreateFromPostFixExpression(sPostFix);
    ExpressionTreeB.CreateFromPreFixExpression(sPrefix);

    if (ExpressionTreeA == ExpressionTreeB)
    {
        cout << "They are equal." << endl;
    }
    else
    {
        cout << "They are not equal." << endl;
    }
}