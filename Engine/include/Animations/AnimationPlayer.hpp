#pragma once

#include "Config.hpp"
#include "Animations/Animation/AnimationID.hpp"
#include "Animations/Animation/AnimationManager.hpp"
#include "Tile/TileID.hpp"
#include "Utils/Container/StateIterator.hpp"


namespace dae
{
	namespace animations
	{
		class ENGINE_API AnimationPlayer
		{
		public :
			AnimationPlayer();

			void reset();

			/**
			 * \brief 
			 * \param time 
			 * \return True if the End is reach, False otherwise
			 */
			bool update(unsigned time);

			void setAnimation(AnimationID animationID,
							  AnimationManager const& animationManager);

			void setSpeedCoefficient(float speedCoefficient);

			void setRepeat(bool isRepeating);
			void setReverseOrder(bool isInReverseOrder);

			float getSpeedCoefficient() const;

			AnimationID getCurrentAnimation() const;
			TileID getCurrentTile() const;

			bool isRepeating() const;
			bool isInReverseOrder() const;

		private :
			void setIterators(AnimationID animationID,
							  AnimationManager const& animationManager);

			float m_speedCoefficient;

			unsigned m_currentTime;

			AnimationID m_animationID;

			utils::StateIterator<TileID> m_tileIterator;
			utils::StateIterator<unsigned> m_timeIterator;
		};
	}
}
