/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___MailData.h */
#ifndef __MAIL_DATA_OBJECT_H__
#define __MAIL_DATA_OBJECT_H__
#include "DBInterface/DBStoredProc.h"
#include "DBInterface/DBInterface.h"

struct StMailItem
{
    StMailItem(INT32 nID = 0, INT32 nNum = 0)
    {
        m_nItemID = nID;
        m_nItemNum = nNum;
    }
    INT32 m_nItemID;
    INT32 m_nItemNum;
};

struct GroupMailDataObject : public ShareObject
{
    GroupMailDataObject()
    {
        m_uGuid = 0;
        m_uTime = 0;
        m_nMailType = 0;
        m_nChannel = 0;
        m_nLanguage = -1;
        m_nGroupType = 0;
        memset(m_szTitle, 0, sizeof(CHAR) * MAIL_TITLE_LEN);
        memset(m_szContent, 0, sizeof(CHAR) * MAIL_CONTENT_LEN);
        memset(m_Items, 0, sizeof(StMailItem) * MAIL_ITEM_COUNT);
        memset(m_szSender, 0, sizeof(CHAR) * ROLE_NAME_LEN);
    }
    UINT64 m_uGuid;                         //[TRANSLATED][TRANSLATED]ID
    CHAR   m_szTitle[MAIL_TITLE_LEN];       //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    CHAR   m_szContent[MAIL_CONTENT_LEN];   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    CHAR   m_szSender[ROLE_NAME_LEN];       //[TRANSLATED][TRANSLATED][TRANSLATED]Name
    UINT64 m_uTime;                         //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32  m_nMailType;                    //[TRANSLATED][TRANSLATED]type
    INT32  m_nChannel;                     //target[TRANSLATED][TRANSLATED]
    INT32  m_nLanguage;                     //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    StMailItem m_Items[MAIL_ITEM_COUNT];    //[TRANSLATED][TRANSLATED]list
    INT32  m_nGroupType;                   //[TRANSLATED][TRANSLATED]type 1->[TRANSLATED][TRANSLATED]player  2->[TRANSLATED][TRANSLATED]player+[TRANSLATED][TRANSLATED]player

    BOOL Create(IDBInterface* pDB)
    {
        static CDBStoredProcedure csp("REPLACE INTO mail_group (id, title, content,sender, mail_time, mailtype, channel,language, grouptype, itemdata) \
			VALUES(?,?,?,?,?,?,?,?,?,?);");
        csp.set_uint64(0, m_uGuid);
        csp.set_string(1, m_szTitle, strlen(m_szTitle));
        csp.set_string(2, m_szContent, strlen(m_szContent));
        csp.set_string(3, m_szSender, strlen(m_szSender));
        csp.set_uint64(4, m_uTime);
        csp.set_int32(5, m_nMailType);
        csp.set_int32(6, m_nChannel);
        csp.set_int32(7, m_nLanguage);
        csp.set_int32(8, m_nGroupType);
        csp.set_tinyblob(9, m_Items, sizeof(StMailItem)*MAIL_ITEM_COUNT);
        return pDB->Execute(&csp);
    }

    BOOL Update(IDBInterface* pDB)
    {
        static CDBStoredProcedure csp("REPLACE INTO mail_group (id, title, content,sender,  mail_time, mailtype, channel,language, grouptype, itemdata) \
			VALUES(?,?,?,?,?,?,?,?,?,?);");
        csp.set_uint64(0, m_uGuid);
        csp.set_string(1, m_szTitle, strlen(m_szTitle));
        csp.set_string(2, m_szContent, strlen(m_szContent));
        csp.set_string(3, m_szSender, strlen(m_szSender));
        csp.set_uint64(4, m_uTime);
        csp.set_int32(5, m_nMailType);
        csp.set_int32(6, m_nChannel);
        csp.set_int32(7, m_nLanguage);
        csp.set_int32(8, m_nGroupType);
        csp.set_tinyblob(9, m_Items, sizeof(StMailItem)*MAIL_ITEM_COUNT);

        return pDB->Execute(&csp);
    }

    BOOL Delete(IDBInterface* pDB)
    {
        static CDBStoredProcedure csp("delete from mail_group where id = ?;");
        csp.set_uint64(0, m_uGuid);
        return pDB->Execute(&csp);
    }
};



