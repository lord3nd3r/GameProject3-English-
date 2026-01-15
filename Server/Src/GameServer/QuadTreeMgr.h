/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___GameServer___QuadTreeMgr.h */
#ifndef __QUAD_TREE_MANAGER_H__
#define __QUAD_TREE_MANAGER_H__

#include "CommonMath.h"
#include "GameObject/MapObject.h"

#define NODE_SPLIT_NUM 8   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]begin[TRANSLATED][TRANSLATED]
#define NODE_MERGE_NUM 4   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]begin[TRANSLATED][TRANSLATED]
#define NODE_MAX_CHILD 4   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
#define NODE_MAX_DEPTH 5   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

struct QuadTreeNode
{
    QuadTreeNode();

    QuadTreeNode(QuadTreeNode* pParent, FLOAT fLeft, FLOAT fTop, FLOAT fRight, FLOAT fBottom, INT32 nDepth);

    BOOL InsertObject(CMapObject* pObject);

    BOOL RemoveObject(CMapObject* pObject);

    BOOL SearchObject(Rect2D rcArea, std::list<CMapObject*>& objectList);

    BOOL TrySplit();

    BOOL TryMerge();

    INT32 GetObjectCount();

    BOOL Contains(CPoint2D pt);

    BOOL Intersects(Rect2D rcArea);

    QuadTreeNode* GetTreeNodeByPos(FLOAT x, FLOAT z);
public:
    INT32  m_nDepth = 0;
    BOOL   m_bLeaf = TRUE;
    FLOAT m_fLeft = 0;
    FLOAT m_fTop = 0;
    FLOAT m_fBottom = 0;
    FLOAT m_fRight = 0;
    QuadTreeNode* m_pParent = NULL;
    QuadTreeNode* m_pChildNodes[NODE_MAX_CHILD] = { NULL };
    std::list<CMapObject*> m_objectList;
};

class CQuadTreeManager
{
public:
    CQuadTreeManager(void);
    ~CQuadTreeManager(void);

    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    BOOL        Init(FLOAT fLeft, FLOAT fTop, FLOAT fRight, FLOAT fBottom);

    BOOL        AddMapObject(CMapObject* pMapObject);

    BOOL        RemoveMapObject(CMapObject* pMapObject);

    BOOL        SearchObject(Rect2D rcArea, std::list<CMapObject*>& objectList);

    QuadTreeNode* GetTreeNodeByPos(FLOAT x, FLOAT z);

    QuadTreeNode* m_pTreeRoot;
};

#endif /*__QUAD_TREE_MANAGER_H__*/