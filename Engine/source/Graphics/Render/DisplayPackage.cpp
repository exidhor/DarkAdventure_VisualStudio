#include "Graphics/Render/DisplayPackage.hpp"

using namespace dae::graphics;

DisplayPackage::DisplayPackage()
    : m_textureID(0),
	  m_layerKey(""),
	  m_separateDraw(false),
      m_lastDisplayLayerID(0),
      m_lastID_upToDate(false)
{
    // nothing
}

DisplayPackage::~DisplayPackage()
{
    // nothing
}

void DisplayPackage::setTexture(TextureID id)
{
	m_lastID_upToDate = false;
	m_textureID = id;
}

void DisplayPackage::setLayer(LayerKey const& key)
{
	m_layerKey = key;
}

void DisplayPackage::setPrimitive(sf::PrimitiveType primitiveType)
{
	m_lastID_upToDate = false;
	m_displayPrimitive = primitiveType;
}

void DisplayPackage::setSeparateDraw(bool isSeparateDraw)
{
	m_separateDraw = isSeparateDraw;
}

void DisplayPackage::setDisplayLayerID(LayerID displayLayerID)
{
    m_lastDisplayLayerID = displayLayerID;
    m_lastID_upToDate = true;
}

LayerID DisplayPackage::getDisplayLayerID() const
{
    return m_lastDisplayLayerID;
}

TextureID DisplayPackage::getTextureID() const
{
	return m_textureID;
}

LayerKey const& DisplayPackage::getLayerKey() const
{
	return m_layerKey;
}

sf::PrimitiveType DisplayPackage::getPrimitive() const
{
	return m_displayPrimitive;
}

bool DisplayPackage::displayIdIsUpToDate() const
{
    return m_lastID_upToDate;
}

bool DisplayPackage::isSeparateDraw() const
{
	return m_separateDraw;
}