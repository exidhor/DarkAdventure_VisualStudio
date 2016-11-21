#include "Animations/Sequence/Sequence.hpp"

using namespace dae::animations;
using namespace dae;

Sequence::Sequence()
{
	// nothing
}

Sequence::Sequence(std::vector <AnimationID> animationIDs)
	: m_animationIDs(animationIDs)
{
	// nothing
}

utils::Iterator<AnimationID> Sequence::getIterator() const
{
	return utils::Iterator <AnimationID> (m_animationIDs);
}