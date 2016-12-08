#include "Graphics/Render/DisplayPackage.hpp"

using namespace dae::graphics;

DisplayPackage::DisplayPackage()
    : m_textureID(0),
	  m_layerKey(""),
	  m_separateDraw(false),
      m_lastLayerID(0),
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


void DisplayPackage::setLayerID(LayerID id)
{
    m_lastLayerID = id;
    m_lastID_upToDate = true;
}


void DisplayPackage::setLayer(LayerKey const& key)
{
	m_lastID_upToDate = false;
	m_layerKey = key;
}

void DisplayPackage::setPrimitive(sf::PrimitiveType primitiveType)
{
	m_lastID_upToDate = false;
	m_primitive = primitiveType;
}

void DisplayPackage::setSeparateDraw(bool isSeparateDraw)
{
	m_separateDraw = isSeparateDraw;
}

LayerID DisplayPackage::getLayerID() const
{
    return m_lastLayerID;
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
	return m_primitive;
}

bool DisplayPackage::displayIdIsUpToDate() const
{
    return m_lastID_upToDate;
}

bool DisplayPackage::isSeparateDraw() const
{
	return m_separateDraw;
}