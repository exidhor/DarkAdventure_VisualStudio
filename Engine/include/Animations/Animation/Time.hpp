#pragma once

#include "Config.hpp"
#include <vector>
#include "Utils/Container/Iterator.hpp"

namespace dae
{
	namespace animations
	{

		class ENGINE_API Time
		{
		public:
			Time(std::vector<unsigned> const& times);

			Time(unsigned firstTime);

			Time(unsigned time, unsigned size);

			void reserve(unsigned size);

			void clear();

			void setAllValues(unsigned value);

			unsigned & operator[](unsigned index);

			unsigned operator[](unsigned index) const;

			utils::Iterator<unsigned> getIterator() const;

		private:
			std::vector<unsigned> m_timePerTile;
		};

	}
}
