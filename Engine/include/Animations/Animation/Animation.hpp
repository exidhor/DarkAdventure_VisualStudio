#pragma once

#include "Config.hpp"
#include "Animations/Tile/TileGroupID.hpp"
#include "Animations/Time/TimeID.hpp"

namespace dae
{
	namespace animations
	{

		class ENGINE_API Animation
		{
		public:
			Animation();

			Animation(TileGroupID const tileGroupID, TimeID const& timeID);

			TileGroupID const& getTileGroupID() const;

			TimeID const& getTimeID() const;

		private:
			TileGroupID m_tileGroupID;
			TimeID m_timeID;
		};

	}
}
