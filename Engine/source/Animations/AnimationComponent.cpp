#include "Animations/AnimationComponent.hpp"

using namespace dae::animations;
using namespace dae;

const AnimationManager* AnimationComponent::s_animationManager = nullptr;
const TileManager*      AnimationComponent::s_tileManager      = nullptr;

void AnimationComponent::setManagersPtr(AnimationManager* animationManager,
										TileManager* tileManager)
{
	s_animationManager = animationManager;
	s_tileManager = tileManager;
}

AnimationComponent::AnimationComponent()
{
	// nothing
}

void AnimationComponent::reset()
{
	m_player.reset();
	m_machine.reset();
}

void AnimationComponent::setAnimationMachine(AnimationMachine const& animationMachine)
{
	m_machine = animationMachine;

	ActualizePlayerWithState();
}

void AnimationComponent::update(graphics::RenderComponent & renderComponent, 
								unsigned time)
{
	bool needToUpdate = true;

	while(needToUpdate)
	{
		needToUpdate = m_player.update(time);

		if (needToUpdate)
		{
			m_machine.next();
			ActualizePlayerWithState();
		}
	}

	renderComponent.setTile(s_tileManager->getTile(m_player.getCurrentTile()));
}

AnimationID AnimationComponent::getCurrentAnimationID() const
{
	return m_player.getCurrentAnimation();
}

void AnimationComponent::ActualizePlayerWithState()
{
	AnimationState const& state = m_machine.getCurrentState();

	m_player.setAnimation(state.getAnimationID(), *s_animationManager);
	m_player.setRepeat(state.isRepeating());
	m_player.setReverseOrder(state.isInReverseOrder());
}