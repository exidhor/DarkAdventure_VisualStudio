#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.hpp"
#include "Graphics/GraphicsEngine.hpp"
#include "Graphics/Render/RenderComponent.hpp"

// number of layers reserved
#define NUMBER_LAYERS_RESERVED 0
#define DEFAULT_VERTEX_LAYER_SIZE 100
#define DEFAULT_DIFFERENT_PRIMITIVE_SIZE 5

// layer keys
#define FIRST_LAYER_KEY "front"
#define SECOND_LAYER_KEY "middle"
#define LAST_LAYER_KEY "background"

// layer depth level
#define FIRST_LAYER_LEVEL 1
#define SECOND_LAYER_LEVEL 2
#define LAST_LAYER_LEVEL 100

// texture path
#define TEXTURE_PATH "../Res/One.png"
#define TEXTURE_KEY "tile_characters"

// component size
#define NUMBER_TRIANGLE 5
#define NUMBER_RECTANGLE 5 
#define NUMBER_COMPONENTS (NUMBER_TRIANGLE + NUMBER_RECTANGLE)

using namespace dae::graphics;
using namespace dae::utils;

// initialization of the Graphics Engine
void initEngine(GraphicsEngine & graphicEngine, sf::RenderWindow & window);
void addLayers_base(GraphicsEngine & graphicEngine);
void loadTexture(GraphicsEngine & graphicEngine);

// initialization of the RenderComponents
void constructTriangles(std::vector<RenderComponent> & components);
void constructRectangles(std::vector<RenderComponent> & components);
void constructSprites(std::vector<RenderComponent> & components);

void setColorToTriangles(std::vector<RenderComponent> & components);
void setColorToRectangles(std::vector<RenderComponent> & components);

void setLayersToComponents(std::vector<RenderComponent> & components);

// display
void display(GraphicsEngine & graphicEngine, std::vector<RenderComponent> & components);

int main()
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

	return 1;

	sf::RenderWindow window(sf::VideoMode(1200, 1000), "Test Graphic Engine");

	// initialization of the Graphics Engine
	GraphicsEngine graphicEngine;
	initEngine(graphicEngine, window);
	addLayers_base(graphicEngine);
	loadTexture(graphicEngine);

	// initialization of the RenderComponents
	std::vector<RenderComponent> components;
	constructTriangles(components);
	constructRectangles(components);

	setColorToTriangles(components);
	setColorToRectangles(components);

	setLayersToComponents(components);

	// display
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// draw calls in the Graphics Engine
		display(graphicEngine, components);
	}

	return 0;
}

void initEngine(GraphicsEngine & graphicEngine, sf::RenderWindow & window)
{
	// this step is just optimizations (to reserve memory forward)
	graphicEngine.init(NUMBER_LAYERS_RESERVED);

	graphicEngine.setWindowPtr(&window);

	graphicEngine.setDefaultLayerSizes(DEFAULT_VERTEX_LAYER_SIZE,
									   DEFAULT_DIFFERENT_PRIMITIVE_SIZE);
}


void addLayers_base(GraphicsEngine & graphicEngine)
{
	// in case any memory was reserved, this can be a little slow 
	graphicEngine.addLayer(FIRST_LAYER_LEVEL, FIRST_LAYER_KEY);
	graphicEngine.addLayer(SECOND_LAYER_LEVEL, SECOND_LAYER_KEY);
	graphicEngine.addLayer(LAST_LAYER_LEVEL, LAST_LAYER_KEY);
}

void loadTexture(GraphicsEngine & graphicEngine)
{
	graphicEngine.loadTexture(TEXTURE_PATH, TEXTURE_KEY);
}

void constructTriangles(std::vector<RenderComponent> & components)
{
	std::vector<Vec2f> vertexPosition;
	
	vertexPosition.push_back(Vec2f(151, 40));
	vertexPosition.push_back(Vec2f(125, 81));
	vertexPosition.push_back(Vec2f(175, 79));

	components.push_back(RenderComponent(vertexPosition, sf::Triangles));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(35, 330));
	vertexPosition.push_back(Vec2f(178, 318));
	vertexPosition.push_back(Vec2f(154, 455));

	components.push_back(RenderComponent(vertexPosition, sf::Triangles));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(687, 77));
	vertexPosition.push_back(Vec2f(801, 94));
	vertexPosition.push_back(Vec2f(661, 191));

	components.push_back(RenderComponent(vertexPosition, sf::Triangles));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(812, 271));
	vertexPosition.push_back(Vec2f(863, 393));
	vertexPosition.push_back(Vec2f(756, 393));

	components.push_back(RenderComponent(vertexPosition, sf::Triangles));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(676, 593));
	vertexPosition.push_back(Vec2f(828, 692));
	vertexPosition.push_back(Vec2f(524, 693));

	components.push_back(RenderComponent(vertexPosition, sf::Triangles));
}

