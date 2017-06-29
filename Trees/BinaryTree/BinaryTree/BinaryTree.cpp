#include <queue>
#include <stack>
#include <iostream>
#include "BinaryTree.h"

using namespace std;

BiTreeNode::BiTreeNode(char c)
{
    bIsFirst = false;
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

// Non-recursice pre-order traversal
void BiTree::NonRecurPreOrder()
{
    if (pRoot == NULL)
    {
        return;
    }

    stack<BiTreeNode *> sNodes;
    BiTreeNode *pCurrNode = pRoot;

    cout << "Non-recursive pre-order:";
    while (pCurrNode || !sNodes.empty())
    {
        while (pCurrNode)
        {
            cout << pCurrNode->data << " ";
            sNodes.push(pCurrNode);
            pCurrNode = pCurrNode->pLChild;
        }

        if (!sNodes.empty())
        {
            pCurrNode = sNodes.top();
            sNodes.pop();
            pCurrNode = pCurrNode->pRChild;
        }
    }
    cout << endl;
}

// Non-recursice in-order traversal
void BiTree::NonRecurInOrder()
{
    if (pRoot == NULL)
    {
        return;
    }

    stack<BiTreeNode*> sNodes;
    BiTreeNode *pCurrNode = pRoot;

    cout << "Non-recursive in-order:";
    while (pCurrNode || !sNodes.empty())
    {
        while (pCurrNode)
        {
            sNodes.push(pCurrNode);
            pCurrNode = pCurrNode->pLChild;
        }

        if (!sNodes.empty())
        {
            pCurrNode = sNodes.top();
            sNodes.pop();
            cout << pCurrNode->data << " ";
            pCurrNode = pCurrNode->pRChild;
        }
    }
    cout << endl;
}

// Non-recursice post-order traversal
void BiTree::NonRecurPostOrder()
{
    if (pRoot == NULL)
    {
        return;
    }
    stack<BiTreeNode*> sNodes;
    BiTreeNode *pCurrNode = pRoot;

    cout << "Non-recursive post-order:";
    while (pCurrNode || !sNodes.empty())
    {
        while (pCurrNode)
        {
            pCurrNode->bIsFirst = true;
            sNodes.push(pCurrNode);
            pCurrNode = pCurrNode->pLChild;
        }

        if (!sNodes.empty())
        {
            BiTreeNode *pNode = sNodes.top();
            sNodes.pop();
            if (pNode->bIsFirst)
            {
                pNode->bIsFirst = false;
                sNodes.push(pNode);
                pCurrNode = pNode->pRChild;
            }
            else
            {
                cout << pNode->data << " ";
                pCurrNode = NULL;
            }
        }
    }
    cout << endl;
}

// level order traversal
void BiTree::LevelOrder()
{
    if (pRoot == NULL)
    {
        return;
    }

    queue<BiTreeNode*> qNodes;
    qNodes.push(pRoot);

    cout << "level order:";
    while (!qNodes.empty())
    {
        BiTreeNode *pNode = qNodes.front();
        qNodes.pop();
        cout << pNode->data << " ";

        if (pNode->pLChild)
        {
            qNodes.push(pNode->pLChild);
        }
        if (pNode->pRChild)
        {
            qNodes.push(pNode->pRChild);
        }
    }
    cout << endl;
}