/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerEngine___DBInterface___CppMysql.h */
#ifndef __MYSQL_HELPER_H__
#define __MYSQL_HELPER_H__

#include "mysql.h"

class CppMySQL3DB;

class CppMySQLQuery
{
    friend class CppMySQL3DB;
public:
    CppMySQLQuery();

    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    CppMySQLQuery(CppMySQLQuery& rQuery);

    // [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]， = [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    CppMySQLQuery& operator=(CppMySQLQuery& rQuery);

    virtual ~CppMySQLQuery();

    int numRow();

    int numFields();

    int fieldIndex(const char* szField);

    //0...n-1[TRANSLATED]
    const char* fieldName(int nCol);
    int fieldType(int nCol);

    int seekRow(int offerset);
    int getIntField(int nField, int nNullValue = 0);
    int getIntField(const char* szField, int nNullValue = 0);

    INT64 getInt64Field(int nField, INT64 nNullValue = 0);
    INT64 getInt64Field(const char* szField, INT64 nNullValue = 0);

    double getFloatField(int nField, double fNullValue = 0.0);
    double getFloatField(const char* szField, double fNullValue = 0.0);

    //0...n-1[TRANSLATED]
    const char* getStringField(int nField, const char* szNullValue = "");
    const char* getStringField(const char* szField, const char* szNullValue = "");

    const unsigned char* getBlobField(int nField, int& nLen);
    const unsigned char* getBlobField(const char* szField, int& nLen);

    bool fieldIsNull(int nField);
    bool fieldIsNull(const char* szField);

    bool eof();

    void nextRow();

private:
    void freeRes();

private:
    MYSQL_RES*  m_MysqlRes;
    MYSQL_FIELD* _field;
    MYSQL_ROW  _row;
    int   _row_count;
    int   _field_count;
};

class CppMySQL3DB
{
public:
    CppMySQL3DB();
    virtual ~CppMySQL3DB();

    bool open(const char* host, const char* user, const char* passwd, const char* db,
              unsigned int port, const char* charSetName = "utf8mb4");

    bool setOpenParam(const char* host, const char* user, const char* passwd, const char* db,
                      unsigned int port, const char* charSetName = "utf8mb4");

    void close();

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] */
    MYSQL* getMysql();

    /* handle[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] */
    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]is[TRANSLATED]CppMySQLQuery[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]_mysql_res[TRANSLATED]is[TRANSLATED]
    CppMySQLQuery& querySQL(const char* sql, bool recon = true);

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] */
    int execSQL(const char* sql, bool recon = true);

    /* [TRANSLATED][TRANSLATED]mysqlserverwhether[TRANSLATED][TRANSLATED] */
    bool ping();

    /* shutdownmysql server */
    bool shutDown();

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]:[TRANSLATED][TRANSLATED]startmysql server */
    bool reboot();

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]:[TRANSLATED][TRANSLATED]connectionmysql server */
    bool reconnect();

    /*[TRANSLATED][TRANSLATED]:[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]InnoDB or BDB[TRANSLATED]type*/
    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]:begin[TRANSLATED][TRANSLATED] */
    bool startTransaction();

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]:[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] */
    bool commit();

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]:[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] */
    bool rollback();

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] */
    const char* getClientInfo();

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]:[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] */
    const unsigned long  getClientVersion();

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]:[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] */
    const char* getHostInfo();

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]:[TRANSLATED][TRANSLATED]Server information */
    const char* GetServerInfo();

    const char* GetErrorMsg();

    int         GetErrorNo();

    /*[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]:[TRANSLATED][TRANSLATED]server[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]*/
    const unsigned long  GetDBVersion();

    /*[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]:[TRANSLATED][TRANSLATED] [TRANSLATED][TRANSLATED]connection[TRANSLATED]Default[TRANSLATED][TRANSLATED][TRANSLATED]*/
    const char*   getCharacterSetName();

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] */
    int createDB(const char* name);

    /* [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]*/
    int dropDB(const char* name);

    /*[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]*/
    bool changeCurDB(const char* name);

    INT64 GetAutoIncrementID(const char* szTableName, const char* szDBName);

    bool  SetAutoIncrementID(INT64 nId, const char* szTableName, const char* szDBName);

private:
    CppMySQL3DB(const CppMySQL3DB& db);
    CppMySQL3DB& operator=(const CppMySQL3DB& db);

private:
    /* msyql connection[TRANSLATED][TRANSLATED] */
    MYSQL* m_pMySqlDB;
    CppMySQLQuery m_dbQuery;

    int          m_nErrNo;
    std::string  m_strError;


    std::string  m_strHost;
    std::string  m_strUser;
    std::string  m_strPwd;
    std::string  m_strDB;
    std::string  m_strCharSet; //[TRANSLATED][TRANSLATED][TRANSLATED]
    int          m_nPort;
};

#endif //__MYSQL_HELPER_H__