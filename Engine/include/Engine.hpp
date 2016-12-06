#pragma once
#include "Graphics/DEBUG_GraphicsView.hpp"
#include "Graphics/GraphicsEngine.hpp"
#include "Animations/AnimationsEngine.hpp"

namespace dae
{
	typedef void(*callbackEvent)(sf::Event const&);

	class ENGINE_API Engine
	{
	public:
		Engine();

		~Engine();

		void init();

		void createWindow(sf::VideoMode const& videoMode, 
						  std::string const& windowTitle,
						  sf::Uint32 style = sf::Style::Default);

		void handleDebugInput();

		void prepare();

		void display();

		void setCallbackEvent(callbackEvent newCallbackEvent);

		bool windowIsOpen() const;

		graphics::GraphicsEngine* graphics();
		animations::AnimationsEngine* animations();

	private:
		bool checkInitialization() const;

		void handleCallbackEvent(sf::Event const& event); // todo : remove it (bad idea)

		sf::RenderWindow* m_window;

		graphics::GraphicsEngine* m_graphicsEngine;
		graphics::DEBUG_GraphicsView* m_DEBUG_graphics;

		animations::AnimationsEngine* m_animationsEngine;

		callbackEvent m_callbackEvent;
	};
}
