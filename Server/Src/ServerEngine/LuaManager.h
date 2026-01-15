/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerEngine___LuaManager.h */
#ifndef __LUA_MANAGER_H__
#define __LUA_MANAGER_H__

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class CLuaHelper
{
public:
	CLuaHelper(void);
	~CLuaHelper(void);

public:
	lua_State* GetLuaState();

	BOOL	Attach(lua_State* L);

	BOOL	Deattch();

	BOOL	LoadAllLua(std::string strDir);

	BOOL	LoadAllLua(const char* pszDir);

	BOOL	LoadScriptFile(const char* pszLuaFile);

	BOOL	LoadScriptFile(std::vector<std::string>& vtScriptList);

	BOOL    DoLuaScript(std::string strLuaScript);

	BOOL	CallLuaFunction(std::string strFuncName, char* pStrParamSig, ...);

	BOOL	CallLuaTableFunc(std::string strTableName, std::string strFuncName, char* pStrParamSig, ...);

	BOOL	GetStackParams(char* pStrParamSig, ...);

	BOOL    RegisterFunction(const char* pszLibName, const luaL_Reg* l);

	BOOL	RegisterFunction(const char* name, lua_CFunction fn);

	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL	GetStackValue_Ptr(INT32 nStackIndex, VOID*& ptrValue);
	BOOL	GetStackValue_Int(INT32 nStackIndex, INT32& intValue);
	BOOL	GetStackValue_Double(INT32 nStackIndex, DOUBLE& doubleValue);
	BOOL    GetStackValue_String(INT32 nStackIndex, const CHAR*& strValue);

	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	INT32	GetGlobalVarInt(const char* pszVarName);
	BOOL	GetGlobalVarBoolean(const char* pszVarName);
	DOUBLE  GetGlobalVarDouble(const char* pszVarName);
	const CHAR*	GetGlobalVarString(const char* pszVarName);

protected:

	lua_State*			m_pLuaState;
};

class CLuaManager : public CLuaHelper
{
private:
	CLuaManager(void);
	~CLuaManager(void);

public:
	BOOL	Init();

	BOOL	Close();
public:
	static CLuaManager* GetInstancePtr();
};



#endif