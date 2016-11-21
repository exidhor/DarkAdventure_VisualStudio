#include "Animations/Tile/Tile.hpp"

using namespace dae::animations;
using namespace dae;

Tile::Tile()
	: Tile(graphics::TextureID(0), utils::AlignedRect())
{
	// nothing
}

Tile::Tile(graphics::TextureID const& textureID, utils::AlignedRect const& rect)
	: m_textureID(textureID),
	  m_rect(rect)
{
	// nothing
}

graphics::TextureID  const& Tile::getTextureID() const
{
	return m_textureID;
}

utils::AlignedRect const& Tile::getRect() const
{
	return m_rect;
}