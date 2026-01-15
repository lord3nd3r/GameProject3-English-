/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerEngine___AVLTree.h */
#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__
#include <vector>

template<typename TKey, typename TValue>
class TreeNode
{
public:
    TreeNode(): m_pLeft(NULL), m_pRight(NULL), m_nHeight(0)
    {
    }

public:
    TKey* GetKey()
    {
        return &m_Key;
    }

    TValue* GetValue()
    {
        return &m_Data;
    }

public:
    TValue m_Data;
    TKey   m_Key;
    int    m_nHeight;
    TreeNode<TKey, TValue>* m_pLeft;
    TreeNode<TKey, TValue>* m_pRight;
    TreeNode<TKey, TValue>* m_pParent;
};

//AVL[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
class AVLTree
{
public:
    typedef TreeNode<TKey, TValue>  TNodeType;
    typedef TreeNode<TKey, TValue>* TNodeTypePtr;

public:
    AVLTree(): m_pRoot(NULL)
    {
        m_pFreeHead = NULL;

        AllocBufferNode();

        m_nCount = 0;
    }

    ~AVLTree()
    {
        Clear();
    }

    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
public:
    TValue*         InsertAlloc(TKey Key);
    bool            Insert(TKey Key, TValue Value);
    bool            Delete(TKey Key);
    TNodeTypePtr    Find(TKey Key);
    void            Traversal();
    TValue*         GetByKey(TKey Key);
    bool            Insert(TNodeTypePtr pNode);
    TNodeTypePtr    AllocNode();
    void            FreeNode(TNodeTypePtr pNode);
    void            DoEnumNode(TNodeTypePtr pNode);
    int             GetCount();
    bool            Delete(TNodeTypePtr pNode);
    TNodeTypePtr    MoveFirst();
    TNodeTypePtr    MoveNext(TNodeTypePtr pNode);
    bool            Clear();

private:
    TNodeTypePtr    FindInner(TNodeTypePtr pRootNode, TKey Key);
    bool            InsertInner(TNodeTypePtr& pParentNode, TNodeTypePtr pInsertNode);   //[TRANSLATED][TRANSLATED]
    void            Insubtree(TNodeTypePtr pRootNode);                                  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    bool            DeleteInner(TNodeTypePtr& pNode,  TKey Key);        //[TRANSLATED][TRANSLATED]
    void            SingRotateLeft(TNodeTypePtr& pNode);//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    void            SingRotateRight(TNodeTypePtr& pNode);//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    void            DoubleRotateLR(TNodeTypePtr& pNode);//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    void            DoubleRotateRL(TNodeTypePtr& pNode);//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    int             Max(int Value1, int Value2); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    int             GetHeight(TNodeTypePtr pNode);


    bool            AllocBufferNode(int nSize = 1024);

private:
    TNodeType* m_pRoot;       //[TRANSLATED][TRANSLATED][TRANSLATED]

    TNodeType* m_pFreeHead;

    int        m_nCount;

    std::vector<TNodeType*> m_NodeBuff;
};

template<typename TKey, typename TValue>
int AVLTree<TKey, TValue>::GetCount()
{
    return m_nCount;
}

template<typename TKey, typename TValue>
TValue* AVLTree<TKey, TValue>::InsertAlloc( TKey Key )
{
    TNodeTypePtr pNode = AllocNode();
    if(pNode == NULL)
    {
        ASSERT(FALSE);
        return NULL;
    }

    pNode->m_Key  = Key;

    if(m_pRoot == NULL)
    {
        m_pRoot         = pNode;
        m_nCount        += 1;
        pNode->m_pParent = NULL;
    }
    else
    {
        if(!InsertInner(m_pRoot, pNode))
        {
            FreeNode(pNode);
            //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Failure，[TRANSLATED][TRANSLATED]key[TRANSLATED][TRANSLATED][TRANSLATED]already[TRANSLATED][TRANSLATED]
            return NULL;
        }
    }

    return &pNode->m_Data;
}

template<typename TKey, typename TValue>
bool AVLTree<TKey, TValue>::Insert( TNodeTypePtr pNode )
{
    if(m_pRoot == NULL)
    {
        m_pRoot = pNode;

        m_nCount += 1;

        return true;
    }

    return InsertInner(m_pRoot, pNode);
}

template<typename TKey, typename TValue>
TValue* AVLTree<TKey, TValue>::GetByKey( TKey Key )
{
    TNodeTypePtr pNode = Find(Key);
    if(pNode == NULL)
    {
        return NULL;
    }

    return &pNode->m_Data;
}

