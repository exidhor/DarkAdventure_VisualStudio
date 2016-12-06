template <typename Object, typename Key, typename Hash>
MapTable<Object, Key, Hash>::MapTable()
{
	// nothing
}

template <typename Object, typename Key, typename Hash>
void MapTable<Object, Key, Hash>::clear()
{
	m_pool.clear();
	m_map.clear();
}

template <typename Object, typename Key, typename Hash>
void MapTable<Object, Key, Hash>::reserve(unsigned size)
{
	m_pool.reserve(size);
	m_map.reserve(size);
}

template <typename Object, typename Key, typename Hash>
void MapTable<Object, Key, Hash>::push_back(Key const& key, Object const& newElement)
{
	m_pool.push_back(newElement);

	constructKey(key, lastIndex());
}

template <typename Object, typename Key, typename Hash>
template <class ... Args>
void MapTable<Object, Key, Hash>::emplace_back(Key const& key, Args&& ... args)
{
	m_pool.emplace_back(args);

	constructKey(key, lastIndex());
}

template <typename Object, typename Key, typename Hash>
Object & MapTable<Object, Key, Hash>::operator[](unsigned index)
{
	return m_pool[index];
}

template <typename Object, typename Key, typename Hash>
Object const& MapTable<Object, Key, Hash>::operator[](unsigned index) const
{
	return m_pool[index];
}

template <typename Object, typename Key, typename Hash>
unsigned MapTable<Object, Key, Hash>::getIndex(Key const& key) const
{
	return m_map.at(key);
}

template <typename Object, typename Key, typename Hash>
unsigned MapTable<Object, Key, Hash>::size() const
{
	return m_pool.size();
}

template <typename Object, typename Key, typename Hash>
bool MapTable<Object, Key, Hash>::exists(Key const& key) const
{
	typename std::unordered_map<const Key, unsigned, Hash>::const_iterator got = m_map.find(key);

	return !(got == m_map.end());
}

template <typename Object, typename Key, typename Hash>
Iterator<Object> MapTable<Object, Key, Hash>::getIterator() const
{
	return Iterator<Object>(m_pool.getConstArray());
}

template <typename Object, typename Key, typename Hash>
std::vector<Object> const& MapTable<Object, Key, Hash>::getConstArray() const
{
	return m_pool.getConstArray();
}

template <typename Object, typename Key, typename Hash>
unsigned MapTable<Object, Key, Hash>::lastIndex() const
{
	return m_pool.size() - 1;
}

template <typename Object, typename Key, typename Hash>
unsigned MapTable<Object, Key, Hash>::capacity() const
{
	return m_pool.capacity();
}

template <typename Object, typename Key, typename Hash>
void MapTable<Object, Key, Hash>::constructKey(Key const& key, unsigned index)
{
	m_map.emplace(key, index);
}