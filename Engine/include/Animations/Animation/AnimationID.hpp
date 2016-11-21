#pragma once

#include "Config.hpp"
#include "Utils/Identifier/UintID.hpp"

namespace dae
{
	namespace animations
	{

		class ENGINE_API AnimationID : public utils::UintID
		{
		public:
			AnimationID()
				: UintID()
			{
				// nothing
			}

			explicit AnimationID(unsigned index)
				: UintID(index)
			{
				// nothing
			}
		};

	}
}
