#include "Engine.hpp"

using namespace dae;


Engine::Engine()
	: m_window(nullptr), 
	m_graphicsEngine(nullptr),
	m_DEBUG_graphics(nullptr),
	m_animationsEngine(nullptr)
{
	// nothing
}

Engine::~Engine()
{
	if(m_window)
	{
		if (m_window->isOpen())
			m_window->close();

		delete m_window;
	}

	if (m_graphicsEngine)
		delete m_graphicsEngine;

	if (m_DEBUG_graphics)
		delete m_DEBUG_graphics;

	if (m_animationsEngine)
		delete m_animationsEngine;
}

void Engine::init()
{
	m_window = new sf::RenderWindow();

	m_graphicsEngine = new graphics::GraphicsEngine();
	m_graphicsEngine->setWindowPtr(m_window);
	m_graphicsEngine->addLayer(1, 10, 2, "front");
	m_graphicsEngine->addLayer(10, 64, 3, "back");
	m_graphicsEngine->addLayer(5, 100, 4, "character");

	// todo : remove this and do a FontManager instead
	sf::Font* font = new sf::Font();	
	font->loadFromFile("../Res/cour.ttf");
	m_DEBUG_graphics = new graphics::DEBUG_GraphicsView(*font);
	m_DEBUG_graphics->link(m_graphicsEngine);

	m_animationsEngine = new animations::AnimationsEngine();
}

void Engine::createWindow()
{
	// todo : allow the user to create his custom window
	m_window->create(sf::VideoMode(1000, 600),
					 "DarkAdventure");
}

void Engine::handleDebugInput()
{
	if (!checkInitialization())
		return;

	sf::Event event;

	while(m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window->close();

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::F1)
			{
				m_DEBUG_graphics->start();
			}
		}
	}
}

void Engine::prepare()
{
	if (!checkInitialization())
		return;

	m_graphicsEngine->clear();
}

void Engine::display()
{
	if (!checkInitialization())
		return;

	m_graphicsEngine->display();

	m_DEBUG_graphics->display();
}

bool Engine::windowIsOpen() const
{
	if (!checkInitialization())
		return false;

	return m_window->isOpen()
		|| m_DEBUG_graphics->isOpen();
}

bool Engine::checkInitialization() const
{
	if (!m_graphicsEngine) // this means that no engine were created
	{
		std::cerr << "The Engine need to be initialized before used." << std::endl;
		std::cerr << "You need to call the function Init" << std::endl;

		return false;
	}

	return true;
}