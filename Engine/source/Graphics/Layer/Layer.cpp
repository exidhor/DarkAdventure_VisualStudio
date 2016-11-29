#include "Graphics/Layer/Layer.hpp"

using namespace dae::graphics;

Layer::Layer()
	: m_id(0),
	m_depthLevel(0)
{
	// nothing
}

Layer::Layer(unsigned id, 
			 unsigned vertexNumberMax, 
			 unsigned differentVertexNumberMax)
    : m_id(id), 
	  m_depthLevel(0),
      m_vertexArray(vertexNumberMax),
	  m_separateVertexArray(differentVertexNumberMax)
{
    // nothing
}

Layer::Layer(Layer const& displayLayer)
	: m_id(displayLayer.m_id.getValue()),
	  m_depthLevel(displayLayer.m_depthLevel),
      m_vertexArray(displayLayer.m_vertexArray),
	  m_separateVertexArray(displayLayer.m_separateVertexArray)
{
	// nothing
}

Layer::~Layer()
{
    // nothing
}

void Layer::initDepthLevel(unsigned depthLevel)
{
    m_depthLevel = depthLevel;
}

void Layer::addVertices(VertexArray const& vertexArray,
						TextureID const& textureID,
						sf::PrimitiveType primitve,
						bool separateDraw)
{
    m_vertexArray.add(vertexArray);
	m_separateVertexArray.add(textureID, primitve, vertexArray.getSize(), separateDraw);
}

void Layer::clear()
{
    m_vertexArray.clear();
	m_separateVertexArray.clear();
}

unsigned Layer::getDepthLevel() const
{
    return m_depthLevel;
}

void Layer::setID(unsigned newID)
{
    m_id = newID;
}

void Layer::draw(sf::RenderTarget & renderTarget,
				 TextureManager const& textureManager,
				 sf::RenderStates renderState)
{
	unsigned vertexIndex = 0;
	for(unsigned i = 0; i < m_separateVertexArray.size(); i++)
	{
		renderState.texture = textureManager.getTexture(m_separateVertexArray.getTextureID(i));

		renderTarget.draw(&m_vertexArray[vertexIndex], 
						  m_separateVertexArray.getSize(i),
						  m_separateVertexArray.getPrimitive(i),
						  renderState);

		vertexIndex += m_separateVertexArray.getSize(i);
	}
}