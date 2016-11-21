#include "Graphics/Layer/LayerArray.hpp"

using namespace dae::graphics;

LayerArray::LayerArray()
    :   MappedArray()
{
    // nothing
}

LayerArray::LayerArray(unsigned size)
    :   MappedArray(size)
{
    // nothing
}

LayerArray::~LayerArray()
{
    // nothing
}

/*
void LayerArray::sort()
{
    if(size() == 0)
        return;

    // we first sort the index
    std::vector<unsigned> indices(size());

    for(unsigned i = 0; i < indices.size(); i++)
    {
        indices[i] = i;
    }

    quicksort(indices, 0, size() - 1);

    // We make a copy of the array
    std::vector <Layer> buffer(m_array);

    // We use this copy to order the array from the indices array sorted
    for(unsigned oldIndex = 0; oldIndex < indices.size(); oldIndex++)
    {
        unsigned newIndex = indices[oldIndex];
        m_array[oldIndex] = buffer[newIndex];
        m_array[oldIndex].setID(newIndex);
    }

    // We regenerate the map to fit with the index changes
    generateMap();
}*/

void LayerArray::sort()
{
	if (size()==0)
		return;

	quicksort(m_indexArray, 0, size()-1);
}

void LayerArray::generateMap()
{
	m_map.clear();

    for(unsigned index = 0; index  < m_array.size(); index++)
    {
        m_map.emplace(m_array[index].getKey(), index);
    }
}

void LayerArray::quicksort(std::vector<unsigned> & vector,
                           int firstIndex,
                           int lastIndex)
{
    if(firstIndex < lastIndex)
    {
        // choice of the pivot by random way, better than fixed value
        // but it cans be improve by computing the median in O(n)
        int pivot = rand() % (lastIndex - firstIndex) + firstIndex;

        pivot = partition(vector, firstIndex, lastIndex, pivot);
        quicksort(vector, firstIndex, pivot - 1);
        quicksort(vector, pivot + 1, lastIndex);
    }
}

unsigned LayerArray::partition(std::vector<unsigned> & vector,
                               int firstIndex,
                               int lastIndex,
                               int pivot)
{
    swap(vector, pivot, lastIndex);
    unsigned j = firstIndex;

    for(int i = firstIndex; i < lastIndex - 1; i++)
    {
        if(m_array[vector[i]].getDepthLevel() <=
            m_array[vector[lastIndex]].getDepthLevel())
        {
            swap(vector, i, j);
            j++;
        }
    }

    swap(vector, lastIndex, j);

    return j;
}

void LayerArray::swap(std::vector<unsigned> & vector,
                      unsigned index_0,
                      unsigned index_1)
{
    unsigned tmp = vector[index_0];
    vector[index_0] = vector[index_1];
    vector[index_1] = tmp;
}

Layer & LayerArray::getOrderedLayer(unsigned index)
{
	return m_array[m_indexArray[index]];
}