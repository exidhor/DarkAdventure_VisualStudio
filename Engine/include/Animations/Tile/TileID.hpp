#pragma once

#include "Config.hpp"
#include "Utils/Identifier/UintID.hpp"

namespace dae
{
	namespace animations
	{

		class ENGINE_API TileID : public utils::UintID
		{
		public:
			TileID()
				: UintID()
			{
				// nothing
			}

			explicit TileID(unsigned index)
				: UintID(index)
			{
				// nothing
			}
		};

	}
}
