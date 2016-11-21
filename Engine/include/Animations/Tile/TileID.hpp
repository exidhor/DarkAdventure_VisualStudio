#pragma once

#include "Config.hpp"
#include "Animations/Tile/TileGroupID.hpp"

namespace dae
{
	namespace animations
	{
		class ENGINE_API TileID
		{
		
		public:
			TileID()
				: TileID(TileGroupID(0), 0)
			{
				// nothing
			}

			explicit TileID(TileGroupID groupID, unsigned tileIndex)
				: m_groupID(groupID),
				  m_tileIndex(tileIndex)
			{
				// nothing
			}

			friend bool operator==(TileID const& lhs, TileID const& rhs)
			{
				return lhs.m_groupID == rhs.m_groupID
					&& lhs.m_tileIndex == rhs.m_tileIndex;
			}

			TileGroupID getGroupID() const
			{
				return m_groupID;
			}

			unsigned getTileIndex() const
			{
				return m_tileIndex;
			}

		private:
			TileGroupID m_groupID;
			unsigned m_tileIndex;
		};
	}
}
