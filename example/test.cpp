// test.cpp : Defines the entry point for the console application.
//

#include "test.h"
extern "C"
{
#include "lua.h"
#include "lualib.h"
}
#include "toluapp.h"

int CTest::TestInt(int p)
{
	return p;
}

unsigned int CTest::TestUInt(unsigned int p)
{
	return p;
}

long long CTest::TestLL(long long p)
{
	return p;
}

unsigned long long CTest::TestULL(unsigned long long p)
{
	return p;
}

float CTest::TestFloat(float p)
{
	return p;
}

double CTest::TestDouble(double p)
{
	return p;
}

short CTest::TestShort(short p)
{
	return p;
}

char* CTest::TestStr(char* p)
{
	return p;
}

const char* CTest::TestCStr(const char* p)
{
	return p;
}

bool CTest::TestBoolean(bool p)
{
	return p;
}

extern int tolua_test_open(lua_State* tolua_S);

int main()
{
	CTest t;

	t.IntArray[0] = 0x7FFFFFFF;
	t.IntArray[1] = 0xFFFFFFFF;
	t.UIntArray[0] = 0x7FFFFFFF;
	t.UIntArray[1] = 0xFFFFFFFF;
	t.LLArray[0] = 0x7FFFFFFFFFFFFFFF;
	t.LLArray[1] = 0xFFFFFFFFFFFFFFFF;
	t.ULLArray[0] = 0x7FFFFFFFFFFFFFFF;
	t.ULLArray[1] = 0xFFFFFFFFFFFFFFFF;
	t.FloatArray[0] = 12345.67890;
	t.DoubleArray[0] = 12345.67890;
	t.StrArray[0] = "StrArray";
	t.CStrArray[0] = "CStrArray";
	t.BooleanArray[0] = false;
	t.BooleanArray[1] = true;

	t.Embedded.IntArray[0] = 0x7FFFFFFF;
	t.Embedded.IntArray[1] = 0xFFFFFFFF;
	t.Embedded.UIntArray[0] = 0x7FFFFFFF;
	t.Embedded.UIntArray[1] = 0xFFFFFFFF;
	t.Embedded.LLArray[0] = 0x7FFFFFFFFFFFFFFF;
	t.Embedded.LLArray[1] = 0xFFFFFFFFFFFFFFFF;
	t.Embedded.ULLArray[0] = 0x7FFFFFFFFFFFFFFF;
	t.Embedded.ULLArray[1] = 0xFFFFFFFFFFFFFFFF;
	t.Embedded.FloatArray[0] = 12345.67890;
	t.Embedded.DoubleArray[0] = 12345.67890;
	t.Embedded.StrArray[0] = "StrArray";
	t.Embedded.CStrArray[0] = "CStrArray";
	t.Embedded.BooleanArray[0] = false;
	t.Embedded.BooleanArray[1] = true;

	//while (1)
	{
		lua_State* L = luaL_newstate();
		luaL_openlibs(L);
		tolua_test_open(L);

		luaL_dostring(L,
			"function test(t)\
		print(TEST_DEFINE);\
		print(TEST_ENUM.teTotal);\
		print(t:TestInt(1234567890));\
		print(t:TestInt(1234567890987654321));\
		print(t:TestUInt(-12345678));\
		print(t:TestUInt(0xFFFFFFFF));\
		print(t:TestLL(0x7FFFFFFFFFFFFFFF));\
		print(t:TestLL(0xFFFFFFFFFFFFFFFF));\
		print(t:TestULL(0x7FFFFFFFFFFFFFFF));\
		print(t:TestULL(0xFFFFFFFFFFFFFFFF));\
		print(t:TestFloat(12345.67890));\
		print(t:TestFloat(123456789.987654321));\
		print(t:TestDouble(123456789.987654321));\
		print(t:TestShort(12345));\
		print(t:TestShort(123456));\
		print(t:TestStr(\"1234567890\"));\
		print(t:TestCStr(\"1234567890\"));\
		print(t:TestBoolean(true));\
		print(t:TestBoolean(false));\
		print('-------------------');\
		print(t.IntArray[0]);\
		print(t.IntArray[1]);\
		print(t.UIntArray[0]);\
		print(t.UIntArray[1]);\
		print(t.LLArray[0]);\
		print(t.LLArray[1]);\
		print(t.ULLArray[0]);\
		print(t.ULLArray[1]);\
		print(t.FloatArray[0]);\
		print(t.DoubleArray[0]);\
		print(t.StrArray[0]);\
		print(t.CStrArray[0]);\
		print(t.BooleanArray[0]);\
		print(t.BooleanArray[1]);\
		print('-------------------');\
		print(t.Embedded.IntArray[0]);\
		print(t.Embedded.IntArray[1]);\
		print(t.Embedded.UIntArray[0]);\
		print(t.Embedded.UIntArray[1]);\
		print(t.Embedded.LLArray[0]);\
		print(t.Embedded.LLArray[1]);\
		print(t.Embedded.ULLArray[0]);\
		print(t.Embedded.ULLArray[1]);\
		print(t.Embedded.FloatArray[0]);\
		print(t.Embedded.DoubleArray[0]);\
		print(t.Embedded.StrArray[0]);\
		print(t.Embedded.CStrArray[0]);\
		print(t.Embedded.BooleanArray[0]);\
		print(t.Embedded.BooleanArray[1]);\
		print('-------------------');\
		obj = CTest:new();\
		obj.IntArray[0] = 10;\
		print(obj.IntArray[0]);\
		obj:delete();\
		end");

		lua_getglobal(L, "test");
		tolua_pushusertype(L, &t, "CTest");
		lua_call(L, 1, 0);

		lua_close(L);
	}

    return 0;
}

