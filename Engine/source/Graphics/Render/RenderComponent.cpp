#include "Graphics/Render/RenderComponent.hpp"
#include "Graphics/GraphicsEngine.hpp"  // forward declaration

using namespace dae::graphics;
using namespace dae::utils;
using namespace dae;

RenderComponent::RenderComponent(std::vector<Vec2f> const& vertexPosition, 
								 sf::PrimitiveType primitiveType)
    : m_vertexArray(vertexPosition)
{
	m_displayPackage.setPrimitive(primitiveType);
}

RenderComponent::~RenderComponent()
{
    // nothing
}

void RenderComponent::setTile(animations::Tile const tile)
{
	m_displayPackage.setTexture(tile.getTextureID());
	m_vertexArray.setTexturePoint(tile.getRect());
}

void RenderComponent::setColor(sf::Color const& color)
{
    m_vertexArray.setColor(color);
}

void RenderComponent::setLayer(std::string const& key)
{
	m_displayPackage.setLayer(LayerKey(key));
}

void RenderComponent::setSeparateDraw(bool isSeparateDraw)
{
	m_displayPackage.setSeparateDraw(isSeparateDraw);
}

void RenderComponent::setDisplayPackage(DisplayPackage const& displayPackage)
{
	m_displayPackage = displayPackage;
}

void RenderComponent::setVertexArray(VertexArray const& vertexArray)
{
	m_vertexArray.copy(vertexArray);
}

sf::Color const& RenderComponent::getColor() const
{
    return m_vertexArray.getColor();
}

LayerKey const& RenderComponent::getLayerKey() const
{
	return m_displayPackage.getLayerKey();
}

void RenderComponent::draw(GraphicsEngine & graphicsEngine,
                           sf::RenderStates renderStates)
{
    graphicsEngine.draw(*this);
}