#pragma once


#include "Config.hpp"
#include <string>
#include "Utils/Identifier/KeyString.hpp"

namespace dae
{
	namespace animations
	{
		class ENGINE_API TileKey : public utils::KeyString
		{
		public :
			explicit TileKey(std::string const& key)
				: KeyString(key)
			{
				// nothing
			}
		};
	}
}
