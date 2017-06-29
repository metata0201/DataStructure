class BiTreeNode
{
    friend class BiTree;
public:
    BiTreeNode(char c);
private:
    char data;
    BiTreeNode *pLChild;
    BiTreeNode *pRChild;
};

class BiTree
{
public:
    BiTree();
    ~BiTree();
    void CreateFromLevelOrder(char cArray[], int n);
    // Recursive traversal
    void RecurPreOrder();
    void RecurInOrder();
    void RecurPostOrder();
    // Non-recursice traversal
    void NonRecurInOrder();
    void NonRecurPreOrder();
    void NonRecurPostOrder();

private:
    void PreOrder(BiTreeNode* pNode);
    void InOrder(BiTreeNode* pNode);
    void PostOrder(BiTreeNode* pNode);

private:
    BiTreeNode *pRoot;
};