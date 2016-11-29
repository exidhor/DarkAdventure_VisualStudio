#pragma once

#ifndef DEF_MAPPED_ARRAY_HPP
#define DEF_MAPPED_ARRAY_HPP

#include <functional>
#include <vector>
#include "Utils/Container/Iterator.hpp"
#include "Utils/Container/IDContainer.hpp"


namespace dae
{
	namespace utils
	{
		

		template <typename Object, 
			      typename Key,
			      typename CompareData = std::less_equal<Object>,
			      typename Hash = std::hash<Key>>
		class MappedArray
		{
			typedef bool(CompareData::*compare)(int, int);

		public :
			MappedArray();

			void clear();

			void reserve(unsigned size);

			void sort();

			Object & operator[](unsigned index);

			Object const& operator[](unsigned index) const;

			unsigned getIndex(Key const& key) const;
			
			unsigned size() const;

			bool exists(Key const& key) const;

			Iterator<unsigned> getIterator() const;

		protected:
			void push_back(Key const& key, Object const& newElement);
			
			template <class ... Args>
			void emplace_back(Key const& key, Args&& ... args);

		private:
			IDContainer<Object, Key, Hash> m_iDContainer;

			// used to modify (like a sort) the structure data
			// without modifying the ID.
			std::vector<unsigned> m_indexArray;
		};

	#include "Utils/Container/MappedArray.inl"
	}
}

#endif // DEF_MAPPED_ARRAY_HPP