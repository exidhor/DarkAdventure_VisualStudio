#pragma once

#include "Config.hpp"
#include "Utils/Math/AlignedRect.hpp"
#include "Utils/Container/IDContainer.hpp"
#include "Animations/Tile/TileKey.hpp"
#include "Animations/Tile/Tile.hpp"
#include "Animations/Tile/TileGroup.hpp"
#include "Animations/Tile/TileGroupID.hpp"
#include "Animations/Tile/TileID.hpp"
#include "Graphics/Texture/TextureID.hpp"

namespace dae
{
	namespace animations
	{
		class ENGINE_API TileManager
		{
		public :
			TileManager();

			virtual ~TileManager();

			TileID loadTile(graphics::TextureID const& textureID,
							utils::AlignedRect const& rect,
							std::string const& key);

			Tile const& getTile(TileID const& tileID) const;

			TileID getTileID(TileGroupID const& tileGroupID, unsigned tileIndex) const;

			TileGroupID getTileGroupID(TileKey const& tileKey) const;

			unsigned getGroupSize(TileGroupID const& tileGroupID) const;

			utils::Iterator<Tile> getIterator(TileGroupID const& tileGroupID) const;

		private :
			utils::IDContainer<TileGroup, TileKey, utils::Hash_string_key> m_idContainer;
		};
	}
}