void constructRectangles(std::vector<RenderComponent> & components)
{
	std::vector<Vec2f> vertexPosition;

	vertexPosition.push_back(Vec2f(111, 184));
	vertexPosition.push_back(Vec2f(262, 184));
	vertexPosition.push_back(Vec2f(262, 405));
	vertexPosition.push_back(Vec2f(111, 405));

	components.push_back(RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(189, 153));
	vertexPosition.push_back(Vec2f(442, 153));
	vertexPosition.push_back(Vec2f(442, 277));
	vertexPosition.push_back(Vec2f(189, 277));

	components.push_back(RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(503, 564));
	vertexPosition.push_back(Vec2f(648, 564));
	vertexPosition.push_back(Vec2f(648, 737));
	vertexPosition.push_back(Vec2f(503, 737));

	components.push_back(RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(612, 116));
	vertexPosition.push_back(Vec2f(736, 116));
	vertexPosition.push_back(Vec2f(736, 275));
	vertexPosition.push_back(Vec2f(612, 275));

	components.push_back(RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(716, 324));
	vertexPosition.push_back(Vec2f(847, 324));
	vertexPosition.push_back(Vec2f(847, 493));
	vertexPosition.push_back(Vec2f(716, 493));

	components.push_back(RenderComponent(vertexPosition, sf::Quads));
}

/*
void constructSprites(std::vector<RenderComponent> & components)
{
	std::vector<Vec2f> vertexPosition;

	vertexPosition.push_back(Vec2f(104, 27));
	vertexPosition.push_back(Vec2f(204, 27));
	vertexPosition.push_back(Vec2f(204, 131));
	vertexPosition.push_back(Vec2f(104, 131));

	components.push_back(RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(231, 338));
	vertexPosition.push_back(Vec2f(326, 338));
	vertexPosition.push_back(Vec2f(326, 481));
	vertexPosition.push_back(Vec2f(231, 481));

	components.push_back(RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(436, 512));
	vertexPosition.push_back(Vec2f(538, 512));
	vertexPosition.push_back(Vec2f(538, 652));
	vertexPosition.push_back(Vec2f(436, 652));

	components.push_back(RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(564, 78));
	vertexPosition.push_back(Vec2f(644, 78));
	vertexPosition.push_back(Vec2f(644, 200));
	vertexPosition.push_back(Vec2f(564, 200));

	components.push_back(RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(Vec2f(749, 352));
	vertexPosition.push_back(Vec2f(825, 352));
	vertexPosition.push_back(Vec2f(825, 459));
	vertexPosition.push_back(Vec2f(749, 459));

	components.push_back(RenderComponent(vertexPosition, sf::Quads));
}*/

void setColorToTriangles(std::vector<RenderComponent> & components)
{
	for(int i = 0; i < NUMBER_TRIANGLE; i++)
	{
		components[i].setColor(sf::Color::Blue);
	}
}

void setColorToRectangles(std::vector<RenderComponent> & components)
{
	for(int i = NUMBER_TRIANGLE; i < NUMBER_TRIANGLE + NUMBER_RECTANGLE; i++)
	{
		components[i].setColor(sf::Color::Yellow);
	}
}

void setLayersToComponents(std::vector<RenderComponent> & components)
{
	for(int i = 0; i < NUMBER_COMPONENTS; i++)
	{
		int res = i % 3;

		switch(res)
		{
		case 0 :
			components[i].setLayer(FIRST_LAYER_KEY);
			components[i].setColor(sf::Color::Yellow);
			break;

		case 1 :
			components[i].setLayer(SECOND_LAYER_KEY);
			components[i].setColor(sf::Color::Blue);
			break;

		case 2 :
			components[i].setLayer(LAST_LAYER_KEY);
			components[i].setColor(sf::Color::Red);
			break;
		}
	}
}

void display(GraphicsEngine & graphicEngine, std::vector<RenderComponent> & components)
{
	graphicEngine.clear();

	for(int i = 0; i < NUMBER_COMPONENTS; i++)
	{
		graphicEngine.draw(components[i]);
	}

	graphicEngine.display();
}