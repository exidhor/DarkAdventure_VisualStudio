#include "Animations/Tile/TileGroup.hpp"

using namespace dae::animations;
using namespace dae;


TileGroup::TileGroup(std::string const& key)
	: m_key(key)
{
	// nothing
}

void TileGroup::push_back(Tile const& tile)
{
	m_tiles.push_back(tile);
}

Tile & TileGroup::operator[](unsigned index)
{
	return m_tiles[index];
}

Tile const& TileGroup::operator[](unsigned index) const
{
	return m_tiles[index];
}

void TileGroup::clear()
{
	m_tiles.clear();
}

unsigned TileGroup::size() const
{
	return m_tiles.size();
}

std::string const& TileGroup::getKey() const
{
	return m_key;
}

utils::Iterator<Tile> TileGroup::getIterator() const
{
	return utils::Iterator<Tile>(m_tiles);
}