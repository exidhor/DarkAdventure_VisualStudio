template <typename Object>
Iterator<Object>::Iterator()
	: Iterator(std::vector<Object> ())
{
	// nothing
}

template <typename Object>
Iterator<Object>::Iterator(std::vector<Object> const& dataArray)
	: m_array(&dataArray),
	m_currentIndex(0)
{
	// nothing
}

template <typename Object>
Iterator<Object>::Iterator(Iterator const& other)
	: m_array(other.m_array),
	m_currentIndex(other.m_currentIndex)
{
	// nothing
}

template <typename Object>
Iterator<Object> & Iterator<Object>::operator=(const Iterator<Object>& other)
{
	m_array = other.m_array;
	m_currentIndex = other.m_currentIndex;

	return *this;
}

template <typename Object>
void Iterator<Object>::reset()
{
	m_currentIndex = 0;
}

template <typename Object>
void Iterator<Object>::setToTheEnd()
{
	m_currentIndex = getLastIndex();
}

template <typename Object>
Object const& Iterator<Object>::next()
{
	if (!isAtEnd())
	{
		m_currentIndex++;
	}

	return (*m_array)[m_currentIndex];
}

template <typename Object>
Object const& Iterator<Object>::previous()
{
	if (!isAtStart())
	{
		m_currentIndex--;
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
bool Iterator<Object>::isAtEnd() const
{
	return m_currentIndex >= (unsigned)getLastIndex();
}

template <typename Object>
bool Iterator<Object>::isAtStart() const
{
	return m_currentIndex == 0;
}

template <typename Object>
int Iterator<Object>::getLastIndex() const
{
	return m_array->size() - 1;
}