/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerEngine___DataBuffer.h */
#ifndef _DATA_BUFFER_H_
#define _DATA_BUFFER_H_
#include "IBufferHandler.h"

template <int SIZE>
class  CBufferManager;

#define HEADER_LEN 28

template <int SIZE>
class CDataBuffer : public IDataBuffer
{
public:
    CDataBuffer(void)
    {
        m_nDataLen      = 0;
        m_nBufSize      = SIZE;
        m_nRefCount     = 0;
        m_pPrev         = NULL;
        m_pNext         = NULL;
        m_pManager      = NULL;
    }

    virtual ~CDataBuffer(void)
    {
        m_nDataLen = 0;
        m_nBufSize = SIZE;
        m_nRefCount = 0;
        m_pPrev = NULL;
        m_pNext = NULL;
        m_pManager = NULL;
    }

    BOOL AddRef()
    {
        m_pManager->m_BuffMutex.lock();
        m_nRefCount++;
        m_pManager->m_BuffMutex.unlock();
        return TRUE;
    }

    BOOL Release()
    {
        assert(m_pManager != NULL);

        m_pManager->ReleaseDataBuff(this);

        return TRUE;
    }

    CHAR* GetData()
    {
        return m_Buffer + HEADER_LEN;
    }

    INT32 GetTotalLenth()
    {
        return m_nDataLen;
    }

    INT32 GetBodyLenth()
    {
        return m_nDataLen - HEADER_LEN;
    }

    VOID SetTotalLenth(INT32 nPos)
    {
        m_nDataLen = nPos;
    }

    CHAR* GetBuffer()
    {
        return m_Buffer;
    }

    INT32 GetBufferSize()
    {
        return m_nBufSize;
    }

    INT32  CopyFrom(IDataBuffer* pSrcBuffer)
    {
        memcpy(m_Buffer, pSrcBuffer->GetBuffer(), pSrcBuffer->GetTotalLenth());

        m_nDataLen = pSrcBuffer->GetTotalLenth();

        return m_nDataLen;
    }

    INT32  CopyTo(CHAR* pDestBuf, INT32 nDestLen)
    {
        if(nDestLen < GetTotalLenth())
        {
            return 0;
        }

        memcpy(pDestBuf, GetBuffer(), GetTotalLenth());

        return nDestLen;
    }

    CDataBuffer<SIZE>* m_pPrev;

    CDataBuffer<SIZE>* m_pNext;

    CBufferManager<SIZE>* m_pManager;

public:
    INT32       m_nRefCount;

    INT32       m_nBufSize;

    CHAR        m_Buffer[SIZE];

    INT32       m_nDataLen;
};

template <int SIZE>
class  CBufferManager
{
public:
    CBufferManager()
    {
        m_pUsedList = NULL;
        m_pFreeList = NULL;
        m_nBufferCount = 0;
        m_EnablePool = TRUE;
    }

    ~CBufferManager()
    {
        ReleaseAll();
    }

    IDataBuffer* AllocDataBuff()
    {
        m_BuffMutex.lock();
        CDataBuffer<SIZE>* pDataBuffer = NULL;
        if(m_pFreeList == NULL)
        {
            pDataBuffer = new CDataBuffer<SIZE>();
            pDataBuffer->m_pManager = this;
        }
        else
        {
            pDataBuffer = m_pFreeList;

            m_pFreeList = m_pFreeList->m_pNext;

            if(m_pFreeList != NULL)
            {
                m_pFreeList->m_pPrev = NULL;
            }

            pDataBuffer->m_pNext = NULL;
            pDataBuffer->m_pPrev = NULL;
        }

        assert(pDataBuffer->m_nRefCount == 0);

        pDataBuffer->m_nRefCount = 1;

        if(m_pUsedList == NULL)
        {
            m_pUsedList = pDataBuffer;
        }
        else
        {
            pDataBuffer->m_pNext = m_pUsedList;
            m_pUsedList->m_pPrev = pDataBuffer;
            pDataBuffer->m_pPrev = NULL;
            m_pUsedList = pDataBuffer;
        }

        m_nBufferCount += 1;
        m_BuffMutex.unlock();
        return pDataBuffer;
    }

