#include "Graphics/Layer/MergedDrawArray.hpp"

using namespace dae::graphics;

MergedDrawArray::MergedDrawArray()
	: m_lastIsSperateDraw(false)
{
	// nothing
}

MergedDrawArray::MergedDrawArray(unsigned reservedSize)
	: m_lastIsSperateDraw(false)
{
	reserve(reservedSize);
}

void MergedDrawArray::reserve(unsigned size)
{
	m_textureID.reserve(size);
	m_sizes.reserve(size);
	m_primitives.reserve(size);
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
							  unsigned size,
							  bool separateDraw)
{
	if(this->size() != 0
	    && !separateDraw
	    && !m_lastIsSperateDraw
		&& getLastTextureID() == textureID 
		&& getLastPrimitive() == primitive)
	{
		unsigned last = this->size()-1;
		m_sizes[last] += size;
	}
	else
	{
		m_textureID.push_back(textureID);
		m_primitives.push_back(primitive);
		m_sizes.push_back(size);

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

unsigned MergedDrawArray::getSize(unsigned index) const
{
	return m_sizes[index];
}

unsigned MergedDrawArray::size() const
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