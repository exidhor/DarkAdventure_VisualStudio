#include <iostream>
#include <SFML/Graphics.hpp>

#include "Graphics/GraphicsEngine.hpp"
#include "Graphics/Render/RenderComponent.hpp"
#include "Utils/Container/Fatory.hpp"

using namespace dae::graphics;
using namespace dae::utils;

struct predicate
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");



	/*
	dae::graphics::GraphicsEngine graphicsEngine;
	graphicsEngine.init(50);
	graphicsEngine.setWindowPtr(&window);
	graphicsEngine.addLayer(0, 50, 3, "background");
	graphicsEngine.addLayer(1, 50, 3, "front");

	// first triangle
	std::vector <Vec2f> vertexPosition0;

	vertexPosition0.push_back(Vec2f(100, 100));
	vertexPosition0.push_back(Vec2f(200, 100));
	vertexPosition0.push_back(Vec2f(100, 200));

	dae::graphics::RenderComponent renderComponent0(vertexPosition0, sf::PrimitiveType::Triangles);
	renderComponent0.setColor(sf::Color::Green);
	renderComponent0.setLayer("front");

	// second triangle
	std::vector <Vec2f> vertexPosition1;

	vertexPosition1.push_back(Vec2f(100, 100));
	vertexPosition1.push_back(Vec2f(200, 100));
	vertexPosition1.push_back(Vec2f(200, 200));

	dae::graphics::RenderComponent renderComponent1(vertexPosition1, sf::PrimitiveType::Triangles);
	renderComponent1.setColor(sf::Color::Red);
	renderComponent1.setLayer("background");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		graphicsEngine.clear();
		graphicsEngine.draw(renderComponent0);
		graphicsEngine.draw(renderComponent1);
		graphicsEngine.display();
	}

	*/
	return 0;
}
