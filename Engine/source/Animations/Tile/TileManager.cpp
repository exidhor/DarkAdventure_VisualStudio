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
	TileKey tileKey(key);

	unsigned groupIndex = 0;
	unsigned tileIndex = 0;

	if(m_idContainer.exists(tileKey))
	{
		groupIndex = m_idContainer.getIndex(tileKey);
	}
	else
	{
		m_idContainer.push_back(TileGroup(key), tileKey);
		groupIndex = m_idContainer.size()-1;
	}

	m_idContainer[groupIndex].push_back(Tile(textureID, rect));
	tileIndex = m_idContainer[groupIndex].size()-1;

	return TileID(TileGroupID(groupIndex), tileIndex);
}

Tile const& TileManager::getTile(TileID const& tileID) const
{
	return m_idContainer[tileID.getGroupID().getValue()][tileID.getTileIndex()];
}

TileID TileManager::getTileID(TileGroupID const& tileGroupID, unsigned tileIndex) const
{
	return TileID(tileGroupID, tileIndex);
}

TileGroupID TileManager::getTileGroupID(TileKey const& tileKey) const
{
	return TileGroupID(m_idContainer.getIndex(tileKey));
}

unsigned TileManager::getGroupSize(TileGroupID const& tileGroupID) const
{
	return m_idContainer[tileGroupID.getValue()].size();
}

utils::Iterator<Tile> TileManager::getIterator(TileGroupID const& tileGroupID) const
{
	return m_idContainer[tileGroupID.getValue()].getIterator();
}