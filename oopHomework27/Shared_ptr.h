#pragma once
template<class T>
class Shared_Ptr
{
	T* ptr = nullptr;
	size_t* count = new size_t(0);

public:
	Shared_Ptr() = default;
	Shared_Ptr(T* ptr);
	Shared_Ptr(const Shared_Ptr& other);

	Shared_Ptr<T>& operator=(const Shared_Ptr& other);
	T& operator*() const;
	T* operator->() const;
	T& operator[](size_t& index);
	T& operator[](size_t& index) const;

	T* get() const;
	bool unique() const;
	size_t use_count() const;
	void swap(Shared_Ptr& other);
	bool owner_before(const Shared_Ptr& other);
	void reset();


	~Shared_Ptr();
};



template<class T>
Shared_Ptr<T>::Shared_Ptr(T* ptr)
{
	this->ptr = ptr;
	++(*count);
}

template<class T>
Shared_Ptr<T>::Shared_Ptr(const Shared_Ptr& other)
{
	this->ptr = other.ptr;
	this->count = other.count;
	++(*count);
}


template<class T>
Shared_Ptr<T>& Shared_Ptr<T>::operator=(const Shared_Ptr& other)
{
	this->ptr = other.ptr;
	this->count = other.count;
	++(*count);

	return *this;
}

template<class T>
T& Shared_Ptr<T>::operator*() const
{
	return *ptr;
}

template<class T>
T* Shared_Ptr<T>::operator->() const
{
	return ptr;
}

template<class T>
T& Shared_Ptr<T>::operator[](size_t& index) const
{
	return ptr[index];
}



template<class T>
T* Shared_Ptr<T>::get() const
{
	return ptr;
}

template<class T>
bool Shared_Ptr<T>::unique() const
{
	return *count == 1;
}

template<class T>
size_t Shared_Ptr<T>::use_count() const
{
	return *count;
}

template<class T>
void Shared_Ptr<T>::swap(Shared_Ptr& other)
{
	T* temp = ptr;
	size_t* tempCount = count;

	this->ptr = other.ptr;
	this->count = other.count;

	other.ptr = temp;
	other.count = tempCount;
}


template<class T>
bool Shared_Ptr<T>::owner_before(const Shared_Ptr& other)
{
	return count < other.count&& ptr == other.ptr;
}

template<class T>
void Shared_Ptr<T>::reset()
{
	ptr = nullptr;
	--(*count);
}

template<class T>
Shared_Ptr<T>::~Shared_Ptr()
{
	if (--(*count) == 0)
		delete ptr;
}