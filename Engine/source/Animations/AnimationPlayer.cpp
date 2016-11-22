#include "Animations/AnimationPlayer.hpp"
#include "Animations/Animation/AnimationManager.hpp"
#include "Animations/Tile/TileManager.hpp"

using namespace dae::animations;
using namespace dae;

AnimationPlayer::AnimationPlayer()
	: m_speedCoefficient(1),
	m_currentTime(0)
{
	// nothing
}

void AnimationPlayer::reset()
{
	m_speedCoefficient = 1;
	m_currentTime = 0;
	
	m_animationID = AnimationID();

	m_tileIterator = utils::StateIterator<TileID>();
	m_timeIterator = utils::StateIterator<unsigned>();
}

bool AnimationPlayer::update(unsigned time)
{
	m_currentTime += time;

	while (m_currentTime >= m_timeIterator.current())
	{
		m_currentTime -= m_timeIterator.current();

		if(!m_tileIterator.isStuck())
		{
			m_tileIterator.next();
			m_timeIterator.next();
		}
		else
		{
			return true;
		}
	}

	return false;
}

void AnimationPlayer::setAnimation(AnimationID animationID, 
								   AnimationManager const& animationManager)
{
	m_animationID = animationID;

	setIterators(m_animationID, animationManager);
}

void AnimationPlayer::setSpeedCoefficient(float speedCoefficient)
{
	m_speedCoefficient = speedCoefficient;
}

void AnimationPlayer::setRepeat(bool isRepeating)
{
	m_tileIterator.setRepeat(isRepeating);
	m_timeIterator.setRepeat(isRepeating);
}

void AnimationPlayer::setReverseOrder(bool isInReverseOrder)
{
	m_tileIterator.setReverseOrder(isInReverseOrder);
	m_timeIterator.setReverseOrder(isInReverseOrder);
}

float AnimationPlayer::getSpeedCoefficient() const
{
	return m_speedCoefficient;
}

AnimationID AnimationPlayer::getCurrentAnimation() const
{
	return m_animationID;
}

TileID AnimationPlayer::getCurrentTile() const
{
	return m_tileIterator.current();
}

bool AnimationPlayer::isRepeating() const
{
	return m_tileIterator.isRepeating();
}

bool AnimationPlayer::isInReverseOrder() const
{
	return m_tileIterator.isInReverseOrder();
}

void AnimationPlayer::setIterators(AnimationID animationID,
								   AnimationManager const& animationManager)
{
	Animation const& anim = animationManager.getAnimation(animationID);

	m_tileIterator = anim.getTileIterator();
	m_timeIterator = anim.getTimeIterator();
}