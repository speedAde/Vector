#include <initializer_list>
#pragma once

template<class T>
class vector
{
private:
	size_t _capacity;
	size_t _size;
	T* _buffer;
public:
	explicit vector(size_t size = 0);
	vector(size_t, T);
	vector(std::initializer_list<T>);
	~vector();

	vector(const vector&);
	vector(vector&&) noexcept;
	vector& operator=(const vector&);
	vector& operator=(vector&&) noexcept;

	void reserve(size_t);
	void resize(size_t);
	void push_back(T);
	void pop_back();
	void clear();
	void shrink_to_fit();

	size_t size();
	size_t capacity();

	T& operator[](unsigned) const;
	T* operator&(unsigned) const;
};
