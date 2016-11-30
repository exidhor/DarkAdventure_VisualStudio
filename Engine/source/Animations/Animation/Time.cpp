#include "Animations/Animation/Time.hpp"

using namespace dae::animations;
using namespace dae;

Time::Time(std::vector<unsigned> const& times)
{
	for (unsigned i = 0; i < times.size(); i++)
	{
		m_timePerTile.push_back(times[i]);
	}
}

Time::Time(unsigned firstTime)
	: Time(firstTime, 1)
{
	// nothing
}

Time::Time(unsigned time, unsigned size)
	: m_timePerTile(1, time)
{
	// nothing
}

void Time::reserve(unsigned size)
{
	m_timePerTile.reserve(size);
}

void Time::clear()
{
	m_timePerTile.clear();
}

void Time::setAllValues(unsigned value)
{
	for (unsigned i = 0; i < m_timePerTile.size(); i++)
	{
		m_timePerTile[i] = value;
	}
}

unsigned & Time::operator[](unsigned index)
{
	return m_timePerTile[index];
}

unsigned Time::operator[](unsigned index) const
{
	return m_timePerTile[index];
}

utils::Iterator<unsigned> Time::getIterator() const
{
	return utils::Iterator<unsigned>(m_timePerTile);
}