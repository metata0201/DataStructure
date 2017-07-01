#include <queue>
#include <stack>
#include <iostream>
#include "BinaryTree.h"

using namespace std;

BiTreeNode::BiTreeNode(char c)
{
    bIsFirst = false;
    data = c;
    val  = 0;
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

// Create algebraic expressions tree from post-fix expression
// Reference:https://en.wikipedia.org/wiki/Binary_expression_tree
void BiTree::CreateFromPostFixExpression(string sPostFix)
{
    stack<BiTreeNode*> Stack;

    // Loop from begin to end
    for (int i = 0; i < sPostFix.size(); i++)
    {
        pRoot = new BiTreeNode(sPostFix.at(i));
        switch (sPostFix.at(i))
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            pRoot->pRChild = Stack.top();
            Stack.pop();
            pRoot->pLChild = Stack.top();
            Stack.pop();
            break;
        default:
            if (!(sPostFix.at(i)>='0' && sPostFix.at(i)<='9'))
            {
                cout << "Invalid algebraic expression!" << endl;
            }
            break;
        }
        Stack.push(pRoot);
    }

    pRoot = Stack.top();
    Stack.pop();
}

// Create algebraic expressions tree from pre-fix expression
void BiTree::CreateFromPreFixExpression(string sPreFix)
{
    stack<BiTreeNode*> Stack;

    // Loop from end to begin
    for (int i = sPreFix.size()-1; i >= 0; i--)
    {
        pRoot = new BiTreeNode(sPreFix.at(i));
        switch (sPreFix.at(i))
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            pRoot->pLChild = Stack.top();
            Stack.pop();
            pRoot->pRChild = Stack.top();
            Stack.pop();
            break;
        default:
            if (!(sPreFix.at(i)>='0' && sPreFix.at(i)<='9'))
            {
                cout << "Invalid algebraic expression!" << endl;
            }
            break;
        }
        Stack.push(pRoot);
    }

    pRoot = Stack.top();
    Stack.pop();
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

// More easy way to implemnet non-recursice traversal
// Reference:http://zisong.me/post/suan-fa/geng-jian-dan-de-bian-li-er-cha-shu-de-fang-fa
void BiTree::NonRecurPreOrderNew()
{
    if (pRoot == NULL)
    {
        return;
    }

    stack<pair<BiTreeNode*, bool>> sNodes;
    sNodes.push(make_pair(pRoot, false));

    cout << "Easy pre-order:";
    while (!sNodes.empty())
    {
        BiTreeNode *pCurrNode = sNodes.top().first;
        bool bVisited = sNodes.top().second;
        sNodes.pop();

        if (bVisited)
        {
            cout << pCurrNode->data << " ";
        }
        else
        {
            if (pCurrNode->pRChild)
            {
                sNodes.push(make_pair(pCurrNode->pRChild, false));
            }
            if (pCurrNode->pLChild)
            {
                sNodes.push(make_pair(pCurrNode->pLChild, false));
            }
            sNodes.push(make_pair(pCurrNode, true));
        }
    }
    cout << endl;
}

void BiTree::NonRecurInOrderNew()
{
    if (pRoot == NULL)
    {
        return;
    }

    stack<pair<BiTreeNode*, bool>> sNodes;
    sNodes.push(make_pair(pRoot, false));

    cout << "Easy in-order:";
    while (!sNodes.empty())
    {
        BiTreeNode *pCurrNode = sNodes.top().first;
        bool bVisited = sNodes.top().second;
        sNodes.pop();

        if (bVisited)
        {
            cout << pCurrNode->data << " ";
        }
        else
        {
            if (pCurrNode->pRChild)
            {
                sNodes.push(make_pair(pCurrNode->pRChild, false));
            }
            sNodes.push(make_pair(pCurrNode, true));
            if (pCurrNode->pLChild)
            {
                sNodes.push(make_pair(pCurrNode->pLChild, false));
            }
        }
    }
    cout << endl;
}

void BiTree::NonRecurPostOrderNew()
{
    if (pRoot == NULL)
    {
        return;
    }

    stack<pair<BiTreeNode*, bool>> sNodes;
    sNodes.push(make_pair(pRoot, false));

    cout << "Easy post-order:";
    while (!sNodes.empty())
    {
        BiTreeNode *pCurrNode = sNodes.top().first;
        bool bVisited = sNodes.top().second;
        sNodes.pop();

        if (bVisited)
        {
            cout << pCurrNode->data << " ";
        }
        else
        {
            sNodes.push(make_pair(pCurrNode, true));
            if (pCurrNode->pRChild)
            {
                sNodes.push(make_pair(pCurrNode->pRChild, false));
            }
            if (pCurrNode->pLChild)
            {
                sNodes.push(make_pair(pCurrNode->pLChild, false));
            }
        }
    }
    cout << endl;
}

// Expression tree evaluation
int BiTree::Evaluate()
{
    PostOrderEvaluate(pRoot);
    return pRoot->val;
}

// Post-order traverse the expression tree to evaluate algebraic expression.
void BiTree::PostOrderEvaluate(BiTreeNode* pNode)
{
    if (pNode)
    {
        PostOrderEvaluate(pNode->pLChild);
        PostOrderEvaluate(pNode->pRChild);
        switch (pNode->data)
        {
        case '+':
            pNode->val = (pNode->pLChild->val) + (pNode->pRChild->val);
            break;
        case '-':
            pNode->val = (pNode->pLChild->val) - (pNode->pRChild->val);
            break;
        case '*':
            pNode->val = (pNode->pLChild->val) * (pNode->pRChild->val);
            break;
        case '/':
            pNode->val = (pNode->pLChild->val) / (pNode->pRChild->val);
            break;
        default:
            if (pNode->data >= '0' && pNode->data <= '9')
            {
                pNode->val = pNode->data - '0';
            }
            else
            {
                cout << "Invalid operand!" << endl;
            }
            break;
        }
    }
}

// Get root
BiTreeNode* BiTree::GetRoot()
{
    return pRoot;
}

// Copy tree
void BiTree::Copy(BiTree &orignalTree)
{
    pRoot = CopyNode(orignalTree.GetRoot());
}

// Copy binary tree node
BiTreeNode* BiTree::CopyNode(BiTreeNode* pOrignalNode)
{
    if (pOrignalNode)
    {
        BiTreeNode* pParent = new BiTreeNode(pOrignalNode->data);
        pParent->pLChild = CopyNode(pOrignalNode->pLChild);
        pParent->pRChild = CopyNode(pOrignalNode->pRChild);
        return pParent;
    }
    else
    {
        return NULL;
    }
}