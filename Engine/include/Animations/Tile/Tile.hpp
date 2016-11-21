#pragma once

#include "Config.hpp"
#include "Utils/Math/AlignedRect.hpp"
#include "Graphics/Texture/TextureID.hpp"
#include "Animations/Tile/TileID.hpp"

namespace dae
{
	namespace animations
	{
		class ENGINE_API Tile
		{
		public :
			Tile();

			Tile(graphics::TextureID const& textureID, utils::AlignedRect const& rect);

			graphics::TextureID  const& getTextureID() const;
			utils::AlignedRect const& getRect() const;

		private :
			graphics::TextureID m_textureID;
			utils::AlignedRect m_rect;
		};
	}
}