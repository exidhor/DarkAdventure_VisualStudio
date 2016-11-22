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

			Time(float firstTime);

			Time(float time, unsigned size);

			void reserve(unsigned size);

			void clear();

			void setAllValues(float value);

			unsigned & operator[](unsigned index);

			unsigned operator[](unsigned index) const;

			utils::Iterator<unsigned> getIterator() const;

		private:
			std::vector<unsigned> m_timePerTile;
		};

	}
}
