#pragma once

#include "Config.hpp"
#include "Utils/Identifier/UintID.hpp"

namespace dae
{
	namespace animations
	{
		
		class ENGINE_API TileGroupID : public utils::UintID
		{
		public :
			TileGroupID()
				: UintID()
			{
				// nothing
			}

			explicit TileGroupID(unsigned index)
				: UintID(index)
			{
				// nothing
			}
		};

	}
}