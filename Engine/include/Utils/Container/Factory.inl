template <typename Object>
Factory<Object>::Factory()
	: m_model(nullptr),
	m_allocationSize(1) // by default, allocate only one by one
{
	// nothing
}

template <class Object>
Factory<Object>::~Factory()
{
	if (m_model)
	{
		delete m_model;
	}
}

template <class Object>
void Factory<Object>::setModel(Object const& model)
{
	// delete the previous model if any
	if (m_model)
	{
		delete m_model;
	}

	m_model = new Object(model);
}

template <class Object>
void Factory<Object>::makeEverythingFree()
{
	// clear all the old free elements
	while(!m_freeElementIndices.empty())
	{
		m_freeElementIndices.pop();
	}

	// and then add every object to the stack of the free elements
	for (unsigned i = 0; i < m_idTable.size(); i++)
	{
		m_freeElementIndices.push(i);
	}
}

template <class Object>
void Factory<Object>::construct(unsigned numberOfElements)
{
	createModelIfAny();

	for (unsigned i = 0; i < numberOfElements; i++)
	{
		m_idTable.push_back(Stock<Object>(m_model));
	}
}

template <class Object>
unsigned Factory<Object>::getAvailableID()
{
	if(m_freeElementIndices.empty())
	{
		increaseSize();
	}

	unsigned freeIndex = m_freeElementIndices.top();
	m_freeElementIndices.pop();

	return freeIndex;
}

template <class Object>
void Factory<Object>::free(unsigned id)
{
	m_freeElementIndices.push(id);
}

template <class Object>
void Factory<Object>::setAllocationSize(unsigned allocationSize)
{
	m_allocationSize = allocationSize;
}

template <class Object>
unsigned Factory<Object>::size() const
{
	return m_idTable.size();
}


template <class Object>
void Factory<Object>::increaseSize()
{
	createModelIfAny();

	// create new elements
	m_idTable.reserve(m_idTable.capacity() + m_allocationSize);

	for (unsigned i = 0; i < m_allocationSize; i++)
	{
		m_idTable.push_back(m_model);

		m_freeElementIndices.push(m_idTable.size() - 1);
	}
}

template <class Object>
void Factory<Object>::createModelIfAny()
{
	if (!m_model)
	{
		// try to construct one with the default constructor
		m_model = new Object();
	}
}
