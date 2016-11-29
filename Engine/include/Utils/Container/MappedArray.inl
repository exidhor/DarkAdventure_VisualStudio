template <typename Object, typename Key, typename CompareData, typename Hash>
MappedArray<Object, Key, CompareData, Hash>::MappedArray()
{
	// nothing
}

template <typename Object, typename Key, typename CompareData, typename Hash>
void MappedArray<Object, Key, CompareData, Hash>::clear()
{
	m_iDContainer.clear();
	m_indexArray.clear();
}

template <typename Object, typename Key, typename CompareData, typename Hash>
void MappedArray<Object, Key, CompareData, Hash>::reserve(unsigned size)
{
	m_iDContainer.reserve(size);
	m_indexArray.reserve(size);
}

template <typename Object, typename Key, typename CompareData, typename Hash>
void MappedArray<Object, Key, CompareData, Hash>::sort()
{
	CompareData compareData(m_iDContainer.getConstArray());

	std::sort(m_indexArray.begin(),
			  m_indexArray.end(),
		      std::bind(&CompareData::compare,
			            &compareData,
			            std::placeholders::_1,
		                std::placeholders::_2));
}

template <typename Object, typename Key, typename CompareData, typename Hash>
Object & MappedArray<Object, Key, CompareData, Hash>::operator[](unsigned index)
{
	return m_iDContainer[index];
}

template <typename Object, typename Key, typename CompareData, typename Hash>
Object const& MappedArray<Object, Key, CompareData, Hash>::operator[](unsigned index) const
{
	return m_iDContainer[index];
}

template <typename Object, typename Key, typename CompareData, typename Hash>
unsigned MappedArray<Object, Key, CompareData, Hash>::getIndex(Key const& key) const
{
	return m_iDContainer.getIndex(key);
}

template <typename Object, typename Key, typename CompareData, typename Hash>
unsigned MappedArray<Object, Key, CompareData, Hash>::size() const
{
	return m_iDContainer.size();
}

template <typename Object, typename Key, typename CompareData, typename Hash>
bool MappedArray<Object, Key, CompareData, Hash>::exists(Key const& key) const
{
	return m_iDContainer.exists(key);
}

template <typename Object, typename Key, typename CompareData, typename Hash>
Iterator<unsigned> MappedArray<Object, Key, CompareData, Hash>::getIterator() const
{
	return Iterator<unsigned>(m_indexArray);
}

template <typename Object, typename Key, typename CompareData, typename Hash>
void MappedArray<Object, Key, CompareData, Hash>::push_back(Key const& key, Object const& newElement)
{
	m_iDContainer.push_back(key, newElement);

	m_indexArray.push_back(m_iDContainer.lastIndex());
}

template <typename Object, typename Key, typename CompareData, typename Hash>
template <class ... Args>
void MappedArray<Object, Key, CompareData, Hash>::emplace_back(Key const& key, Args && ... args)
{
	m_iDContainer.emplace_back(key, args);

	m_indexArray.push_back(m_iDContainer.lastIndex());
}