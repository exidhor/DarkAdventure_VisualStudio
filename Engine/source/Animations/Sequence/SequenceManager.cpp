#include "Animations/Sequence/SequenceManager.hpp"

using namespace dae::animations;

SequenceManager::SequenceManager()
{
	// nothing
}

SequenceID SequenceManager::createSequence(std::vector<AnimationID> animationIDs,
										   std::string const& key)
{
	m_idContainer.push_back(Sequence(animationIDs), SequenceKey(key));

	return SequenceID(m_idContainer.size() - 1);
}

Sequence const& SequenceManager::getSequence(SequenceID const& sequenceID) const
{
	return m_idContainer[sequenceID.getValue()];
}

SequenceID SequenceManager::getSequenceID(SequenceKey const& sequenceKey) const
{
	return SequenceID(m_idContainer.getIndex(sequenceKey));
}