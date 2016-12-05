#include "Engine.hpp"

void main()
{
	dae::Engine engine;

	engine.init();

	engine.createWindow();

	while (engine.windowIsOpen())
	{
		engine.handleDebugInput();
		engine.prepare();
		engine.display();
	}
}