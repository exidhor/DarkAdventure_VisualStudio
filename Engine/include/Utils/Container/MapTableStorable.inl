template <typename Object, typename Key, typename CompareData, typename Hash>
MapTableStorable<Object, Key, CompareData, Hash>::MapTableStorable()
{
	// nothing
}

template <typename Object, typename Key, typename CompareData, typename Hash>
void MapTableStorable<Object, Key, CompareData, Hash>::clear()
{
	m_iDTable.clear();
	m_indexArray.clear();
}

template <typename Object, typename Key, typename CompareData, typename Hash>
void MapTableStorable<Object, Key, CompareData, Hash>::reserve(unsigned size)
{
	m_iDTable.reserve(size);
	m_indexArray.reserve(size);
}

template <typename Object, typename Key, typename CompareData, typename Hash>
void MapTableStorable<Object, Key, CompareData, Hash>::sort()
{
	CompareData compareData(m_iDTable.getConstArray());

	std::sort(m_indexArray.begin(),
			  m_indexArray.end(),
			  std::bind(&CompareData::compare,
						&compareData,
			            std::placeholders::_1,
		                std::placeholders::_2));
}

template <typename Object, typename Key, typename CompareData, typename Hash>
Object & MapTableStorable<Object, Key, CompareData, Hash>::operator[](unsigned index)
{
	return m_iDTable[index];
}

template <typename Object, typename Key, typename CompareData, typename Hash>
Object const& MapTableStorable<Object, Key, CompareData, Hash>::operator[](unsigned index) const
{
	return m_iDTable[index];
}

template <typename Object, typename Key, typename CompareData, typename Hash>
unsigned MapTableStorable<Object, Key, CompareData, Hash>::getIndex(Key const& key) const
{
	return m_iDTable.getIndex(key);
}

template <typename Object, typename Key, typename CompareData, typename Hash>
unsigned MapTableStorable<Object, Key, CompareData, Hash>::size() const
{
	return m_iDTable.size();
}

template <typename Object, typename Key, typename CompareData, typename Hash>
bool MapTableStorable<Object, Key, CompareData, Hash>::exists(Key const& key) const
{
	return m_iDTable.exists(key);
}

template <typename Object, typename Key, typename CompareData, typename Hash>
Iterator<unsigned> MapTableStorable<Object, Key, CompareData, Hash>::getIterator() const
{
	return Iterator<unsigned>(m_indexArray);
}

template <typename Object, typename Key, typename CompareData, typename Hash>
unsigned MapTableStorable<Object, Key, CompareData, Hash>::capacity() const
{
	return m_iDTable.capacity();
}

template <typename Object, typename Key, typename CompareData, typename Hash>
void MapTableStorable<Object, Key, CompareData, Hash>::push_back(Key const& key, Object const& newElement)
{
	m_iDTable.push_back(key, newElement);

	m_indexArray.push_back(m_iDTable.lastIndex());
}

template <typename Object, typename Key, typename CompareData, typename Hash>
template <class ... Args>
void MapTableStorable<Object, Key, CompareData, Hash>::emplace_back(Key const& key, Args && ... args)
{
	m_iDTable.emplace_back(key, args);

	m_indexArray.push_back(m_iDTable.lastIndex());
}