#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Graphics/GraphicsEngine.hpp"
#include "Utils/DEBUG_View/DEBUG_View.hpp"
#include "Utils/DEBUG_View/DEBUG_String.hpp"
#include "Utils/DEBUG_View/DEBUG_Line.hpp"

#define DEBUG_WINDOW_SIZE_X 300
#define DEBUG_WINDOW_SIZE_Y 800

namespace dae
{
	namespace graphics
	{
		class ENGINE_API DEBUG_GraphicsView : public utils::DEBUG_View
		{
		public:
			DEBUG_GraphicsView(sf::Font const& font);

			~DEBUG_GraphicsView();

			void link(const GraphicsEngine * graphicsEngine);

			void initText();

		private:
			virtual void drawInformations();

			void updateInformations();

			void updateLayersInfos(utils::DEBUG_String const& lastString,
								   utils::DEBUG_String & nextString);

			const GraphicsEngine * m_ptr_graphicsEngine;

			utils::DEBUG_String m_title;
			utils::DEBUG_String m_generalDescription;
			utils::DEBUG_Line m_numberOfLayers;
			utils::DEBUG_Line m_numberOfTextures;

			utils::DEBUG_String m_layersDecription;

			utils::DEBUG_String m_texturesDecription;

			std::vector <utils::DEBUG_Line> m_layersInfos;
		};
	}
}
