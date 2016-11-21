#pragma once

#include "Config.hpp"
#include <vector>
#include "Animations/Animation/AnimationID.hpp"
#include "Utils/Container/Iterator.hpp"


namespace dae
{
	namespace animations
	{

		class ENGINE_API Sequence
		{
		public:
			Sequence();

			Sequence(std::vector <AnimationID> animationIDs);

			utils::Iterator<AnimationID> getIterator() const;

		private:
			std::vector<AnimationID> m_animationIDs;
		};

	}
}
