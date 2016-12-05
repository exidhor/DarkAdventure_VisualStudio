#include "Graphics/GraphicsEngine.hpp"

using namespace dae::graphics;

GraphicsEngine::GraphicsEngine()
    : m_window(nullptr)
{
    // nothing
}

GraphicsEngine::~GraphicsEngine()
{
    // nothing
}

void GraphicsEngine::init(unsigned numberOfLayer)
{
    m_layerManager.reserve(numberOfLayer);
}

void GraphicsEngine::addLayer(unsigned depthLevel,
							  std::string const& key)
{
	m_layerManager.addLayer(depthLevel, key);
}


void GraphicsEngine::addLayer(unsigned depthLevel,
							  unsigned vertexLayerSize,
							  std::string const& key)
{
	m_layerManager.addLayer(depthLevel, vertexLayerSize, key);
}

void GraphicsEngine::addLayer(unsigned depthLevel,
							  unsigned vertexLayerSize,
							  unsigned differentVertexSize,
							  std::string const& key)
{
	m_layerManager.addLayer(depthLevel, vertexLayerSize, differentVertexSize, key);
}

TextureID GraphicsEngine::loadTexture(std::string const& path,
									  std::string const& key)
{
	return m_textureManager.loadTexture(path, key);
}

TextureID GraphicsEngine::loadTexture(std::string const& path,
                                      std::string const& key,
                                      sf::IntRect const& rect)
{
    return m_textureManager.loadTexture(path, key, rect);
}

void GraphicsEngine::clear()
{
    m_window->clear();
    m_layerManager.prepare();
}

void GraphicsEngine::draw(RenderComponent & renderComponent)
{
    m_layerManager.addVertices(renderComponent.m_displayPackage, renderComponent.m_vertexArray);
}

void GraphicsEngine::display()
{
    m_drawer.draw(m_layerManager, m_textureManager, *m_window);
    m_window->display();
}

void GraphicsEngine::setDefaultLayerSizes(unsigned vertexSize,
										  unsigned differentPrimitiveSize)
{
	m_layerManager.setDefaultVertexLayerSize(vertexSize);
	m_layerManager.setDefaultDifferentVertexSize(differentPrimitiveSize);
}

void GraphicsEngine::setWindowPtr(sf::RenderWindow * ptr_window)
{
    m_window = ptr_window;
}

sf::RenderWindow const* GraphicsEngine::getWindowPtr() const
{
    return m_window;
}