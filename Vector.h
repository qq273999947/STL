#pragma once
#include <assert.h>

//template<class T>
//struct __VectorIterator
//{
//protected:
//	T* ptr;
//};

template<class T>
class Vector
{
	typedef T ValueType;
public:
	typedef ValueType* Iterator;
	typedef const ValueType* ConstIterator;

	Vector()
		:_start(NULL)
		,_finish(NULL)
		,_endOfStorage(NULL)
	{}

	void PushBack(const ValueType& x)
	{
		_CheckCapacity();

		*_finish = x;
		++_finish;
	}

	void PopBack();
	// 在前面插入一个数据x
	void Insert(Iterator pos, const ValueType& x);
	void Erase(Iterator pos);

	Iterator Begin()
	{
		return _start;
	}

	Iterator End()
	{
		return _finish;
	}

	size_t Size()
	{
		return _finish-_start;
	}

	ValueType& operator[](size_t index)
	{
		assert(_start+index < _finish);
		return _start[index];
	}

protected:
	void _CheckCapacity()
	{
		if (_finish == _endOfStorage)
		{
			size_t oldStorage = _finish - _start;
			size_t storage = oldStorage*2 + 3;

			ValueType* tmp = new ValueType[storage];
			for (size_t i = 0; i < oldStorage; ++i)
			{
				tmp[i] = _start[i];
			}

			delete[] _start;

			_start = tmp;
			_finish = _start+oldStorage;
			_endOfStorage = _start + storage;
		}
	}

protected:
	Iterator _start;
	Iterator _finish;
	Iterator _endOfStorage;
};

void TestVector()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);

	Vector<int>::Iterator it = v.Begin();
	while (it != v.End())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	v[0] = 10;

	for (size_t i = 0 ; i < v.Size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}