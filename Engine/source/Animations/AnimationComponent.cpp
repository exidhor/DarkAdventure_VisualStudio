#include "Animations/AnimationComponent.hpp"

using namespace dae::animations;

const SequenceManager*  AnimationComponent::s_sequenceManager  = nullptr;
const AnimationManager* AnimationComponent::s_animationManager = nullptr;
const TimeManager*      AnimationComponent::s_timeManager      = nullptr;
const TileManager*      AnimationComponent::s_tileManager      = nullptr;

AnimationComponent::AnimationComponent()
	: m_isLooping(false),
	m_readInReverseOrder(false),
	m_theLastTileIsTheFirst(false),
	m_noSequenceIsSet(true)
{
	// nothing
}

void AnimationComponent::reset()
{
	m_isLooping = false;
	m_readInReverseOrder = false;
	m_theLastTileIsTheFirst = false;

	m_noSequenceIsSet = true;
}

void AnimationComponent::setSequence(SequenceID const& sequenceID)
{
	m_noSequenceIsSet = false;

	m_currentSequenceID = sequenceID;

	// construction of the iterators
	setAnimationIterator(m_currentSequenceID);
	
	AnimationID animationID = m_currentAnimationIterated.current();
	TileGroupID tileGroupID = s_animationManager->getAnimation(animationID).getTileGroupID();
	TimeID timeID           = s_animationManager->getAnimation(animationID).getTimeID();

	setTileIterator(tileGroupID);
	setTimeIterator(timeID);
}

void AnimationComponent::update(graphics::RenderComponent & renderComponent, unsigned time)
{
	updateTime(time);
}

void AnimationComponent::setLoop(bool isLooping)
{
	
}

void AnimationComponent::setReverseOrder(bool readInReverseOrder)
{
	
}

void AnimationComponent::setFinishWithTheStart(bool theLastTileIsTheFirst)
{
	
}

SequenceID AnimationComponent::getCurrentSequenceID() const
{
	
}

AnimationID AnimationComponent::getCurrentAnimationID() const
{
	
}

bool AnimationComponent::isLooping() const
{
	
}

bool AnimationComponent::isReadingInReverseOrder() const
{
	
}

bool AnimationComponent::isTheLastTileIsTheFirst() const
{
	
}

void AnimationComponent::setManagersPtr(SequenceManager* sequenceManager,
										AnimationManager* animationManager,
										TimeManager* timeManager,
										TileManager* tileManager)
{
	s_sequenceManager = sequenceManager;
	s_animationManager = animationManager;
	s_timeManager = timeManager;
	s_tileManager = tileManager;
}

void AnimationComponent::updateTime(graphics::RenderComponent & renderComponent, 
									unsigned time)
{
	m_currentTime += time;

	unsigned indexToProgress = 0;

	while (m_currentTime >= m_currentTimeIterated.current())
	{
		m_currentTime -= m_currentTimeIterated.current();
		indexToProgress++;

		if(m_currentTimeIterated.isAtEnd())
		{
			if(m_isLooping)
		}
		else
		{
			m_currentTimeIterated.next();
		}
	}

	if (indexToProgress > 0)
	{
		updateTile(renderComponent, indexToProgress);
	}
}

void AnimationComponent::updateTile(graphics::RenderComponent & renderComponent, 
									unsigned indexToProgress)
{
	
}

void AnimationComponent::setAnimationIterator(SequenceID sequenceID)
{
	m_currentAnimationIterated = s_sequenceManager->getSequence(sequenceID).getIterator();
}

void AnimationComponent::setTileIterator(TileGroupID tileGroupID)
{
	m_currentTileIterated = s_tileManager->getIterator(tileGroupID);
}

void AnimationComponent::setTimeIterator(TimeID timeID)
{
	m_currentTimeIterated = s_timeManager->getTime(timeID).getIterator();
}