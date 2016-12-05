#include "Graphics/Layer/Layer.hpp"

using namespace dae::graphics;

Layer::Layer()
	: Layer(0)
{
	// nothing
}


Layer::Layer(unsigned depthLevel)
	: m_depthLevel(depthLevel)
{
	// nothing
}


Layer::Layer(unsigned depthLevel,
			 size_t vertexNumberMax,
			 size_t mergedDrawCapacity)
    : m_depthLevel(depthLevel),
      m_vertexArray(vertexNumberMax),
	  m_separateVertexArray(mergedDrawCapacity)
{
    // nothing
}


Layer::Layer(Layer const& displayLayer)
	: m_depthLevel(displayLayer.m_depthLevel),
      m_vertexArray(displayLayer.m_vertexArray),
	  m_separateVertexArray(displayLayer.m_separateVertexArray)
{
	// nothing
}


void Layer::setDepthLevel(unsigned depthLevel)
{
    m_depthLevel = depthLevel;
}


void Layer::addVertices(VertexArray const& vertexArray,
						TextureID const& textureID,
						sf::PrimitiveType primitve,
						bool separateDraw)
{
    m_vertexArray.add(vertexArray);

	m_separateVertexArray.add(textureID, 
							  primitve, 
							  vertexArray.getSize(), 
							  separateDraw);
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