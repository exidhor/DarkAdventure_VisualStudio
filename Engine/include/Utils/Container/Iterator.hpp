#pragma once 

#include <vector>

namespace dae
{
	namespace utils
	{
		template <typename Object>
		class Iterator
		{
		public:
			Iterator();
			Iterator(std::vector<Object> const& dataArray);
			Iterator(Iterator const& other);

			Iterator<Object> operator=(const Iterator<Object>& other) = default;

			void reset();
			void setToTheEnd();

			Object const& next();
			Object const& previous();
			Object const& first() const;
			Object const& current() const;
			Object const& last() const;

			bool isAtEnd() const;
			bool isAtStart() const;

		protected:
			int getLastIndex() const; // the return type is int in case of the array size is 0

			const std::vector<Object> & m_array;
			unsigned m_currentIndex;
		};

	#include "Utils/Container/Iterator.inl"
	}
}