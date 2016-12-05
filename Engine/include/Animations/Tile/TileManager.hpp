#pragma once

#include "Config.hpp"
#include "Utils/Math/AlignedRect.hpp"
#include "Utils/Container/IDTable.hpp"
#include "Animations/Tile/TileKey.hpp"
#include "Animations/Tile/Tile.hpp"
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

			TileID getTileID(TileKey const& tileKey) const;

		private :
			utils::IDTable<Tile, TileKey, utils::Hash_string_key> m_idContainer;
		};
	}
}
