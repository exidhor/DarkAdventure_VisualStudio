#include "Animations/Machine/AnimationMachine.hpp"

using namespace dae::animations;

AnimationMachine::AnimationMachine()
{
	// nothing (yet ? ...)
}

void AnimationMachine::reset()
{
	m_states.clear();

	m_currentIndex = 0;
}

void AnimationMachine::add(AnimationID animationID,
						   bool isRepeating,
						   bool isInReverseOrder)
{
	m_states.push_back(AnimationState(animationID, 
					                  isRepeating,
			                          isInReverseOrder));
}

void AnimationMachine::next()
{
	m_currentIndex++;

	if(m_currentIndex >= m_states.size())
	{
		m_currentIndex = 0;
	}
}

AnimationState const& AnimationMachine::getCurrentState() const
{
	return m_states[m_currentIndex];
}