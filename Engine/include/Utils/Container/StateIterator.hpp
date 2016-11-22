#pragma once

#include "Utils/Container/Iterator.hpp"

namespace dae
{
	namespace utils
	{
		template <typename Object>
		class StateIterator : protected Iterator<Object>
		{
		public:
			StateIterator();
			StateIterator(std::vector<Object> const& dataArray);
			StateIterator(Iterator<Object> const& other);

			StateIterator<Object> & operator=(const StateIterator<Object>& other);

			void setToStart();

			void setToEnd();

			void setRepeat(bool isRepeated);
			void setReverseOrder(bool isInReverseOrder);

			Object const& next();
			Object const& previous();
			Object const& first() const;
			Object const& current() const;
			Object const& last() const;

			bool isAtEnd() const;
			bool isAtStart() const;
			bool isStuck() const;

			bool isRepeating() const;
			bool isInReverseOrder() const;

			unsigned getNumberOfIterations() const;

		private:
			unsigned m_numberOfIterations;
			bool m_repeat;
			bool m_reverseOrder;
		};

	#include "Utils/Container/StateIterator.inl"
	}
}
