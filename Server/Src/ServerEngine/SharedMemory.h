/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerEngine___SharedMemory.h */
﻿#ifndef __SHARE_MEMORY_H__
#define __SHARE_MEMORY_H__
#include "DBInterface/DBInterface.h"

#define BLOCK_CHECK_CODE    0x5A

/**[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
*/
enum SharedMemoryStatus
{
    SMS_NONE,       //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    SMS_USE,        //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED]servercan[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    SMS_LOCK,       //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED]server[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    SMS_RELEASE,    //[TRANSLATED][TRANSLATED]server[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。[TRANSLATED][TRANSLATED][TRANSLATED]server[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]can[TRANSLATED]isSMS_NONE[TRANSLATED][TRANSLATED]
    SMS_DELETE,     //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
};

///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]sharedMemory[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]ShareObject[TRANSLATED][TRANSLATED][TRANSLATED]
class ShareObject
{
public:
    ShareObject();

    ///begin[TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED]is[TRANSLATED][TRANSLATED][TRANSLATED]
    void Lock();

    ///[TRANSLATED][TRANSLATED]is[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。
    void Unlock();

    ///[TRANSLATED][TRANSLATED]is[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    void Release();

    //[TRANSLATED][TRANSLATED]is[TRANSLATED][TRANSLATED]
    void Destroy();

    void UseIt();

    void Reset();

    BOOL IsLock()const;

    BOOL IsDestroy() const;

    BOOL IsRelease() const;

    BOOL IsUse() const;

    time_t getLastMotifyTime();

    SharedMemoryStatus GetStatus();

    INT32 GetCheckCode();

private:
    INT32                      m_nCheckCode;
    SharedMemoryStatus         m_Status;
    time_t                     m_UpdateTime;    ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
};

///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]T[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
struct _SMBlock
{
    INT32           m_nIndex;      //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    BOOL            m_bUse;         //whether[TRANSLATED][TRANSLATED][TRANSLATED]true[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，false[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    BOOL            m_bNewBlock;    //whether[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    time_t          m_beforeTime;   //DSserver[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。
    time_t          m_afterTime;
    _SMBlock()
    {
        m_nIndex = 0;
        m_bUse = false;
        m_beforeTime = 0;
        m_afterTime = 0;
        m_bNewBlock = false;
    }
};

///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
struct shareMemoryPage
{
    char*        m_pdata;///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    _SMBlock*    m_pBlock;///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]position
    HANDLE       m_shm;///
};

class SharedMemoryBase
{
public:
    SharedMemoryBase(INT32 nModuleID, INT32 rawblockSize, INT32 nCountPerPage, BOOL noCreate = false);

    SharedMemoryBase(INT32 rawblockSize, char* pdata, INT32 len);

    virtual ~SharedMemoryBase();
protected:

    typedef std::vector<shareMemoryPage> ShareMemoryPageMapping;
    ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED].
    ShareMemoryPageMapping m_ShareMemoryPageMapping;

    INT32           m_nCountperPage;    ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Ttypecount
    INT32           m_nPageCount;   ///[TRANSLATED]count
    INT32           m_nCount;       ///Ttype[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED],Ttype[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。
    INT32           m_nSpace;       ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32           m_rawblockSize;
    INT32           m_nModuleID;
    BOOL            m_bEmpty;

    ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    typedef  std::map<INT32, _SMBlock*>    mapSMBlock;
    mapSMBlock                     m_mapSMBlock;///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

    typedef std::map<void*, _SMBlock*>  mapUsedSMBlock;
    mapUsedSMBlock                 m_mapUsedSMBlock;    ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

    typedef std::map<INT32, _SMBlock*> mapFreeSMBlock;
    mapFreeSMBlock                 m_mapFreeSMBlock;///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
private:
    ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    BOOL NewPage();
    /**
    * @brief        [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    * @details      [TRANSLATED][TRANSLATED][TRANSLATED]0，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    * @param[in]    rPage : [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    * @return       void
    * @remarks
    */
    void InitPage(shareMemoryPage& rPage);

