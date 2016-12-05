#include "Graphics/Layer/LayerManager.hpp"

using namespace dae::graphics;

LayerManager::LayerManager()
    : m_defaultVertexLayerSize(0),
	  m_defaultDifferentVertexSize(0),
      m_needToBeSorted(false)
{
    // nothing
}

LayerManager::LayerManager(unsigned numberOfLayer,
							   unsigned defaultVertexLayerSize,
							   unsigned defaultDifferentVertexSize)
        : m_layerFactory(),
		  m_defaultVertexLayerSize(defaultVertexLayerSize),
		  m_defaultDifferentVertexSize(defaultDifferentVertexSize),
          m_needToBeSorted(false)
{
   m_layerFactory.reserve(numberOfLayer);
}

LayerManager::~LayerManager()
{
    // nothing
}

void LayerManager::reserve(unsigned size)
{
	m_layerFactory.reserve(size);
}

void LayerManager::prepare()
{
    clearLayers();

    if(m_needToBeSorted)
    {
		m_layerFactory.sort();

        m_needToBeSorted = false;
    }
}

void LayerManager::addLayer(unsigned depthLevel,
                              std::string const& key)
{
    addLayer(depthLevel, m_defaultVertexLayerSize, key);
}

void LayerManager::addLayer(unsigned depthLevel,
                              unsigned layerSize,
							  std::string const& key)
{
	addLayer(depthLevel, layerSize, m_defaultDifferentVertexSize, key);
}

void LayerManager::addLayer(unsigned depthLevel,
							  unsigned vertexLayerSize,
							  unsigned differentVertexSize,
							  std::string const& key)
{
	m_needToBeSorted = true;

	m_layerFactory.AddLayer(depthLevel,
	                        vertexLayerSize,
	                        differentVertexSize,
	                        key);
}

void LayerManager::addVertices(DisplayPackage & displayPackage,
                                 VertexArray const& vertexArray)
{
    unsigned layerIndex;

    if(displayPackage.displayIdIsUpToDate())
    {
        layerIndex = displayPackage.getDisplayLayerID().getValue();
    }
    else
    {
        layerIndex = m_layerFactory.getIndex(displayPackage.getLayerKey());
        displayPackage.setDisplayLayerID(layerIndex);
    }

    m_layerFactory[layerIndex].addVertices(vertexArray, 
    									   displayPackage.getTextureID(),
    									   displayPackage.getPrimitive(),
    									   displayPackage.isSeparateDraw());
}

void LayerManager::setDefaultVertexLayerSize(unsigned vertexLayerSize)
{
	m_defaultVertexLayerSize = vertexLayerSize;
}

void LayerManager::setDefaultDifferentVertexSize(unsigned differentVertexSize)
{
	m_defaultDifferentVertexSize = differentVertexSize;
}

unsigned LayerManager::size() const
{
    return m_layerFactory.size();
}

void LayerManager::clearLayers()
{
	// we dont need here the iterator of the layerFactory 
	// because the order doesnt matter
    for(unsigned i = 0; i < m_layerFactory.size(); i++) 
    {
		m_layerFactory[i].clear();
    }
}