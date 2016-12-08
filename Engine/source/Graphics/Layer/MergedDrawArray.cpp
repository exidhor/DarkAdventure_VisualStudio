#include "Graphics/Layer/MergedDrawArray.hpp"

using namespace dae::graphics;

MergedDrawArray::MergedDrawArray()
	: m_lastIsSperateDraw(false)
{
	// nothing
}

MergedDrawArray::MergedDrawArray(size_t capacity)
	: m_lastIsSperateDraw(false)
{
	reserve(capacity);
}

void MergedDrawArray::reserve(size_t capacity)
{
	m_textureID.reserve(capacity);
	m_sizes.reserve(capacity);
	m_primitives.reserve(capacity);
}

void MergedDrawArray::clear()
{
	m_textureID.clear();
	m_sizes.clear();
	m_primitives.clear();

	m_lastIsSperateDraw = false;
}

void MergedDrawArray::add(TextureID const& textureID, 
						  sf::PrimitiveType primitive,
						  size_t numberOfVertices,
						  bool separateDraw)
{
	if(size() != 0
	    && !separateDraw
	    && !m_lastIsSperateDraw
		&& getLastTextureID() == textureID 
		&& getLastPrimitive() == primitive)
	{
		// we can merge it
		unsigned last = size()-1;
		m_sizes[last] += numberOfVertices;
	}
	else
	{
		// we create a new "draw"
		m_textureID.push_back(textureID);
		m_primitives.push_back(primitive);
		m_sizes.push_back(numberOfVertices);

		m_lastIsSperateDraw = separateDraw;
	}
}

TextureID const& MergedDrawArray::getTextureID(unsigned index) const
{
	return m_textureID[index];
}

sf::PrimitiveType MergedDrawArray::getPrimitive(unsigned index) const
{
	return m_primitives[index];
}

size_t MergedDrawArray::getSize(unsigned index) const
{
	return m_sizes[index];
}

size_t MergedDrawArray::size() const
{
	return m_textureID.size();
}

TextureID const& MergedDrawArray::getLastTextureID() const
{
	return m_textureID[this->size()-1];
}

sf::PrimitiveType MergedDrawArray::getLastPrimitive() const
{
	return m_primitives[this->size()-1];
}