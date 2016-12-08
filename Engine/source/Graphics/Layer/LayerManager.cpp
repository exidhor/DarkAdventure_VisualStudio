#include "Graphics/Layer/LayerManager.hpp"

using namespace dae::graphics;

LayerManager::LayerManager()
    : m_defaultVertexCapacity(0),
	  m_defaultMergedDrawCapacity(0),
      m_needToBeSorted(false)
{
    // nothing
}

LayerManager::LayerManager(size_t layerCapacity,
						   size_t defaultVertexCapacity,
						   size_t defaultMergedDrawCapacity)
        : m_layerFactory(),
		  m_defaultVertexCapacity(defaultVertexCapacity),
		  m_defaultMergedDrawCapacity(defaultMergedDrawCapacity),
          m_needToBeSorted(false)
{
   m_layerFactory.reserve(layerCapacity);
}

LayerManager::~LayerManager()
{
    // nothing
}

void LayerManager::reserve(size_t capacity)
{
	m_layerFactory.reserve(capacity);
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
    addLayer(depthLevel, m_defaultVertexCapacity, key);
}

void LayerManager::addLayer(unsigned depthLevel,
							size_t vertexCapacity,
							std::string const& key)
{
	addLayer(depthLevel, vertexCapacity, m_defaultMergedDrawCapacity, key);
}

void LayerManager::addLayer(unsigned depthLevel,
							size_t vertexCapacity,
							size_t mergedDrawCapacity,
							std::string const& key)
{
	m_needToBeSorted = true;

	m_layerFactory.AddLayer(depthLevel,
							vertexCapacity,
							mergedDrawCapacity,
	                        key);
}

void LayerManager::addVertices(DisplayPackage & displayPackage,
							   VertexArray const& vertexArray)
{
    unsigned layerIndex;

    if(displayPackage.displayIdIsUpToDate())
    {
        layerIndex = displayPackage.getLayerID().getValue();
    }
    else
    {
		// we refresh the cache
        layerIndex = m_layerFactory.getIndex(displayPackage.getLayerKey());
        displayPackage.setLayerID(layerIndex);
    }

    m_layerFactory[layerIndex].addVertices(vertexArray, 
    									   displayPackage.getTextureID(),
    									   displayPackage.getPrimitive(),
    									   displayPackage.isSeparateDraw());
}

void LayerManager::setDefaultVertexCapacity(size_t vertexCapacity)
{
	m_defaultVertexCapacity = vertexCapacity;
}

void LayerManager::setDefaultMergedDrawCapacity(size_t mergedDrawCapacity)
{
	m_defaultMergedDrawCapacity = mergedDrawCapacity;
}

size_t LayerManager::size() const
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