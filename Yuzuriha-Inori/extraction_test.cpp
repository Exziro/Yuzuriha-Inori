#include<iostream>
using namespace std;
struct _TrueType
{
	bool Get()
	{
		return true;
	}
};
struct _FalseType
{
	bool Get()
	{
		return false;
	}
};
template<class _Tp>
struct TypeTraists
{
	typedef _FalseType _IsPODType;

	};
template<>
struct TypeTraists<bool>
{
	typedef _FalseType _IsPODType;

	};
struct TypeTraists<char>
{
	typedef _FalseType _IsPODType;

	};
struct TypeTraists<unsigned char>
{
	typedef _FalseType _IsPODType;

	};
struct TypeTraists<short>
{
	typedef _FalseType _IsPODType;

	};
struct TypeTraists<unsigned short>
{
	typedef _FalseType _IsPODType;

	};
struct TypeTraists<int>
{
	typedef _FalseType _IsPODType;

	};
struct TypeTraists<unsigned int>
{
	typedef _FalseType _IsPODType;

	};
