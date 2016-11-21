#include "Graphics/Layer/DisplayManager.hpp"

using namespace dae::graphics;

DisplayManager::DisplayManager()
    : m_lastLayerID(0),
	  m_defaultVertexLayerSize(0),
	  m_defaultDifferentVertexSize(0),
      m_needToBeSorted(false)
{
    srand((unsigned)time(NULL));
}

DisplayManager::DisplayManager(unsigned numberOfLayer,
							   unsigned defaultVertexLayerSize,
							   unsigned defaultDifferentVertexSize)
        : m_layerFactory(),
		  m_lastLayerID(0),
		  m_defaultVertexLayerSize(defaultVertexLayerSize),
		  m_defaultDifferentVertexSize(defaultDifferentVertexSize),
          m_needToBeSorted(false)
{
    srand((unsigned)time(NULL));

	m_layerFactory.reserve(numberOfLayer);
}

DisplayManager::~DisplayManager()
{
    // nothing
}

void DisplayManager::reserve(unsigned size)
{
	m_layerFactory.reserve(size);
}

void DisplayManager::prepare()
{
    clearLayers();

    if(m_needToBeSorted)
    {
		m_layerFactory.sort();

        m_needToBeSorted = false;
    }
}

void DisplayManager::addLayer(unsigned depthLevel,
                              std::string const& key)
{
    addLayer(depthLevel, m_defaultVertexLayerSize, key);
}

void DisplayManager::addLayer(unsigned depthLevel,
                              unsigned layerSize,
							  std::string const& key)
{
	addLayer(depthLevel, layerSize, m_defaultDifferentVertexSize, key);
}

void DisplayManager::addLayer(unsigned depthLevel,
							  unsigned vertexLayerSize,
							  unsigned differentVertexSize,
							  std::string const& key)
{
	m_lastLayerID++;
	m_needToBeSorted = true;

	m_layerFactory.AddLayer(depthLevel,
							m_lastLayerID,
							vertexLayerSize,
							differentVertexSize,
							key);
}

void DisplayManager::addVertices(DisplayPackage & displayPackage,
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

void DisplayManager::setDefaultVertexLayerSize(unsigned vertexLayerSize)
{
	m_defaultVertexLayerSize = vertexLayerSize;
}

void DisplayManager::setDefaultDifferentVertexSize(unsigned differentVertexSize)
{
	m_defaultDifferentVertexSize = differentVertexSize;
}

unsigned DisplayManager::size() const
{
    return m_layerFactory.size();
}

void DisplayManager::clearLayers()
{
	// we dont need here the iterator of the layerFactory 
	// because the order doesnt matter
    for(unsigned i = 0; i < m_layerFactory.size(); i++) 
    {
		m_layerFactory[i].clear();
    }
}