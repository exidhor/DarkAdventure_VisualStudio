#pragma once

#include "Config.hpp"
#include "Graphics/Render/RenderComponent.hpp"
#include "Utils/Container/Iterator.hpp"
#include "Animations/Sequence/SequenceID.hpp"
#include "Animations/Sequence/SequenceManager.hpp"
#include "Animations/Animation/AnimationID.hpp"
#include "Animations/Animation/AnimationManager.hpp"
#include "Animations/Tile/TileID.hpp"
#include "Animations/Tile/TileManager.hpp"
#include "Animations/Time/TimeID.hpp"
#include "Animations/Time/TimeManager.hpp"

namespace dae
{
	namespace animations
	{
		class ENGINE_API AnimationComponent
		{
		public :
			AnimationComponent();

			void reset();

			void setSequence(SequenceID const& sequenceID);

			void update(graphics::RenderComponent & renderComponent, unsigned time);

			void setLoop(bool isLooping);
			void setReverseOrder(bool readInReverseOrder);
			void setFinishWithTheStart(bool theLastTileIsTheFirst);

			SequenceID getCurrentSequenceID() const;
			AnimationID getCurrentAnimationID() const;

			bool isLooping() const;
			bool isReadingInReverseOrder() const;
			bool isTheLastTileIsTheFirst() const;

			static void setManagersPtr(SequenceManager* sequenceManager,
									   AnimationManager* animationManager,
									   TimeManager* timeManager,
									   TileManager* tileManager);

		private :
			void updateTime(graphics::RenderComponent & renderComponent, unsigned time);
			void updateTile(graphics::RenderComponent & renderComponent, unsigned indexToProgress);
			
			void setAnimationIterator(SequenceID sequenceID);
			void setTileIterator(TileGroupID tileGroupID);
			void setTimeIterator(TimeID timeID);

			bool m_isLooping;
			bool m_readInReverseOrder;
			bool m_theLastTileIsTheFirst;

			bool m_noSequenceIsSet;

			SequenceID m_currentSequenceID;
			unsigned m_currentTime;

			utils::Iterator<AnimationID> m_currentAnimationIterated;
			utils::Iterator<Tile> m_currentTileIterated;
			utils::Iterator<unsigned> m_currentTimeIterated;

			static const SequenceManager * s_sequenceManager;
			static const AnimationManager * s_animationManager;
			static const TimeManager * s_timeManager;
			static const TileManager * s_tileManager;
		};
		
	}
}
