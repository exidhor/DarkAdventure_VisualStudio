template <typename Object>
IDTable<Object>::IDTable()
{
	// nothing
}

template <typename Object>
void IDTable<Object>::clear()
{
	m_data.clear();
}

template <typename Object>
void IDTable<Object>::reserve(unsigned size)
{
	m_data.reserve(size);
}

template <typename Object>
void IDTable<Object>::push_back(Object const& newElement)
{
	m_data.push_back(newElement);
}

template <typename Object>
template <class ... Args>
void IDTable<Object>::emplace_back(Args&& ... args)
{
	m_data.emplace_back(args);
}

template <typename Object>
Object & IDTable<Object>::operator[](unsigned index)
{
	return m_data[index];
}

template <typename Object>
Object const& IDTable<Object>::operator[](unsigned index) const
{
	return m_data[index];
}

template <typename Object>
unsigned IDTable<Object>::size() const
{
	return m_data.size();
}

template <typename Object>
unsigned IDTable<Object>::capacity() const
{
	return m_data.capacity();
}

template <typename Object>
Iterator<Object> IDTable<Object>::getIterator() const
{
	return Iterator<Object>(m_data);
}

template <typename Object>
std::vector<Object> const& IDTable<Object>::getConstArray() const
{
	return m_data;
}

template <typename Object>
Object const& IDTable<Object>::last() const
{
	return m_data[m_data.size() - 1];
}

template <typename Object>
Object & IDTable<Object>::last()
{
	return m_data[m_data.size() - 1];
}