template<typename TKey, typename TValue>
TreeNode<TKey, TValue>* AVLTree<TKey, TValue>::AllocNode()
{
    if(m_pFreeHead == NULL)
    {
        AllocBufferNode();
    }

    if(m_pFreeHead == NULL)
    {
        return NULL;
    }

    TNodeTypePtr pValidNode = m_pFreeHead;

    m_pFreeHead = m_pFreeHead->m_pRight;
    if (m_pFreeHead != NULL)
    {
        m_pFreeHead->m_pLeft = NULL;
    }

    pValidNode = new(pValidNode)TNodeType();
    pValidNode->m_nHeight = 0;
    pValidNode->m_pLeft   = NULL;
    pValidNode->m_pRight  = NULL;

    return pValidNode;
}

template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::FreeNode(TNodeTypePtr pNode)
{
    if (m_pFreeHead == NULL)
    {
        m_pFreeHead = pNode;
        m_pFreeHead->m_pLeft = NULL;
        m_pFreeHead->m_pRight = NULL;
    }
    else
    {
        pNode->m_pRight = m_pFreeHead;
        m_pFreeHead->m_pLeft = pNode;
        m_pFreeHead = pNode;
        m_pFreeHead->m_pLeft = NULL;
    }

    return ;
}

template<typename TKey, typename TValue>
bool AVLTree<TKey, TValue>::Delete(TNodeTypePtr pNode)
{
    if((m_pRoot == NULL) || (pNode == NULL))
    {
        return false;
    }

    ASSERT(Find(*pNode->GetKey()) != NULL);

    return Delete(*pNode->GetKey());
}

template<typename TKey, typename TValue>
TreeNode<TKey, TValue>* AVLTree<TKey, TValue>::MoveFirst()
{
    if(m_pRoot == NULL)
    {
        return NULL;
    }

    TreeNode<TKey, TValue>* pTempNode = m_pRoot;
    while(pTempNode->m_pLeft != NULL)
    {
        pTempNode = pTempNode->m_pLeft;
    }

    return pTempNode;
}


template<typename TKey, typename TValue>
TreeNode<TKey, TValue>* AVLTree<TKey, TValue>::MoveNext(TNodeTypePtr pNode)
{
    if(pNode == NULL)
    {
        return NULL;
    }

    TreeNode<TKey, TValue>* pTempNode = NULL;

    if (pNode->m_pRight != NULL)
    {
        pTempNode = (TreeNode<TKey, TValue>*) pNode->m_pRight;
        while (pTempNode->m_pLeft != NULL)
        {
            pTempNode = (TreeNode<TKey, TValue>*)pTempNode->m_pLeft;
        }

        return pTempNode;
    }

    pTempNode = (TreeNode<TKey, TValue>*)pNode->m_pParent;
    while (pTempNode != NULL && pNode == (TreeNode<TKey, TValue>*)pTempNode->m_pRight)
    {
        pNode = pTempNode;

        pTempNode = (TreeNode<TKey, TValue>*)pTempNode->m_pParent;
    }

    return pTempNode;
}


template<typename TKey, typename TValue>
bool AVLTree<TKey, TValue>::AllocBufferNode(int nSize)
{
    TNodeType* pNode = (TNodeType*)malloc(sizeof(TNodeType) * nSize);
    if(pNode == NULL)
    {
        return false;
    }

    memset(pNode, 0, sizeof(TNodeType) * nSize);

    m_NodeBuff.push_back(pNode);

    for(int i = 0; i < nSize; i++)
    {
        pNode = new(pNode)TNodeType();
        pNode->m_Key = i;

        if(m_pFreeHead == NULL)
        {
            m_pFreeHead = pNode;
        }
        else
        {
            pNode->m_pRight = m_pFreeHead;
            m_pFreeHead->m_pLeft = pNode;
            m_pFreeHead = pNode;
            m_pFreeHead->m_pLeft = NULL;
        }

        pNode ++;
    }

    return true;
}

template<typename TKey, typename TValue>
bool AVLTree<TKey, TValue>::Clear()
{
    for(size_t i = 0; i < m_NodeBuff.size(); ++i)
    {
        TNodeType* pNode = m_NodeBuff.at(i);
        if(pNode != NULL)
        {
            free(pNode);
        }
    }

    m_NodeBuff.clear();

    m_pFreeHead = NULL;
    m_pRoot     = NULL;

    return true;
}



template<typename TKey, typename TValue>
int AVLTree<TKey, TValue>::Max( int Value1, int Value2 )
{
    return Value1 > Value2 ? Value1 : Value2;
}

//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
int AVLTree<TKey, TValue>::GetHeight(TNodeTypePtr pNode)
{
    if(pNode == NULL)
    {
        return -1;
    }

    return pNode->m_nHeight;

}

