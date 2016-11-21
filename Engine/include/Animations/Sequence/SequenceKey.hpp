#pragma once

#include "Config.hpp"
#include <string>
#include "Utils/Identifier/KeyString.hpp"

namespace dae
{
	namespace animations
	{
		class ENGINE_API SequenceKey : public utils::KeyString
		{
		public:
			explicit SequenceKey(std::string const& key)
				: KeyString(key)
			{
				// nothing
			}
		};
	}
}