/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerEngine___AstarFinder.h */
#ifndef __ASTAR_FINDER_H__
#define __ASTAR_FINDER_H__

#define TILESIZE 1			// change this also to reflect tile size. 64x64.
#define MAPDATANOCOPY		//use the pointer for mapdata

//[TRANSLATED][TRANSLATED]
/* [TRANSLATED]TileMap[TRANSLATED][TRANSLATED]， [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED]is1[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]， 0:[TRANSLATED][TRANSLATED]can[TRANSLATED][TRANSLATED]*/



class EngineClass AstarFinder
{
	struct NODE       // node structure
	{
		long f, h;
		int g, tmpg;
		int x, y;
		int NodeNum;
		NODE* Parent;
		NODE* Child[8];  // a node may have upto 8+(NULL) children.
		NODE* NextNode;  // for filing purposes
	};

	struct STACK        // the stack structure
	{
		NODE*		pNode;
		STACK*		pNextStack;
	};
public:
	AstarFinder(void);
	~AstarFinder();

	BOOL	InitAstarMap(BYTE* pMap, INT32 w, INT32 h);
	BOOL	NewPath(int sx, int sy, int dx, int dy);
	BOOL	IsReached(void);
	BOOL	PathNextNode(void);
	INT32	NodeGetX();
	INT32	NodeGetY();
	INT32	GetTileNum(int x, int y);
	INT32	IsTileAviable(int x, int y); ////is[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

private:
	void	FreeNodes(void);
	void	FindPath(int sx, int sy, int dx, int dy);
	NODE*	GetBestNode(void);
	void	GenerateSuccessors(NODE* BestNode, int dx, int dy);
	void	GenerateSucc(NODE* BestNode, int x, int y, int dx, int dy);
	NODE*	CheckOPEN(int tilenum);
	NODE*	CheckCLOSED(int tilenum);
	void	Insert(NODE* Successor);
	void	PropagateDown(NODE* Old);
	void	Push(NODE* Node); // stack functions
	NODE*	Pop(void);

	NODE*	m_pOpenList;    // the node list pointers
	NODE*	m_pClosedList;
	NODE*	m_pCurPath;    // pointer to the best path
	STACK*	m_pStack;

	int		m_nRowCnt;			// tilemap data members, need to be initialisize
	int		m_nColCnt;			// with current map's width and height
	int		m_nTotalTiles;	// to allocate memory for the
	BYTE*	m_pTileMap;		// pointer to the A* own tilemap data array
};



#endif //__ASTAR_FINDER_H__