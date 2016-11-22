#include "Animations/Tile/TileManager.hpp"

using namespace dae::animations;
using namespace dae;

TileManager::TileManager()
{
	// nothing
}

TileManager::~TileManager()
{
	// nothing
}

TileID TileManager::loadTile(graphics::TextureID const& textureID,
									utils::AlignedRect const& rect,
									std::string const& key)
{
	m_idContainer.push_back(Tile(textureID, rect), TileKey(key));

	return TileID(m_idContainer.size() - 1);
}

Tile const& TileManager::getTile(TileID const& tileID) const
{
	return m_idContainer[tileID.getValue()];
}

TileID TileManager::getTileID(TileKey const& tileKey) const
{
	return TileID(m_idContainer.getIndex(tileKey));
}