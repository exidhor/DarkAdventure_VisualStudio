#pragma once

#include "Config.hpp"
#include "Animations/Animation/Time.hpp"
#include "Animations/Tile/TileID.hpp"

namespace dae
{
	namespace animations
	{

		class ENGINE_API Animation
		{
		public:
			Animation();

			Animation(std::vector<TileID> const& tileID,
					  Time timeID);

			Time const& getTime() const;

			utils::Iterator<TileID> getTileIterator() const;
			utils::Iterator<unsigned> getTimeIterator() const;

		private:
			std::vector<TileID> m_tileID;
			Time m_time;
		};

	}
}
