#include <queue>
#include <iostream>
#include "BinaryTree.h"

using namespace std;

BiTreeNode::BiTreeNode(char c)
{
    data = c;
    pLChild = nullptr;
    pRChild = nullptr;
}

BiTree::BiTree()
{
    pRoot = nullptr;
}

BiTree::~BiTree()
{
}

// Create a binary tree from a stream of level order data
void BiTree::CreateFromLevelOrder(char cArray[], int n)
{
    if (n <= 0)
    {
        return;
    }

    queue<BiTreeNode*> qNodes;
    if (pRoot == NULL)
    {
        pRoot = new BiTreeNode(cArray[0]);
    }
    qNodes.push(pRoot);

    int i = 1;
    while (i < n)
    {
        BiTreeNode* pNode = qNodes.front();
        qNodes.pop();

        if (i < n)
        {
            BiTreeNode* pLNode = new BiTreeNode(cArray[i++]);
            pNode->pLChild = pLNode;
            qNodes.push(pLNode);
        }

        if (i < n)
        {
            BiTreeNode* pRNode = new BiTreeNode(cArray[i++]);
            pNode->pRChild = pRNode;
            qNodes.push(pRNode);
        }
    }
}

// Traverse the binary tree pre-order.
void BiTree::RecurPreOrder()
{
    if (pRoot == NULL)
    {
        return;
    }

    cout << "Pre-Order:";
    PreOrder(pRoot);
    cout << endl;
}

void BiTree::PreOrder(BiTreeNode* pNode)
{
    if (pNode)
    {
        cout << pNode->data << " ";
        PreOrder(pNode->pLChild);
        PreOrder(pNode->pRChild);
    }
}

// Traverse the binary tree in-order.
void BiTree::RecurInOrder()
{
    if (pRoot == NULL)
    {
        return;
    }

    cout << "In-Order:";
    InOrder(pRoot);
    cout << endl;
}

void BiTree::InOrder(BiTreeNode* pNode)
{
    if (pNode)
    {
        InOrder(pNode->pLChild);
        cout << pNode->data << " ";
        InOrder(pNode->pRChild);
    }
}

// Traverse the binary tree post-order.
void BiTree::RecurPostOrder()
{
    if (pRoot == NULL)
    {
        return;
    }

    cout << "Post-Order:";
    PostOrder(pRoot);
    cout << endl;
}

void BiTree::PostOrder(BiTreeNode* pNode)
{
    if (pNode)
    {
        PostOrder(pNode->pLChild);
        PostOrder(pNode->pRChild);
        cout << pNode->data << " ";
    }
}

// Non-recursice traversal
void BiTree::NonRecurInOrder()
{

}

void BiTree::NonRecurPreOrder()
{

}

void BiTree::NonRecurPostOrder()
{

}