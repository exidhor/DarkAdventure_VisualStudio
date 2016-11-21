#pragma once

#include "Config.hpp"
#include "Utils/Identifier/UintID.hpp"

namespace dae
{
	namespace animations
	{

		class ENGINE_API SequenceID : public utils::UintID
		{
		public:
			SequenceID()
				: UintID()
			{
				// nothing
			}

			explicit SequenceID(unsigned index)
				: UintID(index)
			{
				// nothing
			}
		};

	}
}