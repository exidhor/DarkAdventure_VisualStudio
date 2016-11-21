#pragma once

#include "Config.hpp"
#include <string>
#include "Utils/Identifier/KeyString.hpp"

namespace dae
{
	namespace animations
	{
		class ENGINE_API TimeKey : public utils::KeyString
		{
		public:
			explicit TimeKey(std::string const& key)
				: KeyString(key)
			{
				// nothing
			}
		};
	}
}
