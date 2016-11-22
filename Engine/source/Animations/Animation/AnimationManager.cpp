#include "Animations/Animation/AnimationManager.hpp"

using namespace dae::animations;

AnimationManager::AnimationManager()
{
	// nothing
}

AnimationID AnimationManager::createAnimation(std::vector<TileID> const& tileID,
										 Time const& time,
										 std::string const& key)
{
	m_idContainer.push_back(Animation(tileID, time), AnimationKey(key));

	return AnimationID(m_idContainer.size() - 1);
}

Animation const& AnimationManager::getAnimation(AnimationID const& animationID) const
{
	return m_idContainer[animationID.getValue()];
}

AnimationID AnimationManager::getAnimationID(AnimationKey const& animationKey) const
{
	return AnimationID(m_idContainer.getIndex(animationKey));
}