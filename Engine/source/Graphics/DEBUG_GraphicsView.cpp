#include "Graphics/DEBUG_GraphicsView.hpp"

using namespace dae::graphics;
using namespace dae;

DEBUG_GraphicsView::DEBUG_GraphicsView(sf::Font const& font)
	: utils::DEBUG_View(font),
	m_ptr_graphicsEngine(nullptr)
{
	initText();
}

DEBUG_GraphicsView::~DEBUG_GraphicsView()
{
	// nothing
}

void DEBUG_GraphicsView::link(const GraphicsEngine * graphicsEngine)
{
	m_ptr_graphicsEngine = graphicsEngine;
}

void DEBUG_GraphicsView::initText()
{
	m_title.setFont(m_font);
	m_title.setInfoType(utils::TITLE);
	m_title.setString("DEBUG GRAPHICS VIEW");

	m_generalDescription.setPositionNextTo(m_title);
	m_generalDescription.setFont(m_font);
	m_generalDescription.setInfoType(utils::LITTLE_TITLE);
	m_generalDescription.setString("General Information");

	m_numberOfLayers.setPositionNextTo(m_generalDescription);
	m_numberOfLayers.setFont(m_font);
	m_numberOfLayers.setLabel("Number of Layers : ");

	m_numberOfTextures.setPositionNextTo(m_numberOfLayers);
	m_numberOfTextures.setFont(m_font);
	m_numberOfTextures.setLabel("Number of Textures : ");

	m_layersDecription.setPositionNextTo(m_numberOfTextures);
	m_layersDecription.setFont(m_font);
	m_layersDecription.setInfoType(utils::LITTLE_TITLE);
	m_layersDecription.setString("Layer arrays");

	m_texturesDecription.setPositionNextTo(m_layersDecription);
	m_texturesDecription.setFont(m_font);
	m_texturesDecription.setInfoType(utils::LITTLE_TITLE);
	m_texturesDecription.setString("Texture arrays");
}


void DEBUG_GraphicsView::drawInformations()
{
	updateInformations();

	m_title.draw(m_debugWindow);

	m_generalDescription.draw(m_debugWindow);

	m_numberOfLayers.draw(m_debugWindow);
	m_numberOfTextures.draw(m_debugWindow);

	m_layersDecription.draw(m_debugWindow);

	for(unsigned i = 0; i < m_layersInfos.size(); i++)
	{
		m_layersInfos[i].draw(m_debugWindow);
	}

	m_texturesDecription.draw(m_debugWindow);
}

void DEBUG_GraphicsView::updateInformations()
{
	if (!m_ptr_graphicsEngine)
		return;
	
	// general layer info
	LayerManager const& layerManager = m_ptr_graphicsEngine->m_layerManager;

	m_numberOfLayers.setInfo1(std::to_string(layerManager.size()));
	m_numberOfLayers.setInfo2("(" + std::to_string(layerManager.m_layerFactory.capacity()) + ")");

	// general texture info
	auto const& textureArray = m_ptr_graphicsEngine->m_textureManager.m_textures;

	m_numberOfTextures.setInfo1(std::to_string(textureArray.size()));
	m_numberOfTextures.setInfo2("(" + std::to_string(textureArray.capacity()) + ")");

	// specific layer info
	updateLayersInfos(m_layersDecription, m_texturesDecription);
}

void DEBUG_GraphicsView::updateLayersInfos(utils::DEBUG_String const& lastString,
										   utils::DEBUG_String & nextString)
{
	auto const& layerFactory = m_ptr_graphicsEngine->m_layerManager.m_layerFactory;

	m_layersInfos.resize(layerFactory.size());

	for(unsigned i = 0; i < m_layersInfos.size(); i++)
	{
		if(i == 0)
		{
			m_layersInfos[i].setPositionNextTo(lastString);
		}
		else
		{
			m_layersInfos[i].setPositionNextTo(m_layersInfos[i - 1]);
		}

		m_layersInfos[i].setFont(m_font); // because they can be created at this update
		m_layersInfos[i].setLabel(std::to_string(i) + " : ");
		m_layersInfos[i].setInfo1(std::to_string(layerFactory[i].m_vertexArray.getSize()));
		m_layersInfos[i].setInfo2("(" + std::to_string(layerFactory[i].m_vertexArray.getCapacity()) + ")");
		m_layersInfos[i].setInfo3(layerFactory[i].m_key.getKeyValue());
	}

	nextString.setPositionNextTo(m_layersInfos[m_layersInfos.size() - 1]);
}