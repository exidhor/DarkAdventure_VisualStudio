#include "Utils/DEBUG_View/DEBUG_String.hpp"
#include "Utils/DEBUG_View/DEBUG_Line.hpp"

using namespace dae::utils;

DEBUG_String::DEBUG_String()
{
	// nothing
}

void DEBUG_String::setPositionNextTo(DEBUG_String const& string)
{
	setPosition(sf::Vector2f(string.getGlobalBounds().left,
				string.getGlobalBounds().top + string.getGlobalBounds().height)
				+ sf::Vector2f(0, string.getCharacterSize() * COEF_SPACE));
}

void DEBUG_String::setPositionNextTo(DEBUG_Line const& line)
{
	setPositionNextTo(line.getLabel());
}

void DEBUG_String::setInfoType(DEBUG_InfoType type)
{
	m_type = type;

	switch (m_type)
	{
	case TITLE:
		setCharacterSize(DEBUG_TITLE_SIZE);
		setFillColor(DEBUG_TITLE_COLOR);
		setStyle(DEBUG_TITLE_STYLE);
		break;

	case LITTLE_TITLE:
		setCharacterSize(DEBUG_LITTLE_TITLE_SIZE);
		setFillColor(DEBUG_LITTLE_TITLE_COLOR);
		setStyle(DEBUG_LITTLE_TITLE_STYLE);
		break;

	case LABEL:
		setCharacterSize(DEBUG_LABEL_SIZE);
		setFillColor(DEBUG_LABEL_COLOR);
		setStyle(DEBUG_LABEL_STYLE);
		break;

	case INFO_1:
		setCharacterSize(DEBUG_INFO_1_SIZE);
		setFillColor(DEBUG_INFO_1_COLOR);
		setStyle(DEBUG_INFO_1_STYLE);
		break;

	case INFO_2:
		setCharacterSize(DEBUG_INFO_2_SIZE);
		setFillColor(DEBUG_INFO_2_COLOR);
		setStyle(DEBUG_INFO_2_STYLE);
		break;
	}
}

void DEBUG_String::draw(sf::RenderTarget & renderTarget)
{
	renderTarget.draw(*this);
}

DEBUG_InfoType DEBUG_String::getType() const
{
	return m_type;
}