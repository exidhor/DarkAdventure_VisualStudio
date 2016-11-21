#pragma once

#include "Config.hpp"
#include <string>
#include "Utils/Identifier/KeyString.hpp"

namespace dae
{
	namespace animations
	{
		class ENGINE_API AnimationKey : public utils::KeyString
		{
		public:
			explicit AnimationKey(std::string const& key)
				: KeyString(key)
			{
				// nothing
			}
		};
	}
}
