template <typename Object, typename Key, typename Hash>
IDContainer<Object, Key, Hash>::IDContainer()
{
	// nothing
}

template <typename Object, typename Key, typename Hash>
void IDContainer<Object, Key, Hash>::clear()
{
	m_data.clear();
	m_map.clear();
}

template <typename Object, typename Key, typename Hash>
void IDContainer<Object, Key, Hash>::reserve(unsigned size)
{
	m_data.reserve(size);
	m_map.reserve(size);
}

template <typename Object, typename Key, typename Hash>
void IDContainer<Object, Key, Hash>::push_back(Key const& key, Object const& newElement)
{
	m_data.push_back(newElement);

	constructKey(key, lastIndex());
}

template <typename Object, typename Key, typename Hash>
template <class ... Args>
void IDContainer<Object, Key, Hash>::emplace_back(Key const& key, Args&& ... args)
{
	m_data.emplace_back(args);

	constructKey(key, lastIndex());
}

template <typename Object, typename Key, typename Hash>
Object & IDContainer<Object, Key, Hash>::operator[](unsigned index)
{
	return m_data[index];
}

template <typename Object, typename Key, typename Hash>
Object const& IDContainer<Object, Key, Hash>::operator[](unsigned index) const
{
	return m_data[index];
}

template <typename Object, typename Key, typename Hash>
unsigned IDContainer<Object, Key, Hash>::getIndex(Key const& key) const
{
	return m_map.at(key);
}

template <typename Object, typename Key, typename Hash>
unsigned IDContainer<Object, Key, Hash>::size() const
{
	return m_data.size();
}

template <typename Object, typename Key, typename Hash>
bool IDContainer<Object, Key, Hash>::exists(Key const& key) const
{
	typename std::unordered_map<const Key, unsigned, Hash>::const_iterator got = m_map.find(key);

	return !(got == m_map.end());
}

template <typename Object, typename Key, typename Hash>
Iterator<Object> IDContainer<Object, Key, Hash>::getIterator() const
{
	return Iterator<Object>(m_data);
}

template <typename Object, typename Key, typename Hash>
std::vector<Object> const& IDContainer<Object, Key, Hash>::getConstArray() const
{
	return m_data;
}

template <typename Object, typename Key, typename Hash>
unsigned IDContainer<Object, Key, Hash>::lastIndex() const
{
	return m_data.size() - 1;
}

template <typename Object, typename Key, typename Hash>
void IDContainer<Object, Key, Hash>::constructKey(Key const& key, unsigned index)
{
	m_map.emplace(key, index);
}