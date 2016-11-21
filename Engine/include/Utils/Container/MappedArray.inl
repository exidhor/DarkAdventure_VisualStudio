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
void MappedArray<Object, Key, CompareData, Hash>::push_back(Object const& newElement, Key const& key)
{
	m_iDContainer.push_back(newElement, key);

	unsigned index = m_iDContainer.size()-1;

	m_indexArray.push_back(index);
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