template <typename Object>
Iterator<Object>::Iterator()
	: Iterator(std::vector<Object> ())
{
	// nothing
}

template <typename Object>
Iterator<Object>::Iterator(std::vector<Object> const& dataArray)
	: m_array(&dataArray),
	m_currentIndex(0),
	m_isStuck(false)
{
	if(m_array->size() == 0)
	{
		m_isStuck = true;
	}
}

template <typename Object>
Iterator<Object>::Iterator(Iterator const& other)
	: m_array(other.m_array),
	m_currentIndex(other.m_currentIndex),
	m_isStuck(other.m_isStuck)
{
	// nothing
}

template <typename Object>
Iterator<Object> & Iterator<Object>::operator=(Iterator const& other)
{
	m_array = other.m_array;
	m_currentIndex = other.m_currentIndex;
	m_isStuck = other.m_isStuck;

	return *this;
}

template <typename Object>
void Iterator<Object>::reset()
{
	m_currentIndex = 0;
	m_isStuck = false;
}

template <typename Object>
void Iterator<Object>::setToTheEnd()
{
	m_currentIndex = getLastIndex();
	m_isStuck = false;
}

template <typename Object>
Object const& Iterator<Object>::next()
{
	if (!isLast())
	{
		m_currentIndex++;
	}
	else
	{
		m_isStuck = true;
	}

	return (*m_array)[m_currentIndex];
}

template <typename Object>
Object const& Iterator<Object>::previous()
{
	if (!isFirst())
	{
		m_currentIndex--;
	}
	else
	{
		m_isStuck = true;
	}

	return (*m_array)[m_currentIndex];
}

template <typename Object>
Object const& Iterator<Object>::first() const
{
	return (*m_array)[0];
}

template <typename Object>
Object const& Iterator<Object>::current() const
{
	return (*m_array)[m_currentIndex];
}

template <typename Object>
Object const& Iterator<Object>::last() const
{
	return (*m_array)[getLastIndex()];
}

template <typename Object>
bool Iterator<Object>::isLast() const
{
	return m_currentIndex >= (unsigned)getLastIndex();
}

template <typename Object>
bool Iterator<Object>::isFirst() const
{
	return m_currentIndex == 0;
}

template <typename Object>
int Iterator<Object>::getLastIndex() const
{
	return m_array->size() - 1;
}

template <typename Object>
bool Iterator<Object>::isStuck() const
{
	return m_isStuck;
}