public:
    ///[TRANSLATED][TRANSLATED][TRANSLATED]server[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]map,[TRANSLATED][TRANSLATED]server[TRANSLATED][TRANSLATED][TRANSLATED],[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    void InitToMap();

    /**whether[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]*/
    BOOL IsFirstCreated();

    /**[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]*/
    void ImportOtherPage();

    /**[TRANSLATED][TRANSLATED]count*/
    const INT32 GetCount()const;

    /**[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]    */
    INT32 GetFreeCount()const;

    ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32 GetUseCount()const;

    /**[TRANSLATED][TRANSLATED]id[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]*/
    virtual _SMBlock* GetSMBbyRawIndex(INT32 index);

    /**[TRANSLATED][TRANSLATED]id[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]*/
    virtual ShareObject*  GetObjectByRawindex(INT32 index);

    const INT32 GetRawMemoryBlockSize();

    const INT32 GetBlockSize();

    /*handle[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]server[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]*/
    void ProcessCleanDirtyData();

    /*[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED],[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    @param isNewBlock istrue[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]saveobject [TRANSLATED]Create[TRANSLATED][TRANSLATED][TRANSLATED]
    */
    virtual ShareObject* NewObject(BOOL isNewBlock = false);

    /**[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]*/
    virtual BOOL DestoryObject(ShareObject* pobject);

    mapUsedSMBlock& GetUsedDataList();
};

template<typename T>
class SharedMemory : public SharedMemoryBase
{
public:
    SharedMemory(INT32 nModuleID, INT32 nCountPerPage, BOOL noCreate = false)
        : SharedMemoryBase(nModuleID, sizeof(T), nCountPerPage, noCreate)
    {

    }

    T*  GetObjectByRawindex(INT32 index)
    {
        return static_cast<T*>(SharedMemoryBase::GetObjectByRawindex(index));
    }

    T* NewObject(BOOL isNewBlock = false)
    {
        T* pTmp = static_cast<T*>(SharedMemoryBase::NewObject(isNewBlock));
        if (pTmp == NULL)
        {
            return NULL;
        }

        new(pTmp)(T);
        return pTmp;
    }

    _SMBlock* GetSMBbyRawIndex(INT32 index)
    {
        return SharedMemoryBase::GetSMBbyRawIndex(index);
    }

    BOOL DestoryObject(T* pobject)
    {
        return SharedMemoryBase::DestoryObject(pobject);
    }
};

class DataWriterBase
{
public:
    DataWriterBase() {};

    virtual ~DataWriterBase() {};

    virtual BOOL SaveModifyToDB(IDBInterface* pdb) = 0;

    virtual INT32 GetErrorCount() = 0;
};