//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::SingRotateLeft(TNodeTypePtr& pNode)
{
    TNodeTypePtr  pOrgParent = pNode->m_pParent;
    TNodeTypePtr pTempNode;
    pTempNode = pNode->m_pLeft;
    pNode->m_pLeft  = pTempNode->m_pRight;
    if (pNode->m_pLeft != NULL)
    {
        pNode->m_pLeft->m_pParent = pNode;
    }
    pTempNode->m_pRight = pNode;
    pNode->m_pParent = pTempNode;

    pNode->m_nHeight = Max(GetHeight(pNode->m_pLeft), GetHeight(pNode->m_pRight)) + 1;
    pTempNode->m_nHeight = Max(GetHeight(pTempNode->m_pLeft), GetHeight(pNode)) + 1;
    pNode = pTempNode;
    pNode->m_pParent = pOrgParent;
}
//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::SingRotateRight(TNodeTypePtr& pNode)
{
    TNodeTypePtr  pOrgParent = pNode->m_pParent;
    TNodeTypePtr pTempNode;
    pTempNode = pNode->m_pRight;
    pNode->m_pRight = pTempNode->m_pLeft;
    if (pNode->m_pRight != NULL)
    {
        pNode->m_pRight->m_pParent = pNode;
    }
    pTempNode->m_pLeft = pNode;
    pNode->m_pParent = pTempNode;

    pNode->m_nHeight = Max(GetHeight(pNode->m_pLeft), GetHeight(pNode->m_pRight)) + 1;
    pTempNode->m_nHeight = Max(GetHeight(pTempNode->m_pRight), GetHeight(pNode)) + 1;

    pNode = pTempNode;
    pNode->m_pParent = pOrgParent;
}
//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::DoubleRotateLR(TNodeTypePtr& pNode)
{
    SingRotateRight(pNode->m_pLeft);

    SingRotateLeft(pNode);
}
//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::DoubleRotateRL(TNodeTypePtr& pNode)
{
    SingRotateLeft(pNode->m_pRight);

    SingRotateRight(pNode);
}

//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
bool AVLTree<TKey, TValue>::Insert(TKey Key, TValue Value)
{
    TNodeTypePtr pNode = AllocNode();
    if(pNode == NULL)
    {
        ASSERT(FALSE);
        return false;
    }

    pNode->m_Key  = Key;
    pNode->m_Data = Value;

    if(m_pRoot == NULL)
    {
        m_pRoot = pNode;
        m_nCount += 1;
        pNode->m_pParent = NULL;

        return true;
    }

    return InsertInner(m_pRoot, pNode);
}

//[TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
bool AVLTree<TKey, TValue>::InsertInner(TNodeTypePtr& pParentNode, TNodeTypePtr pInsertNode)
{
    if(pParentNode == NULL)
    {
        ASSERT(FALSE);
        return false;
    }

    if(pParentNode->m_Key > pInsertNode->m_Key)
    {
        if(pParentNode->m_pLeft != NULL)
        {
            if(!InsertInner(pParentNode->m_pLeft, pInsertNode))
            {
                ASSERT(FALSE);
                return false;
            }
        }
        else
        {
            pParentNode->m_pLeft = pInsertNode;
            pInsertNode->m_pParent = pParentNode;
            m_nCount += 1;
        }

        if((GetHeight(pParentNode->m_pLeft) - GetHeight(pParentNode->m_pRight)) >= 2)
        {
            if(pInsertNode->m_Key < pParentNode->m_pLeft->m_Key)
            {
                SingRotateLeft(pParentNode);
            }
            else
            {
                DoubleRotateLR(pParentNode);
            }
        }
    }
    else if(pParentNode->m_Key < pInsertNode->m_Key)
    {
        if(pParentNode->m_pRight != NULL)
        {
            if(!InsertInner(pParentNode->m_pRight, pInsertNode))
            {
                ASSERT(FALSE);
                return false;
            }
        }
        else
        {
            pParentNode->m_pRight = pInsertNode;
            pInsertNode->m_pParent = pParentNode;
            m_nCount += 1;
        }

        if((GetHeight(pParentNode->m_pRight) - GetHeight(pParentNode->m_pLeft)) >= 2)
        {
            if(pInsertNode->m_Key > pParentNode->m_pRight->m_Key)
            {
                SingRotateRight(pParentNode);
            }
            else
            {
                DoubleRotateRL(pParentNode);
            }
        }
    }
    else
    {
        //already[TRANSLATED][TRANSLATED]
        return false;
    }

    pParentNode->m_nHeight = Max(GetHeight(pParentNode->m_pLeft), GetHeight(pParentNode->m_pRight)) + 1;

    return true;
}


