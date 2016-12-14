#pragma once

#include <stack>
#include "Utils/Container/IDTable.hpp"


namespace dae
{
	namespace utils
	{
		template <class Object>
		class Factory
		{
		public:
			Factory();

			~Factory();

			void setModel(Object const& model);

			void makeEverythingFree();

			void construct(unsigned numberOfElements);

			unsigned getAvailableID();

			void free(unsigned id);

			void setAllocationSize(unsigned allocationSize);

			unsigned size() const;

		private:
			void increaseSize();

			void createModelIfAny();

			Object*              m_model;
			IDTable<Object>      m_idTable;
			std::stack<unsigned> m_freeElementIndices;

			unsigned             m_allocationSize;
		};

	#include "Utils/Container/Factory.inl"
	}
}
