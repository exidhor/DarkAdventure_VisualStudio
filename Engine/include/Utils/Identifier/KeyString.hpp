#pragma once

#include <string>
#include "Config.hpp"

namespace dae
{
	namespace utils
	{
		class ENGINE_API KeyString
		{
		public:
			KeyString(std::string const& key)
				: m_key(key)
			{
				// nothing
			}

			std::string const& getKeyValue() const
			{
				return m_key;
			}

			friend bool operator==(KeyString const& lhs, KeyString const& rhs)
			{
				return lhs.m_key == rhs.m_key;
			}

			explicit operator std::string const&() const
			{
				return m_key;
			}

		private:
			std::string m_key;
		};

		/*!
		* \brief   the struct used to hash the key information into the map
		* \source  http://marknelson.us/2011/09/03/hash-functions-for-c-unordered-containers/
		*/
		struct Hash_string_key
		{
			size_t operator()(KeyString const& key) const
			{
				return std::hash<std::string>()(key.getKeyValue());
			}
		};
	}
}