template<typename TKey, typename TValue>
TreeNode<TKey, TValue>* AVLTree<TKey, TValue>::FindInner(TNodeTypePtr pNode, TKey Key)
{
    if(pNode == NULL) //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]is[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED],[TRANSLATED][TRANSLATED]NULL
    {
        return NULL;
    }

    if(pNode->m_Key > Key)//[TRANSLATED][TRANSLATED]x[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED],[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]x
    {
        return FindInner(pNode->m_pLeft, Key);
    }

    if(pNode->m_Key < Key) //[TRANSLATED][TRANSLATED]x[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED],[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]x
    {
        return FindInner(pNode->m_pRight, Key);
    }

    return pNode;
}
//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
TreeNode<TKey, TValue>* AVLTree<TKey, TValue>::Find(TKey Key)
{
    return FindInner(m_pRoot, Key);
}
//[TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
bool AVLTree<TKey, TValue>::DeleteInner(TNodeTypePtr& pNode, TKey Key)
{
    if(pNode == NULL)
    {
        return false;
    }

    if(Key < pNode->m_Key)
    {
        if(!DeleteInner(pNode->m_pLeft, Key))
        {
            return false;
        }

        if((GetHeight(pNode->m_pRight) - GetHeight(pNode->m_pLeft)) >= 2)
        {
            if((pNode->m_pRight->m_pLeft != NULL) && (GetHeight(pNode->m_pRight->m_pLeft) > GetHeight(pNode->m_pRight->m_pRight)) )
            {
                DoubleRotateRL(pNode);
            }
            else
            {
                SingRotateRight(pNode);
            }
        }
    }
    else if(Key > pNode->m_Key)
    {
        if(!DeleteInner(pNode->m_pRight, Key))
        {
            return false;
        }

        if((GetHeight(pNode->m_pLeft) - GetHeight(pNode->m_pRight)) >= 2)
        {
            if(pNode->m_pLeft->m_pRight != NULL && (GetHeight(pNode->m_pLeft->m_pRight) > GetHeight(pNode->m_pLeft->m_pLeft) ))
            {
                DoubleRotateLR(pNode);
            }
            else
            {
                SingRotateLeft(pNode);
            }
        }
    }
    else//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED],[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    {
        if(pNode->m_pLeft && pNode->m_pRight)//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        {
            TNodeTypePtr pTempNode = pNode->m_pRight;//temp[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
            while(pTempNode->m_pLeft != NULL)
            {
                pTempNode = pTempNode->m_pLeft;//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
            }

            //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
            pNode->m_Key  = pTempNode->m_Key;
            pNode->m_Data = pTempNode->m_Data;

            if(!DeleteInner(pNode->m_pRight, pTempNode->m_Key))//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
            {
                return false;
            }

            if((GetHeight(pNode->m_pLeft) - GetHeight(pNode->m_pRight)) >= 2)
            {
                if(pNode->m_pLeft->m_pRight != NULL && (GetHeight(pNode->m_pLeft->m_pRight) > GetHeight(pNode->m_pLeft->m_pLeft) ))
                {
                    DoubleRotateLR(pNode);
                }
                else
                {
                    SingRotateLeft(pNode);
                }
            }
        }
        else//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]1[TRANSLATED][TRANSLATED]0[TRANSLATED][TRANSLATED][TRANSLATED]
        {
            TNodeTypePtr pOrgParentNode = pNode->m_pParent;
            TNodeTypePtr pTempNode = pNode;

            if(pNode->m_pLeft == NULL)//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
            {
                pNode = pNode->m_pRight;
            }
            else if(pNode->m_pRight == NULL)//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
            {
                pNode = pNode->m_pLeft;
            }

            if(pNode != NULL)
            {
                pNode->m_pParent = pOrgParentNode;
            }

            FreeNode(pTempNode);

            m_nCount--;
        }
    }

    if(pNode == NULL)
    {
        return false;
    }
    
    pNode->m_nHeight = Max(GetHeight(pNode->m_pLeft), GetHeight(pNode->m_pRight)) + 1;

    return true;
}


//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
bool AVLTree<TKey, TValue>::Delete(TKey Key)
{
    return DeleteInner(m_pRoot, Key);
}
//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::Insubtree(TNodeTypePtr pNode)
{
    if(pNode == NULL)
    {
        return;
    }

    Insubtree(pNode->m_pLeft);//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    DoEnumNode(pNode);
    Insubtree(pNode->m_pRight);//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
}
//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::Traversal()
{
    Insubtree(m_pRoot);
}

template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::DoEnumNode( TNodeTypePtr pNode )
{

}

#endif
