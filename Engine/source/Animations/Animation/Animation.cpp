#include "Animations/Animation/Animation.hpp"

using namespace dae::animations;
using namespace dae;

Animation::Animation()
	: m_time(0)
{
	// nothing
}

Animation::Animation(std::vector<TileID> const& tileID,
					 Time timeID)
	: m_tileID(tileID), 
	m_time(timeID)
{
	// nothing
}

Time const& Animation::getTime() const
{
	return m_time;
}

utils::Iterator<TileID> Animation::getTileIterator() const
{
	return utils::Iterator<TileID>(m_tileID);
}

utils::Iterator<unsigned> Animation::getTimeIterator() const
{
	return m_time.getIterator();
}