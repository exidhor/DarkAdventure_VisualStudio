#pragma once

#include "Config.hpp"
#include <vector>
#include "Animations/Animation/AnimationID.hpp"
#include "Animations/Machine/AnimationState.hpp"


namespace dae
{
	namespace animations
	{
		// todo : finish it, this code is temporary

		class ENGINE_API AnimationMachine
		{
		public :
			AnimationMachine();

			void reset();

			void add(AnimationID animationID,
					 bool isRepeating = false,
					 bool isInReverseOrder = false);
			
			void next();

			AnimationState const& getCurrentState() const;

		private :
			std::vector<AnimationState> m_states;
			unsigned m_currentIndex;
		};

	}
}