struct MailDataObject : public ShareObject
{
    MailDataObject()
    {
        m_uRoleID = 0;
        m_uGuid = 0;
        m_uTime = 0;
        m_uSenderID = 0;
        m_nMailType = 0; //[TRANSLATED][TRANSLATED]type
        m_nStatus = 0;   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        m_uGroupGuid = 0; //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]ID
        memset(m_szSender, 0, sizeof(CHAR) * ROLE_NAME_LEN);
        memset(m_szTitle, 0, sizeof(CHAR) * MAIL_TITLE_LEN);
        memset(m_szContent, 0, sizeof(CHAR) * MAIL_CONTENT_LEN);
        memset(m_Items, 0, sizeof(StMailItem) * MAIL_ITEM_COUNT);
    }

    UINT64 m_uGuid;                         //[TRANSLATED][TRANSLATED]ID
    UINT64 m_uRoleID;                       //[TRANSLATED][TRANSLATED]ID
    UINT64 m_uGroupGuid;                    //[TRANSLATED][TRANSLATED][TRANSLATED]ID
    UINT64 m_uTime;                         //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    UINT64 m_uSenderID;                     //[TRANSLATED][TRANSLATED][TRANSLATED]ID
    INT32  m_nMailType;                    //[TRANSLATED][TRANSLATED]type
    INT32  m_nStatus;                      //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    CHAR   m_szSender[ROLE_NAME_LEN];       //[TRANSLATED][TRANSLATED][TRANSLATED]Name
    CHAR   m_szTitle[MAIL_TITLE_LEN];       //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    CHAR   m_szContent[MAIL_CONTENT_LEN];   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    StMailItem m_Items[MAIL_ITEM_COUNT];    //[TRANSLATED][TRANSLATED]list


    BOOL Create(IDBInterface* pDB)
    {
        static CDBStoredProcedure csp("REPLACE INTO mail (roleid, id, groupid, mailtype, mailstatus, senderid, sendername, title, content, mail_time, itemdata) \
			VALUES(?,?,?,?,?,?,?,?,?,?,?);");
        csp.set_uint64(0, m_uRoleID);
        csp.set_uint64(1, m_uGuid);
        csp.set_uint64(2, m_uGroupGuid);
        csp.set_int32(3, m_nMailType);
        csp.set_int32(4, m_nStatus);
        csp.set_uint64(5, m_uSenderID);
        csp.set_string(6, m_szSender, strlen(m_szSender));
        csp.set_string(7, m_szTitle, strlen(m_szTitle));
        csp.set_string(8, m_szContent, strlen(m_szContent));
        csp.set_uint64(9, m_uTime);
        csp.set_tinyblob(10, m_Items, sizeof(StMailItem)*MAIL_ITEM_COUNT);
        return pDB->Execute(&csp);
    }

    BOOL Update(IDBInterface* pDB)
    {
        static CDBStoredProcedure csp("REPLACE INTO mail (roleid, id, groupid, mailtype, mailstatus, senderid, sendername, title, content, mail_time, itemdata) \
			VALUES(?,?,?,?,?,?,?,?,?,?,?);");
        csp.set_uint64(0, m_uRoleID);
        csp.set_uint64(1, m_uGuid);
        csp.set_uint64(2, m_uGroupGuid);
        csp.set_int32(3, m_nMailType);
        csp.set_int32(4, m_nStatus);
        csp.set_uint64(5, m_uSenderID);
        csp.set_string(6, m_szSender, strlen(m_szSender));
        csp.set_string(7, m_szTitle, strlen(m_szTitle));
        csp.set_string(8, m_szContent, strlen(m_szContent));
        csp.set_uint64(9, m_uTime);
        csp.set_tinyblob(10, m_Items, sizeof(StMailItem)*MAIL_ITEM_COUNT);
        return pDB->Execute(&csp);
    }

    BOOL Delete(IDBInterface* pDB)
    {
        static CDBStoredProcedure csp("delete from mail where id = ?;");
        csp.set_uint64(0, m_uGuid);
        return pDB->Execute(&csp);
    }
};


struct OffDataObject : public ShareObject
{
    OffDataObject()
    {
        m_uRoleID = 0;
        m_nOpType = 0;

    }

    UINT32 m_nOpType;
    UINT64 m_uRoleID;                       //[TRANSLATED][TRANSLATED]ID
    union
    {
        UINT64          m_Parm64[4];
        UINT32          m_Parm32[8];
    } m_Param; //eventparams



    BOOL Create(IDBInterface* pDB)
    {
        return TRUE;
    }

    BOOL Update(IDBInterface* pDB)
    {
        return TRUE;
    }

    BOOL Delete(IDBInterface* pDB)
    {
        return TRUE;
    }
};



#endif //__MAIL_DATA_OBJECT_H__