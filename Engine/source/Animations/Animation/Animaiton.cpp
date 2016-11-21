#include "Animations/Animation/Animation.hpp"

using namespace dae::animations;

Animation::Animation()
{
	// nothing
}

Animation::Animation(TileGroupID const tileGroupID, TimeID const& timeID)
	: m_tileGroupID(tileGroupID), 
	m_timeID(timeID)
{
	// nothing
}

TileGroupID const& Animation::getTileGroupID() const
{
	return m_tileGroupID;
}

TimeID const& Animation::getTimeID() const
{
	return m_timeID;
}