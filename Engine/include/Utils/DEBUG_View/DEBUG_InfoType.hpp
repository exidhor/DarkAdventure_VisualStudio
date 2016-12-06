#pragma once
#include <SFML/Graphics.hpp>

#define DEBUG_TITLE_SIZE 20
#define DEBUG_TITLE_COLOR sf::Color::White
#define DEBUG_TITLE_STYLE sf::Text::Bold

#define DEBUG_LITTLE_TITLE_SIZE 15
#define DEBUG_LITTLE_TITLE_COLOR sf::Color::White
#define DEBUG_LITTLE_TITLE_STYLE sf::Text::Bold

#define DEBUG_LABEL_SIZE 13
#define DEBUG_LABEL_COLOR sf::Color(200, 200, 200) // grey
#define DEBUG_LABEL_STYLE sf::Text::Regular

#define DEBUG_INFO_1_SIZE 13
#define DEBUG_INFO_1_COLOR sf::Color::Green
#define DEBUG_INFO_1_STYLE sf::Text::Regular

#define DEBUG_INFO_2_SIZE 13
#define DEBUG_INFO_2_COLOR sf::Color(18, 221, 255) // light blue
#define DEBUG_INFO_2_STYLE sf::Text::Regular

#define DEBUG_INFO_3_SIZE 13
#define DEBUG_INFO_3_COLOR sf::Color(230, 230, 230) // light grey
#define DEBUG_INFO_3_STYLE sf::Text::Italic

namespace dae
{
	namespace utils
	{
		enum
		{
			TITLE,
			LITTLE_TITLE,
			LABEL,
			INFO_1,
			INFO_2,
			INFO_3
		} typedef DEBUG_InfoType;
	}
}