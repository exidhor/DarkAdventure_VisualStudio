#include "Graphics/Layer/SeparateVertexArray.hpp"

using namespace dae::graphics;

SeparateVertexArray::SeparateVertexArray()
{
	// nothing
}

SeparateVertexArray::SeparateVertexArray(unsigned reservedSize)
	: m_textureID(reservedSize),
	  m_primitives(reservedSize),
	  m_sizes(reservedSize)
{
	// nothing
}

void SeparateVertexArray::reserve(unsigned size)
{
	clear();

	m_textureID.reserve(size);
	m_sizes.reserve(size);
	m_primitives.reserve(size);
}

void SeparateVertexArray::clear()
{
	m_textureID.clear();
	m_sizes.clear();
	m_primitives.clear();
}

void SeparateVertexArray::add(TextureID const& textureID, 
							  sf::PrimitiveType primitive, 
							  unsigned size,
							  bool separateDraw)
{
	if(this->size() != 0
	    && !separateDraw
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
	}
}

TextureID const& SeparateVertexArray::getTextureID(unsigned index) const
{
	return m_textureID[index];
}

sf::PrimitiveType SeparateVertexArray::getPrimitive(unsigned index) const
{
	return m_primitives[index];
}

unsigned SeparateVertexArray::getSize(unsigned index) const
{
	return m_sizes[index];
}

unsigned SeparateVertexArray::size() const
{
	return m_textureID.size();
}

TextureID const& SeparateVertexArray::getLastTextureID() const
{
	return m_textureID[this->size()-1];
}

sf::PrimitiveType SeparateVertexArray::getLastPrimitive() const
{
	return m_primitives[this->size()-1];
}