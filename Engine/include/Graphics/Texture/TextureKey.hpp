#pragma once

#include "Config.hpp"
#include <string>
#include "Utils/Identifier/KeyString.hpp"

namespace dae
{
	namespace graphics
	{

		class ENGINE_API TextureKey : public utils::KeyString
		{
		public:
			explicit TextureKey(std::string const& key)
				: KeyString(key)
			{
				// nothing
			}

		};

	}
}
