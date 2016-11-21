#pragma once

#include "Config.hpp"
#include "Utils/Identifier/UintID.hpp"

namespace dae
{
	namespace animations
	{

		class ENGINE_API TimeID : public utils::UintID
		{
		public:
			TimeID()
				: UintID()
			{
				// nothing
			}

			explicit TimeID(unsigned index)
				: UintID(index)
			{
				// nothing
			}
		};

	}
}
