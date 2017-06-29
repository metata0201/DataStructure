class BiTreeNode
{
    friend class BiTree;
public:
    BiTreeNode(char c);
private:
    bool bIsFirst;          // Specially use for non-recursive post-order traversal.
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
    void NonRecurPreOrder();
    void NonRecurInOrder();
    void NonRecurPostOrder();
    // level order traversal
    void LevelOrder();
    // Non-recursice traversal:more easy
    void NonRecurPreOrderNew();
    void NonRecurInOrderNew();
    void NonRecurPostOrderNew();

private:
    void PreOrder(BiTreeNode* pNode);
    void InOrder(BiTreeNode* pNode);
    void PostOrder(BiTreeNode* pNode);

private:
    BiTreeNode *pRoot;
};