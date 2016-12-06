#pragma once

#include <functional>
#include <vector>
#include <unordered_map>
#include "Utils/Container/IDTable.hpp"
#include "Utils/Container/Iterator.hpp"
#include <algorithm>

namespace dae
{
	namespace utils
	{

		template <typename Object,
			typename Key,
			typename Hash = std::hash<Key>>
		class MapTable
		{
		public:
			MapTable();

			void clear();

			void reserve(unsigned size);

			void push_back(Key const& key, Object const& newElement);

			template <class ... Args>
			void emplace_back(Key const& key, Args&& ... args);

			Object & operator[](unsigned index);

			Object const& operator[](unsigned index) const;

			unsigned getIndex(Key const& key) const;

			unsigned size() const;

			bool exists(Key const& key) const;

			Iterator<Object> getIterator() const;

			std::vector<Object> const& getConstArray() const;

			unsigned lastIndex() const;

			unsigned capacity() const;

		private:
			void constructKey(Key const& key, unsigned index);

			IDTable<Object> m_pool; //std::vector<Object> m_data; // contains the objet datas
			std::unordered_map<Key, unsigned, Hash> m_map;// used to be able to access to the element with key			
		};

	#include "Utils/Container/MapTable.inl"
	}
}