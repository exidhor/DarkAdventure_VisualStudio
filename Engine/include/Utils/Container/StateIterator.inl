template <typename Object>
StateIterator<Object>::StateIterator()
	: Iterator<Object>(),
	m_repeat(false),
	m_reverseOrder(false),
	m_numberOfIterations(0)
{
	// nothing
}

template <typename Object>
StateIterator<Object>::StateIterator(std::vector<Object> const& dataArray)
	: Iterator<Object>(dataArray),
	m_repeat(false),
	m_reverseOrder(false),
	m_numberOfIterations(0)
{
	// nothing
}

template <typename Object>
StateIterator<Object>::StateIterator(Iterator<Object> const& other)
	: Iterator<Object>(other),
	m_repeat(false),
	m_reverseOrder(false),
	m_numberOfIterations(0)
{
	// nothing
}

template <typename Object>
void StateIterator<Object>::setToStart()
{
	if (m_reverseOrder)
	{
		Iterator<Object>::m_currentIndex = Iterator<Object>::getLastIndex();
	}
	else
	{
		Iterator<Object>::reset();
	}
}

template <typename Object>
void StateIterator<Object>::setToEnd()
{
	if(m_reverseOrder)
	{
		Iterator<Object>::m_currentIndex = 0;
	}
	else
	{
		Iterator<Object>::setToTheEnd();
	}
}

template <typename Object>
void StateIterator<Object>::setRepeat(bool isRepeated)
{
	m_repeat = isRepeated;
}

template <typename Object>
void StateIterator<Object>::setReverseOrder(bool isInReverseOrder)
{
	m_reverseOrder = isInReverseOrder;
}

template <typename Object>
Object const& StateIterator<Object>::next()
{
	if(!isAtEnd())
	{
		if(m_reverseOrder)
		{
			Iterator<Object>::m_currentIndex -= 1;
		}
		else
		{
			Iterator<Object>::m_currentIndex += 1;
		}
	}
	else if(m_repeat)
	{
		setToStart();
		m_numberOfIterations++;
	}

	return Iterator<Object>::m_array[Iterator<Object>::m_currentIndex];
}

template <typename Object>
Object const& StateIterator<Object>::previous()
{
	if (!isAtStart())
	{
		if (m_reverseOrder)
		{
			Iterator<Object>::m_currentIndex += 1;
		}
		else
		{
			Iterator<Object>::m_currentIndex -= 1;
		}
	}
	else if (m_repeat)
	{
		setToEnd();
		m_numberOfIterations++;
	}

	return Iterator<Object>::m_array[Iterator<Object>::m_currentIndex];
}

template <typename Object>
Object const& StateIterator<Object>::first() const
{
	if (m_reverseOrder)
	{
		return Iterator<Object>::last();
	}
	
	return Iterator<Object>::first();
}

template <typename Object>
Object const& StateIterator<Object>::current() const
{
	return Iterator<Object>::current();
}

template <typename Object>
Object const& StateIterator<Object>::last() const
{
	if (m_reverseOrder)
	{
		return Iterator<Object>::first();
	}

	return Iterator<Object>::last();
}

template <typename Object>
bool StateIterator<Object>::isAtEnd() const
{
	if (m_reverseOrder)
	{
		return Iterator<Object>::isAtStart();
	}

	return Iterator<Object>::isAtEnd();
}

template <typename Object>
bool StateIterator<Object>::isStuck() const
{
	return !m_repeat && ((isAtEnd() && !m_reverseOrder)
						 || (isAtStart() && m_reverseOrder));
}

template <typename Object>
bool StateIterator<Object>::isAtStart() const
{
	if (m_reverseOrder)
	{
		return Iterator<Object>::isAtEnd();
	}

	return Iterator<Object>::isAtStart();
}

template <typename Object>
bool StateIterator<Object>::isRepeating() const
{
	return m_repeat;
}

template <typename Object>
bool StateIterator<Object>::isInReverseOrder() const
{
	return m_reverseOrder;
}

template <typename Object>
unsigned StateIterator<Object>::getNumberOfIterations() const
{
	return m_numberOfIterations;
}