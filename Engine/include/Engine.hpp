#pragma once
#include "Graphics/DEBUG_GraphicsView.hpp"
#include "Graphics/GraphicsEngine.hpp"
#include "Animations/AnimationsEngine.hpp"

namespace dae
{
	class ENGINE_API Engine
	{
	public:
		Engine();

		~Engine();

		void init();

		void createWindow();

		void handleDebugInput();

		void prepare();

		void display();

		bool windowIsOpen() const;

	private:
		bool checkInitialization() const;

		sf::RenderWindow* m_window;

		graphics::GraphicsEngine* m_graphicsEngine;
		graphics::DEBUG_GraphicsView* m_DEBUG_graphics;

		animations::AnimationsEngine* m_animationsEngine;
	};
}
