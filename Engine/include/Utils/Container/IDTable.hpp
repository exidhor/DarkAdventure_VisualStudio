#pragma once

#include <vector>
#include "Utils/Container/Iterator.hpp"

namespace dae
{
	namespace utils
	{

		template <typename Object>
		class IDTable
		{
		public:
			IDTable();

			void clear();

			void reserve(unsigned size);

			void push_back(Object const& newElement);

			template <class ... Args>
			void emplace_back(Args&& ... args);

			Object & operator[](unsigned index);

			Object const& operator[](unsigned index) const;

			unsigned size() const;

			unsigned capacity() const;

			Iterator<Object> getIterator() const;

			std::vector<Object> const& getConstArray() const;

			Object const& last() const;
			Object & last();

		private:
			std::vector<Object> m_data; // contains the objet datas
		};

	#include "Utils/Container/IDTable.inl"
	}
}