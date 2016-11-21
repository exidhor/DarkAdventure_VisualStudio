#pragma once

#include <functional>
#include <vector>
#include <unordered_map>
#include "Utils/Container/Iterator.hpp"
#include <algorithm>

namespace dae
{
	namespace utils
	{

		template <typename Object,
			typename Key,
			typename Hash = std::hash<Key>>
			class IDContainer
		{

		public:
			IDContainer();

			void clear();

			void reserve(unsigned size);

			Object & operator[](unsigned index);

			Object const& operator[](unsigned index) const;

			unsigned getIndex(Key const& key) const;

			unsigned size() const;

			bool exists(Key const& key) const;

			Iterator<Object> getIterator() const;

			std::vector<Object> const& getConstArray() const;

			void push_back(Object const& newElement, Key const& key);

		protected:
			std::vector<Object> m_data; // contains the objet datas
			std::unordered_map<Key, unsigned, Hash> m_map;// used to be able to access to the element with key

		private:
			
		};

	#include "Utils/Container/IDContainer.inl"
	}
}