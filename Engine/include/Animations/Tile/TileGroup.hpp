#pragma once

#include "Config.hpp"
#include <string>
#include <vector>
#include "Animations/Tile/Tile.hpp"
#include "Animations/Tile/TileGroupID.hpp"
#include "Utils/Container/Iterator.hpp"

namespace dae
{
	namespace animations
	{
		class ENGINE_API TileGroup
		{
		public :

			explicit TileGroup(std::string const& key);

			void push_back(Tile const& tile);

			Tile & operator[](unsigned index);

			Tile const& operator[](unsigned index) const;

			void clear();

			unsigned size() const;

			std::string const& getKey() const;

			utils::Iterator<Tile> getIterator() const;

		private :

			std::string m_key;
			std::vector <Tile> m_tiles;
		};
	}
}
