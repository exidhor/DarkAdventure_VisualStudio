#include "Engine.hpp"

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

// initialization of the RenderComponents
void constructTriangles(std::vector<dae::graphics::RenderComponent> & components);
void constructRectangles(std::vector<dae::graphics::RenderComponent> & components);

void setColorToTriangles(std::vector<dae::graphics::RenderComponent> & components);
void setColorToRectangles(std::vector<dae::graphics::RenderComponent> & components);

void setLayersToComponents(std::vector<dae::graphics::RenderComponent> & components);

// handle the input
void handleUserInput(sf::Event const& event);

// global variables
std::vector<dae::graphics::RenderComponent> components;
dae::Engine engine;

void main()
{
	// initialization of the Graphics Engine
	engine.init();

	engine.createWindow(sf::VideoMode(1200, 1000), "Test Engine");

	engine.graphics()->setDefaultLayerSizes(DEFAULT_VERTEX_LAYER_SIZE,
											DEFAULT_DIFFERENT_PRIMITIVE_SIZE);

	engine.graphics()->addLayer(FIRST_LAYER_LEVEL, FIRST_LAYER_KEY);
	engine.graphics()->addLayer(SECOND_LAYER_LEVEL, SECOND_LAYER_KEY);
	engine.graphics()->addLayer(LAST_LAYER_LEVEL, LAST_LAYER_KEY);

	engine.graphics()->loadTexture(TEXTURE_PATH, TEXTURE_KEY);
	
	engine.setCallbackEvent(&handleUserInput);

	// initialization of the RenderComponents
	constructTriangles(components);
	constructRectangles(components);

	//setColorToTriangles(components);
	//setColorToRectangles(components);

	setLayersToComponents(components);

	while (engine.windowIsOpen())
	{
		engine.handleDebugInput();
		engine.prepare();

		for (int i = 0; i < NUMBER_COMPONENTS; i++)
		{
			engine.graphics()->draw(components[i]);
		}

		engine.display();
	}
}

void constructTriangles(std::vector<dae::graphics::RenderComponent> & components)
{
	std::vector<dae::utils::Vec2f> vertexPosition;

	vertexPosition.push_back(dae::utils::Vec2f(151, 40));
	vertexPosition.push_back(dae::utils::Vec2f(125, 81));
	vertexPosition.push_back(dae::utils::Vec2f(175, 79));

	components.push_back(dae::graphics::RenderComponent(vertexPosition, sf::Triangles));

	vertexPosition.clear();

	vertexPosition.push_back(dae::utils::Vec2f(35, 330));
	vertexPosition.push_back(dae::utils::Vec2f(178, 318));
	vertexPosition.push_back(dae::utils::Vec2f(154, 455));

	components.push_back(dae::graphics::RenderComponent(vertexPosition, sf::Triangles));

	vertexPosition.clear();

	vertexPosition.push_back(dae::utils::Vec2f(687, 77));
	vertexPosition.push_back(dae::utils::Vec2f(801, 94));
	vertexPosition.push_back(dae::utils::Vec2f(661, 191));

	components.push_back(dae::graphics::RenderComponent(vertexPosition, sf::Triangles));

	vertexPosition.clear();

	vertexPosition.push_back(dae::utils::Vec2f(812, 271));
	vertexPosition.push_back(dae::utils::Vec2f(863, 393));
	vertexPosition.push_back(dae::utils::Vec2f(756, 393));

	components.push_back(dae::graphics::RenderComponent(vertexPosition, sf::Triangles));

	vertexPosition.clear();

	vertexPosition.push_back(dae::utils::Vec2f(676, 593));
	vertexPosition.push_back(dae::utils::Vec2f(828, 692));
	vertexPosition.push_back(dae::utils::Vec2f(524, 693));

	components.push_back(dae::graphics::RenderComponent(vertexPosition, sf::Triangles));
}

void constructRectangles(std::vector<dae::graphics::RenderComponent> & components)
{
	std::vector<dae::utils::Vec2f> vertexPosition;

	vertexPosition.push_back(dae::utils::Vec2f(111, 184));
	vertexPosition.push_back(dae::utils::Vec2f(262, 184));
	vertexPosition.push_back(dae::utils::Vec2f(262, 405));
	vertexPosition.push_back(dae::utils::Vec2f(111, 405));

	components.push_back(dae::graphics::RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(dae::utils::Vec2f(189, 153));
	vertexPosition.push_back(dae::utils::Vec2f(442, 153));
	vertexPosition.push_back(dae::utils::Vec2f(442, 277));
	vertexPosition.push_back(dae::utils::Vec2f(189, 277));

	components.push_back(dae::graphics::RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(dae::utils::Vec2f(503, 564));
	vertexPosition.push_back(dae::utils::Vec2f(648, 564));
	vertexPosition.push_back(dae::utils::Vec2f(648, 737));
	vertexPosition.push_back(dae::utils::Vec2f(503, 737));

	components.push_back(dae::graphics::RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(dae::utils::Vec2f(612, 116));
	vertexPosition.push_back(dae::utils::Vec2f(736, 116));
	vertexPosition.push_back(dae::utils::Vec2f(736, 275));
	vertexPosition.push_back(dae::utils::Vec2f(612, 275));

	components.push_back(dae::graphics::RenderComponent(vertexPosition, sf::Quads));

	vertexPosition.clear();

	vertexPosition.push_back(dae::utils::Vec2f(716, 324));
	vertexPosition.push_back(dae::utils::Vec2f(847, 324));
	vertexPosition.push_back(dae::utils::Vec2f(847, 493));
	vertexPosition.push_back(dae::utils::Vec2f(716, 493));

	components.push_back(dae::graphics::RenderComponent(vertexPosition, sf::Quads));
}

void setColorToTriangles(std::vector<dae::graphics::RenderComponent> & components)
{
	for (int i = 0; i < NUMBER_TRIANGLE; i++)
	{
		components[i].setColor(sf::Color::Blue);
	}
}

void setColorToRectangles(std::vector<dae::graphics::RenderComponent> & components)
{
	for (int i = NUMBER_TRIANGLE; i < NUMBER_TRIANGLE + NUMBER_RECTANGLE; i++)
	{
		components[i].setColor(sf::Color::Yellow);
	}
}

void setLayersToComponents(std::vector<dae::graphics::RenderComponent> & components)
{
	for (int i = 0; i < NUMBER_COMPONENTS; i++)
	{
		int res = rand() % 3;

		switch (res)
		{
		case 0:
			components[i].setLayer(FIRST_LAYER_KEY);
			components[i].setColor(sf::Color::Yellow);
			break;

		case 1:
			components[i].setLayer(SECOND_LAYER_KEY);
			components[i].setColor(sf::Color::Blue);
			break;

		case 2:
			components[i].setLayer(LAST_LAYER_KEY);
			components[i].setColor(sf::Color::Red);
			break;
		}
	}
}

void handleUserInput(sf::Event const& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			std::cout << "Space" << std::endl;
			setLayersToComponents(components);
			unsigned random = rand();
			engine.graphics()->addLayer(random, std::to_string(random));
		}
	}
}