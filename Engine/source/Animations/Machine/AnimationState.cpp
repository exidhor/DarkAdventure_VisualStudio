#include "Animations/Machine/AnimationState.hpp"

using namespace dae::animations;

AnimationState::AnimationState()
	: AnimationState(AnimationID())
{
	// nothing
}

AnimationState::AnimationState(AnimationID animationID)
	: AnimationState(animationID, false, false)
{
	// nothing
}

AnimationState::AnimationState(AnimationID animationID,
							   bool isRepeating,
							   bool isInReverseOrder)
	: m_animationID(animationID),
	m_repeat(isRepeating),
	m_reverseOrder(isInReverseOrder)
{
	// nothing
}

AnimationID AnimationState::getAnimationID() const
{
	return m_animationID;
}

bool AnimationState::isRepeating() const
{
	return m_repeat;
}

bool AnimationState::isInReverseOrder() const
{
	return m_reverseOrder;
}