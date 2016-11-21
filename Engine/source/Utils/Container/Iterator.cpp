#include "Utils/Container/Iterator.hpp"

using namespace dae::utils;

Iterator::Iterator(std::vector<unsigned> const& indexArray)
	: m_indexArray(indexArray),
	m_currentIndex(0)
{
	// nothing
}

void Iterator::reset()
{
	m_currentIndex = 0;
}

unsigned Iterator::nextIndex()
{
	if(isAtEnd())
	{
		m_currentIndex = 0;
	}
	else
	{
		m_currentIndex++;
	}

	return m_currentIndex;
}

unsigned Iterator::previousIndex()
{
	if(isAtStart())
	{
		m_currentIndex = m_indexArray.size()-1;
	}
	else
	{
		m_currentIndex--;
	}

	return m_currentIndex;
}

unsigned Iterator::currentIndex() const
{
	return m_currentIndex;
}

bool Iterator::isAtEnd() const
{
	return m_currentIndex >= m_indexArray.size()-1;
}

bool Iterator::isAtStart() const
{
	return m_currentIndex == 0;
}