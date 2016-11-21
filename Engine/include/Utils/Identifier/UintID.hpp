#pragma once

#include "Config.hpp"

namespace dae
{
	namespace utils
	{

		class ENGINE_API UintID
		{
		public:
			UintID()
				: UintID(0)
			{
				// nothing
			}

			explicit UintID(unsigned id)
			{
				m_value = id;
			}

			friend bool operator==(UintID const& lhs, UintID const& rhs)
			{
				return lhs.m_value == rhs.m_value;
			}

			unsigned getValue() const
			{
				return m_value;
			}

		protected :
			unsigned m_value;
		};

	}
}
