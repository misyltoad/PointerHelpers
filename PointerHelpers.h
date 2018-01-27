#ifndef POINTERHELPERS_H
#define POINTERHELPERS_H

#include <cstddef>

#define SET_BASE(x) using BaseClass = x;

template <typename T>
class PointerWrapper
{
public:
	PointerWrapper(T* value = nullptr)
		: m_Value(value)
	{}

	template <typename J>
	PointerWrapper& operator=(const J rhs)
	{
		m_Value = rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator=(const J& rhs)
	{
		m_Value = rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator=(const J&& rhs)
	{
		m_Value = rhs;
		return *this;
	}

	template <typename J>
	const T* operator+(const J& rhs) const
	{
		return m_Value + rhs;
	}

	template <typename J>
	const T* operator-(const J& rhs) const
	{
		return m_Value - rhs;
	}

	template <typename J>
	const T* operator*(const J& rhs) const
	{
		return m_Value * rhs;
	}

	template <typename J>
	const T* operator/(const J& rhs) const
	{
		return m_Value / rhs;
	}

	template <typename J>
	const T* operator%(const J& rhs) const
	{
		return m_Value % rhs;
	}

	template <typename J>
	const T* operator^(const J& rhs) const
	{
		return m_Value ^ rhs;
	}

	template <typename J>
	const T* operator&(const J& rhs) const
	{
		return m_Value & rhs;
	}

	template <typename J>
	const T* operator|(const J& rhs) const
	{
		return m_Value | rhs;
	}

	template <typename J>
	const T* operator<<(const J& rhs) const
	{
		return m_Value << rhs;
	}

	template <typename J>
	const T* operator>>(const J& rhs) const
	{
		return m_Value >> rhs;
	}

	template <typename J>
	PointerWrapper& operator+=(const J& rhs)
	{
		m_Value += rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator-=(const J& rhs)
	{
		m_Value -= rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator*=(const J& rhs)
	{
		m_Value *= rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator/=(const J& rhs)
	{
		m_Value /= rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator%=(const J& rhs)
	{
		m_Value %= rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator^=(const J& rhs)
	{
		m_Value ^= rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator&=(const J& rhs)
	{
		m_Value &= rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator|=(const J& rhs)
	{
		m_Value |= rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator<<=(const J& rhs)
	{
		m_Value <<= rhs;
		return *this;
	}

	template <typename J>
	PointerWrapper& operator>>=(const J& rhs)
	{
		m_Value >>= rhs;
		return *this;
	}

	const T* operator~() const
	{
		return ~m_Value;
	}

	PointerWrapper& operator++()
	{
		m_Value++;
	}

	PointerWrapper& operator++(int unused)
	{
		m_Value++;
	}

	T* operator->() 
	{
		return m_Value;
	}

	const T* operator->() const
	{
		return m_Value;
	}

	T& operator*()
	{
		return *m_Value;
	}

	const T& operator*() const
	{
		return *m_Value;
	}

	T** operator&()
	{
		return &m_Value;
	}

	const T** operator&() const
	{
		return &m_Value;
	}

	template <typename J>
	const T& operator[](std::size_t id) const
	{
		return m_Value[id];
	}

	template <typename J>
	T& operator[](std::size_t id)
	{
		return m_Value[id];
	}

	template <typename J>
	bool operator==(const J& rhs) const
	{
		return m_Value == rhs;
	}

	template <typename J>
	bool operator!=(const J& rhs) const
	{
		return m_Value != rhs;
	}

	template <typename J>
	bool operator<(const J& rhs) const
	{
		return m_Value < rhs;
	}

	template <typename J>
	bool operator>(const J& rhs) const
	{
		return m_Value > rhs;
	}

	template <typename J>
	bool operator<=(const J& rhs) const
	{
		return m_Value <= rhs;
	}

	template <typename J>
	bool operator>=(const J& rhs) const
	{
		return m_Value >= rhs;
	}

	template <typename J>
	bool operator&&(const J& rhs) const
	{
		return m_Value && rhs;
	}

	template <typename J>
	bool operator||(const J& rhs) const
	{
		return m_Value || rhs;
	}

	bool operator!() const
	{
		return !m_Value;
	}
	
	T* GetPtr()
	{
		return m_Value;
	}
	
	const T* GetPtr() const
	{
		return m_Value;
	}
	
	T GetValue()
	{
		return *m_Value;
	}
	
	const T GetValue() const
	{
		return *m_Value;
	}
	
	void SetPtr(T* value)
	{
		m_Value = value;
	}
	
	void MakeNew()
	{
		if (m_Value)
			delete m_Value;
		
		m_Value = new T;
	}
	
	void MakeNewNoDelete()
	{
		m_Value = new T;
	}
	
	void Delete()
	{
		delete m_Value;
	}
	
	template<class ... Args>
	void MakeNew(Args... args)
	{
		if (m_Value)
			delete m_Value;
		
		m_Value = new T(&args...);
	}
	
	template<class ... Args>
	void MakeNewNoDelete(Args... args)
	{
		m_Value = new T(&args...);
	}
	
	bool IsValid()
	{
		return m_Value != nullptr;
	}

protected:
	T* m_Value;
};

template <typename T>
class AutoNewPtr : public PointerWrapper<T>
{
	SET_BASE(PointerWrapper<T>);
	
public:
	AutoNewPtr()
	{
		BaseClass::m_Value = new T;
	}
	
	void Delete()
	{
		delete BaseClass::m_Value;
		BaseClass::m_Value = new T;
	}
	
	template<class ... Args>
	AutoNewPtr(Args... args)
	{
		BaseClass::m_Value = new T(&args...);
	}
};

template <typename T>
class SelfDestructPtr : public PointerWrapper<T>
{
	SET_BASE(PointerWrapper<T>);
	
public:
	~SelfDestructPtr()
	{
		delete BaseClass::m_Value;
		BaseClass::m_Value = nullptr;
	}
};

#endif