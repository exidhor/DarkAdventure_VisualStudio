#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Graphics/GraphicsEngine.hpp"

#define DEBUG_WINDOW_SIZE_X 300
#define DEBUG_WINDOW_SIZE_Y 800

namespace dae
{
	namespace utils
	{
		class ENGINE_API DEBUG_View
		{
		public:
			DEBUG_View(sf::Font const& font);

			~DEBUG_View();

			void start();

			void display();

			void close();

			bool isOpen() const;


		protected:
			virtual void drawInformations() = 0;

			sf::RenderWindow m_debugWindow;
			sf::Font const& m_font;
		};
	}
}
