#include "vector.h"

template<class T>
vector<T>::vector(size_t size) 
	: _size(size), _capacity(size), _buffer(new T[size]) {}

template<class T>
vector<T>::vector(size_t size, T filler) 
	: _size(size), _capacity(size), _buffer(new T[size])
{
	std::fill(_buffer, _buffer + _size, filler);
}

template<class T>
vector<T>::vector(std::initializer_list<T> initList) 
	: _size(initList.size()), _capacity(initList.size())
{
	_buffer = new T[_size];
	std::copy(initList.begin(), initList.end(), _buffer);
}

template<class T>
vector<T>::~vector()
{
	delete[] _buffer;
}
template<class T>
vector<T>::vector(const vector& vec) 
	: _size(vec._size), _capacity(_size), _buffer(new T[_size])
{
	std::copy(vec._buffer, vec._buffer + _size, _buffer);
}

template<class T>
vector<T>::vector(vector&& vec) noexcept
	: _size(vec._size), _capacity(_size), _buffer(vec._buffer)
{
	vec._buffer = nullptr;
	vec._size = 0;
	vec._capacity = 0;
}

template<class T>
vector<T>& vector<T>::operator=(const vector& vec)
{
	if (this != &vec)
	{
		delete[] _buffer;
		_size = vec._size;
		_capacity = _size;
		_buffer = new T[_size];
		std::copy(vec._buffer, vec._buffer + vec._size, _buffer);
	}
	return *this;
}

template<class T>
vector<T>& vector<T>::operator=(vector&& vec) noexcept
{
	if (this != &vec)
	{
		delete[] _buffer;
		_buffer = vec._buffer;
		_size = vec._size;
		_capacity = _size;
		vec._size = 0;
		vec._capacity = 0;
		vec._buffer = nullptr;
	}
	return *this;
}

template<class T>
void vector<T>::reserve(size_t newCapacity)
{
	if (_capacity < newCapacity)
	{
		T* temp = new T[newCapacity];
		std::copy(_buffer, _buffer + _size, temp);
		delete[] _buffer;
		_buffer = temp;
		_capacity = newCapacity;
	}
}

template<class T>
void vector<T>::resize(size_t newSize)
{
	reserve(newSize);
	_size = newSize;
}

template<class T>
void vector<T>::push_back(T newItem)
{
	if (_capacity - _size < 5)
		reserve(_size + 5);
	*(_buffer + _size) = newItem;
	++_size;
}

template<class T>
void vector<T>::pop_back()
{
	if(_size > 0)
		--(_size);
}

template<class T>
void vector<T>::clear()
{
	_size = 0;
}

template<class T>
void vector<T>::shrink_to_fit()
{
	delete[] _buffer;
	_buffer = nullptr;
	_size = 0;
	_capacity = 0;
}

template<class T>
size_t vector<T>::size()
{
	return _size;
}

template<class T>
size_t vector<T>::capacity()
{
	return _capacity;
}

template<class T>
T& vector<T>::operator[](unsigned index) const
{
	return *(_buffer + index);
}

template<class T>
T* vector<T>::operator&(unsigned index) const
{
	return _buffer + index;
}