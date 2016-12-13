#include "Graphics/Render/GraphicsComponent.hpp"
#include "Graphics/GraphicsEngine.hpp"  // forward declaration

using namespace dae::graphics;
using namespace dae::utils;
using namespace dae;


GraphicsComponent::GraphicsComponent(std::vector<Vec2f> const& vertexPosition, 
								 sf::PrimitiveType primitiveType)
    : m_vertexArray(vertexPosition)
{
	m_displayPackage.setPrimitive(primitiveType);
}

GraphicsComponent::~GraphicsComponent()
{
    // nothing
}

void GraphicsComponent::setTile(animations::Tile const tile)
{
	m_displayPackage.setTexture(tile.getTextureID());
	m_vertexArray.setTexturePoint(tile.getRect());
}

void GraphicsComponent::setColor(sf::Color const& color)
{
    m_vertexArray.setColor(color);
}

void GraphicsComponent::setLayer(std::string const& key)
{
	m_displayPackage.setLayer(LayerKey(key));
}

void GraphicsComponent::setSeparateDraw(bool isSeparateDraw)
{
	m_displayPackage.setSeparateDraw(isSeparateDraw);
}

void GraphicsComponent::setDisplayPackage(DisplayPackage const& displayPackage)
{
	m_displayPackage = displayPackage;
}

void GraphicsComponent::setVertexArray(VertexArray const& vertexArray)
{
	m_vertexArray.copy(vertexArray);
}

sf::Color const& GraphicsComponent::getColor() const
{
    return m_vertexArray.getColor();
}

LayerKey const& GraphicsComponent::getLayerKey() const
{
	return m_displayPackage.getLayerKey();
}

void GraphicsComponent::draw(GraphicsEngine & graphicsEngine,
                           sf::RenderStates renderStates)
{
    graphicsEngine.draw(*this);
}