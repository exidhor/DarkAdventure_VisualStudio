#include "Utils/DEBUG_View/DEBUG_Line.hpp"

using namespace dae::utils;

DEBUG_Line::DEBUG_Line()
{
	m_label.setInfoType(LABEL);
	m_info_1.setInfoType(INFO_1);
	m_info_2.setInfoType(INFO_2);
	m_info_3.setInfoType(INFO_3);

	setPosition(sf::Vector2f(0, 0));
}

void DEBUG_Line::setLabel(std::string const& label)
{
	m_label.setString(label);
}

void DEBUG_Line::setFont(sf::Font const& font)
{
	m_label.setFont(font);
	m_info_1.setFont(font);
	m_info_2.setFont(font);
	m_info_3.setFont(font);
}

void DEBUG_Line::setInfo1(std::string const& info)
{
	m_info_1.setString(info);
}

void DEBUG_Line::setInfo2(std::string const& info)
{
	m_info_2.setString(info);
}

void DEBUG_Line::setInfo3(std::string const& info)
{
	m_info_3.setString(info);
}

void DEBUG_Line::draw(sf::RenderTarget & renderTarget)
{
	computeOffset();

	renderTarget.draw(m_label);
	renderTarget.draw(m_info_1);
	renderTarget.draw(m_info_2);
	renderTarget.draw(m_info_3);
}

void DEBUG_Line::setPosition(sf::Vector2f const& position)
{
	m_label.setPosition(position);
}

void DEBUG_Line::setPositionNextTo(DEBUG_String const& string)
{
	m_label.setPositionNextTo(string);
}

void DEBUG_Line::setPositionNextTo(DEBUG_Line const& line)
{
	setPositionNextTo(line.m_label);
}

DEBUG_String const& DEBUG_Line::getLabel() const
{
	return m_label;
}

void DEBUG_Line::computeOffset()
{
	// space bewteen label and info_1
	sf::Vector2f offset(0, 0);
	sf::FloatRect globalBounds = m_label.getGlobalBounds();
	// this is for letting a little space between the two texts
	offset.x = globalBounds.width + m_label.getCharacterSize() * DEBUG_COEF_SPACE;
	m_info_1.setPosition(m_label.getPosition() + offset);

	// space between info_1 and info_2
	globalBounds = m_info_1.getGlobalBounds();
	offset.x = globalBounds.width + m_label.getCharacterSize() * DEBUG_COEF_SPACE;
	m_info_2.setPosition(m_info_1.getPosition() + offset);

	// space between info_2 and info_3
	globalBounds = m_info_2.getGlobalBounds();
	offset.x = globalBounds.width + m_label.getCharacterSize() * DEBUG_COEF_SPACE;
	m_info_3.setPosition(m_info_2.getPosition() + offset);
}

