#include "Graphics/Layer/Layer.hpp"

using namespace dae::graphics;


Layer::Layer(std::string const& key, 
			 unsigned depthLevel,
			 size_t vertexNumberMax,
			 size_t mergedDrawCapacity)
    : m_key(key),
	  m_depthLevel(depthLevel),
      m_vertexArray(vertexNumberMax),
	  m_mergedDrawArray(mergedDrawCapacity)
{
    // nothing
}


Layer::Layer(Layer const& displayLayer)
	: m_key(displayLayer.m_key),
	  m_depthLevel(displayLayer.m_depthLevel),
      m_vertexArray(displayLayer.m_vertexArray),
	  m_mergedDrawArray(displayLayer.m_mergedDrawArray)
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

	m_mergedDrawArray.add(textureID, 
							  primitve, 
							  vertexArray.getSize(), 
							  separateDraw);
}

void Layer::clear()
{
    m_vertexArray.clear();
	m_mergedDrawArray.clear();
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

	for(unsigned i = 0; i < m_mergedDrawArray.size(); i++)
	{
		renderState.texture = textureManager.getTexture(m_mergedDrawArray.getTextureID(i));

		renderTarget.draw(&m_vertexArray[vertexIndex], 
						  m_mergedDrawArray.getSize(i),
						  m_mergedDrawArray.getPrimitive(i),
						  renderState);

		vertexIndex += m_mergedDrawArray.getSize(i);
	}
}