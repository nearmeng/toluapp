//tolua_begin
#define TEST_DEFINE (2.1)

enum TEST_ENUM 
{
	teInvalid,


	teTotal = 100,
};

class CTest
{
public:
	CTest() {};
	~CTest() {};

	int TestInt(int p);
	unsigned int TestUInt(unsigned int p);
	long long TestLL(long long p);
	unsigned long long TestULL(unsigned long long p);
	float TestFloat(float p);
	double TestDouble(double p);
	short TestShort(short p);
	char* TestStr(char* p);
	const char* TestCStr(const char* p);
	bool TestBoolean(bool p);

	int IntArray[teTotal];
	unsigned int UIntArray[teTotal];
	long long LLArray[teTotal];
	unsigned long long ULLArray[teTotal];
	float FloatArray[teTotal];
	double DoubleArray[teTotal];
	char* StrArray[teTotal];
	const char* CStrArray[teTotal];
	bool BooleanArray[teTotal];

	struct EMBEDDED
	{
		int IntArray[teTotal];
		unsigned int UIntArray[teTotal];
		long long LLArray[teTotal];
		unsigned long long ULLArray[teTotal];
		float FloatArray[teTotal];
		double DoubleArray[teTotal];
		char* StrArray[teTotal];
		const char* CStrArray[teTotal];
		bool BooleanArray[teTotal];
	}  Embedded;

	EMBEDDED e[teTotal];
};

//tolua_end
