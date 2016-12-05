#include "Utils/DEBUG_View/DEBUG_View.hpp"

using namespace dae::utils;

DEBUG_View::DEBUG_View(sf::Font const& font)
	: m_debugWindow(),
	m_font(font)
{
	// nothing
}

DEBUG_View::~DEBUG_View()
{
	// nothing
}

void DEBUG_View::start()
{
	if (!m_debugWindow.isOpen())
	{
		std::cout << "START THE DEBUG VIEW" << std::endl;
		m_debugWindow.create(sf::VideoMode(DEBUG_WINDOW_SIZE_X, DEBUG_WINDOW_SIZE_Y),
							 "DEBUG VIEW");
	}
}

void DEBUG_View::close()
{
	if (m_debugWindow.isOpen())
	{
		std::cout << "CLOSE THE DEBUG VIEW" << std::endl;
		m_debugWindow.close();
	}
}

void DEBUG_View::display()
{
	if (m_debugWindow.isOpen())
	{
		sf::Event event;
		while (m_debugWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_debugWindow.close();
		}

		m_debugWindow.clear();

		drawInformations();

		m_debugWindow.display();
	}
}

bool DEBUG_View::isOpen() const
{
	return m_debugWindow.isOpen();
}