#pragma once

#include "Config.hpp"
#include "Animations/Animation/AnimationID.hpp"

namespace dae
{
	namespace animations
	{
		
		class ENGINE_API AnimationState
		{
		public :
			AnimationState();
			AnimationState(AnimationID animationID);
			AnimationState(AnimationID animationID, 
						   bool isRepeating,
						   bool isInReverseOrder);

			AnimationID getAnimationID() const;

			bool isRepeating() const;
			bool isInReverseOrder() const;

		private :
			AnimationID m_animationID;

			bool m_repeat;
			bool m_reverseOrder;
		};

	}
}
