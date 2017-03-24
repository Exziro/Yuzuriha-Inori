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
template<>
struct TypeTraists<char>
{
	typedef _FalseType _IsPODType;

	};
template<>
struct TypeTraists<unsigned char>
{
	typedef _FalseType _IsPODType;

	};
template<>
struct TypeTraists<short>
{
	typedef _FalseType _IsPODType;

	};
template<>
struct TypeTraists<unsigned short>
{
	typedef _FalseType _IsPODType;

	};
template<>
struct TypeTraists<int>
{
	typedef _FalseType _IsPODType;

	};
template<>
struct TypeTraists<unsigned int>
{
	typedef _FalseType _IsPODType;

	};
template<>
struct TypeTraists<double>
{
	typedef _FalseType _IsPODType;

};
template<>
struct TypeTraists<long>
{
	typedef _FalseType _IsPODType;

};
template<>
struct TypeTraists<long long>
{
	typedef _FalseType _IsPODType;

};
template<class T>
void Copy(const T* src,T* dst,size_t size _FALSE Type)
{
	cout<<"_FalseType:"<<typeid(T).name()<<endl;
	for(size_t i=0;i<size;++i)
	{
		dst[i]=src[i];
	}
}
template<class T>
void Copy(const T* src,T* dst,size_t size _FALSE Type)
{
	cout<<"_FalseType:"<<typeid(T).name()<<endl;
	memccpy(dst,src,size*sizeof(T));

}
