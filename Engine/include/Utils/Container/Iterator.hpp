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
			
			Iterator<Object> & operator=(Iterator const& other);

			void reset();
			void setToTheEnd();

			Object const& next();
			Object const& previous();
			Object const& first() const;
			Object const& current() const;
			Object const& last() const;

			bool isLast() const;
			bool isFirst() const;
			bool isStuck() const;

		protected:
			int getLastIndex() const; // the return type is int in case of the array size is 0

			bool m_isStuck;
			std::vector<Object> const* m_array;
			unsigned m_currentIndex;
		};

	#include "Utils/Container/Iterator.inl"
	}
}