template <typename T> class DataWriter : public DataWriterBase
{
public:
    DataWriter(INT32 nModuleID, INT32 nCount)
    {
        m_MemoryPool = NULL;
        m_nModuleID = nModuleID;
        m_nCount = nCount;
        m_nErrorCount = 0;
    }

    ~DataWriter()
    {
        delete m_MemoryPool;
        m_MemoryPool = NULL;
        m_nErrorCount = 0;
    }

    INT32 GetErrorCount()
    {
        return m_nErrorCount;
    }

    /**[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]*/
    BOOL SaveModifyToDB(IDBInterface* pdb)
    {
        ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        if (m_MemoryPool == NULL)
        {
            m_MemoryPool = new SharedMemory<T>(m_nModuleID, m_nCount, true);
        }
        if (m_MemoryPool == NULL)
        {
            return FALSE;
        }

        if (m_MemoryPool->IsFirstCreated())
        {
            ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
            delete m_MemoryPool;
            m_MemoryPool = NULL;
            return FALSE;
        }

        m_nErrorCount = 0;
        UINT64 uTickStart = CommonFunc::GetTickCount();

        INT32 nCreateCount = 0, nUpdateCount = 0, nDeleteCount = 0, nRealseCount = 0;
        BOOL hasOprate = false;
        ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED],getRawMemoryBlockSize[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，
        INT32 nTemblockSize = m_MemoryPool->GetRawMemoryBlockSize();
        for (INT32 r = 0; r < nTemblockSize; r++)
        {
            _SMBlock* pBlock = m_MemoryPool->GetSMBbyRawIndex(r);
            if (pBlock == NULL)
            {
                continue;
            }
            if (pBlock->m_bUse == FALSE)
            {
                continue;
            }

            T* pdata = m_MemoryPool->GetObjectByRawindex(r);
            if (pdata == NULL)
            {
                CLog::GetInstancePtr()->LogError("SaveModifyToDB Error pData is NULL, ModuleID:[%d]--RawIndex:[%d]", m_nModuleID, r);
                m_nErrorCount++;
                continue;
            }

            if (pdata->GetCheckCode() != BLOCK_CHECK_CODE)
            {
                CLog::GetInstancePtr()->LogError("SaveModifyToDB Error Memory Crash, ModuleID:[%d]--RawIndex:[%d]", m_nModuleID, r);
                m_nErrorCount++;
                continue;
            }

            if (!pdata->IsUse())
            {
                continue;
            }

            if (pdata->IsLock())
            {
                continue;
            }

            if (pdata->IsDestroy())
            {
                if (!pdata->Delete(pdb))
                {
                    m_nErrorCount++;
                    continue;
                }

                m_MemoryPool->DestoryObject(pdata);
                hasOprate = true;
                nDeleteCount++;
                continue;
            }
            ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
            if (pBlock->m_bNewBlock)
            {
                pBlock->m_beforeTime = time(0);
                if (!pdata->Create(pdb))
                {
                    m_nErrorCount++;
                    continue;
                }
                pBlock->m_bNewBlock = FALSE;
                pBlock->m_afterTime = time(0);
                hasOprate = true;
                nCreateCount++;
                continue;
            }

            time_t lastMotifyTime;
            time_t beforeTime, afterTime;
            lastMotifyTime = pdata->getLastMotifyTime();
            beforeTime = pBlock->m_beforeTime;
            afterTime = pBlock->m_afterTime;
            BOOL bNeedSave = FALSE;
            if (afterTime >= beforeTime)
            {
                if (lastMotifyTime > beforeTime)
                {
                    bNeedSave = true;
                }
            }
            else
            {
                bNeedSave = true;
            }

            if (bNeedSave)
            {
                pBlock->m_beforeTime = time(0);
                if (!pdata->Update(pdb))
                {
                    m_nErrorCount++;
                    continue;
                }
                hasOprate = true;
                nUpdateCount++;
                pBlock->m_afterTime = time(0);
                continue;
            }

            if (pdata->IsRelease())
            {
                ///[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]...[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Success[TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
                if ((lastMotifyTime > 0) && (afterTime < beforeTime || lastMotifyTime > beforeTime))
                {
                    pBlock->m_beforeTime = time(0);
                    if (!pdata->Update(pdb))
                    {
                        m_nErrorCount++;
                        continue;
                    }
                    hasOprate = true;
                    nUpdateCount++;
                    pBlock->m_afterTime = time(0);
                }
                m_MemoryPool->DestoryObject(pdata);
                nRealseCount++;
            }
        }

        UINT64 uTickEnd = CommonFunc::GetTickCount();
        if(nCreateCount > 0 || nCreateCount > 0 || nUpdateCount > 0 || nDeleteCount > 0 || nRealseCount > 0 || m_nErrorCount > 0)
        {
            CLog::GetInstancePtr()->LogInfo("ModuleID:[%02d]--Create:[%d]--Update:[%d]--Delete:[%d]--Release:[%d]--Error:[%d]--Time:[%d]", m_nModuleID, nCreateCount, nUpdateCount, nDeleteCount, nRealseCount, m_nErrorCount, uTickEnd - uTickStart);
        }

        return hasOprate;
    }
private:
    SharedMemory<T>*    m_MemoryPool; //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32               m_nCount;     //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32               m_nModuleID;  //[TRANSLATED][TRANSLATED]ID
    INT32               m_nErrorCount;
};

#endif