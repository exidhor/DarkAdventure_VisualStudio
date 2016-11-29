#include "Graphics/Render/VertexArray.hpp"

using namespace dae::graphics;
using namespace dae::utils;
using namespace dae;

VertexArray::VertexArray()
        : VertexArray(0)
{
    // nothing
}

VertexArray::VertexArray(int size)
{
	m_vertices.reserve(size);
}

VertexArray::VertexArray(std::vector<Vec2f> const& vertexPosition)
    : VertexArray(vertexPosition.size())
{
    for(unsigned i = 0; i < vertexPosition.size(); i++)
    {
        m_vertices.emplace_back(sf::Vector2f(vertexPosition[i].x,
								             vertexPosition[i].y));
    }
}

VertexArray::VertexArray(VertexArray const& vertexArray)
{
	copy(vertexArray);
}

VertexArray::~VertexArray()
{
    // nothing
}

void VertexArray::copy(VertexArray const& vertexArray)
{
	m_vertices.reserve(vertexArray.m_vertices.capacity());
	m_vertices.resize(vertexArray.m_vertices.size());

	for (unsigned i = 0; i < vertexArray.m_vertices.size(); i++)
	{
		m_vertices[i] = vertexArray.m_vertices[i];
	}
}

sf::Vertex & VertexArray::operator[](unsigned index)
{
    assert(index < m_vertices.size());

    return m_vertices[index];
}

sf::Vertex const& VertexArray::operator[](unsigned index) const
{
    assert(index < m_vertices.size());

    return m_vertices[index];
}

void VertexArray::resize(int vertexSize)
{
    reallocateArray(vertexSize);
}

void VertexArray::clear()
{
    m_vertices.clear();
}

void VertexArray::add(VertexArray const& vertexArray)
{
    if(m_vertices.size() + vertexArray.getSize() > m_vertices.capacity())
    {
        std::cerr << "ERROR : trying to overflow the capacity of the vertexArray." << std::endl;
        std::cerr << "\tcapacity of the vertexArray : " << m_vertices.capacity() << std::endl;
        std::cerr << "\tactual size of the vertexArray : " << m_vertices.size() << std::endl;
        std::cerr << "\tnumber of element we try to add : " << vertexArray.getSize() << std::endl;
        std::cerr << "\t" << m_vertices.size() + vertexArray.getSize() - m_vertices.capacity() << " additional emplacements needed" << std::endl;

        return;
    }

    for(unsigned i = 0; i < vertexArray.getSize(); i++)
    {
        m_vertices.push_back(vertexArray.m_vertices[i]);
    }
}

void VertexArray::setTexturePoint(utils::AlignedRect const& rect)
{
	// top left point
	m_vertices[0].texCoords.x = rect.left;
	m_vertices[0].texCoords.y = rect.top;

	// top right point
	m_vertices[1].texCoords.x = rect.getRight();
	m_vertices[1].texCoords.y = rect.top;

	// bot right point
	m_vertices[2].texCoords.x = rect.getRight();
	m_vertices[2].texCoords.y = rect.getBottom();

	// bot left point
	m_vertices[3].texCoords.x = rect.left;
	m_vertices[3].texCoords.y = rect.getBottom();
}

void VertexArray::setColor(sf::Color const& color)
{
    for(unsigned i = 0; i < m_vertices.size(); i++)
    {
        m_vertices[i].color = color;
    }
}

bool VertexArray::isVoid() const
{
    return getSize() == 0;
}

unsigned VertexArray::getSize() const
{
    return m_vertices.size();
}

sf::Color const& VertexArray::getColor() const
{
    return m_vertices[0].color;
}

void VertexArray::copyArray(sf::Vertex* dest, sf::Vertex* origin, int size)
{
    memcpy((void*) dest, (void*) origin, size * sizeof(sf::Vertex));
}

void VertexArray::copyArray(std::vector<sf::Vertex> & dest, std::vector<sf::Vertex> const& origin)
{
    if(dest.size() < origin.size())
    {
        dest.resize(origin.size());
    }

    for(unsigned i = 0; i < dest.size(); i++)
    {
        dest[i] = origin[i];
    }
}

void VertexArray::reallocateArray(int size)
{
    m_vertices.resize((unsigned)size);
}