    BOOL ReleaseDataBuff(CDataBuffer<SIZE>* pBuff)
    {
        assert(pBuff != NULL);
        if (pBuff == NULL)
        {
            return FALSE;
        }

        assert(pBuff->m_nRefCount > 0);
        if (pBuff->m_nRefCount <= 0)
        {
            return FALSE;
        }
        std::lock_guard<std::mutex> lock(m_BuffMutex);
        pBuff->m_nRefCount--;

        if (pBuff->m_nRefCount <= 0)
        {
            pBuff->m_nDataLen = 0;
            //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
            if (m_pUsedList == pBuff)
            {
                //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
                m_pUsedList = pBuff->m_pNext;
                if (m_pUsedList != NULL)
                {
                    m_pUsedList->m_pPrev = NULL;
                }
            }
            else
            {
                assert(pBuff->m_pPrev != NULL);
                pBuff->m_pPrev->m_pNext = pBuff->m_pNext;
                if (pBuff->m_pNext != NULL)
                {
                    pBuff->m_pNext->m_pPrev = pBuff->m_pPrev;
                }
            }

            if (m_EnablePool)
            {
                //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
                pBuff->m_pNext = m_pFreeList;
                pBuff->m_pPrev = NULL;
                m_pFreeList = pBuff;

                if (pBuff->m_pNext != NULL)
                {
                    pBuff->m_pNext->m_pPrev = pBuff;
                }
            }
            else
            {
                delete pBuff;
            }
            m_nBufferCount--;
        }
        return TRUE;
    }

    void ReleaseAll()
    {
        CDataBuffer<SIZE>* pBufferNode = m_pFreeList;
        while (pBufferNode)
        {
            CDataBuffer<SIZE>* pTempNode = pBufferNode;
            pBufferNode = pTempNode->m_pNext;
            delete pTempNode;
        }

        pBufferNode = m_pUsedList;
        while (pBufferNode)
        {
            CDataBuffer<SIZE>* pTempNode = pBufferNode;
            pBufferNode = pTempNode->m_pNext;
            delete pTempNode;
        }

        return;
    }

    VOID SetEnablePool(BOOL bEnablePool)
    {
        m_EnablePool = bEnablePool;
    }

    void PrintOutList(CDataBuffer<SIZE>* pList)
    {
        INT32 nCount = 0;
        CDataBuffer<SIZE>* pBufferNode = pList;
        if(pBufferNode == NULL)
        {
            return ;
        }

        BOOL bNext = TRUE;
        while(pBufferNode)
        {
            if(bNext)
            {
                nCount++;
                if(pBufferNode->m_pNext != NULL)
                {
                    pBufferNode = pBufferNode->m_pNext;
                }
                else
                {
                    bNext = FALSE;
                    pBufferNode = pBufferNode->m_pPrev;
                }
            }
            else
            {
                nCount++;
                pBufferNode = pBufferNode->m_pPrev;
            }
        }

        return ;
    }

    CDataBuffer<SIZE>* m_pFreeList;

    CDataBuffer<SIZE>* m_pUsedList;

    std::mutex  m_BuffMutex;

    INT32       m_nBufferCount;

    BOOL        m_EnablePool;
private:
};

class CBufferAllocator
{
    CBufferAllocator();
    ~CBufferAllocator();
public:
    static CBufferAllocator* GetInstancePtr();

public:
    IDataBuffer* AllocDataBuff(int nSize);

    CBufferManager<64>     m_BufferManager64B;      //[TRANSLATED][TRANSLATED]<=64B[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
    CBufferManager<128>    m_BufferManager128B;     //[TRANSLATED][TRANSLATED]<=128B[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
    CBufferManager<256>    m_BufferManager256B;     //[TRANSLATED][TRANSLATED]<=256B[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
    CBufferManager<512>    m_BufferManager512B;     //[TRANSLATED][TRANSLATED]<=512B[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
    CBufferManager<1024>   m_BufferManager1K;       //[TRANSLATED][TRANSLATED]<=1k[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
    CBufferManager<2048>   m_BufferManager2K;       //[TRANSLATED][TRANSLATED]<=2k[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
    CBufferManager<4096>   m_BufferManager4K;       //[TRANSLATED][TRANSLATED]<=4k[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
    CBufferManager<8192>   m_BufferManager8K;       //[TRANSLATED][TRANSLATED]<=8k[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
    CBufferManager<16384>  m_BufferManager16K;      //[TRANSLATED][TRANSLATED]<=16k[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
    CBufferManager<32768>  m_BufferManager32K;      //[TRANSLATED][TRANSLATED]<=32k[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
    CBufferManager<65536>  m_BufferManager64K;      //[TRANSLATED][TRANSLATED]<=64k[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，

    CBufferManager<10 * 1024 * 1014> m_BufferManagerAny;        //[TRANSLATED][TRANSLATED]<=10M[TRANSLATED][TRANSLATED][TRANSLATED], [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED], [TRANSLATED][TRANSLATED]apply, [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED].
};

#endif