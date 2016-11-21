#include "Utils/Transform/Translation.hpp"

using namespace dae::utils;

Translation::Translation()
    : Translation(0.0f, 0.0f)
{
    // nothing
}

Translation::Translation(float offset_x, float offset_y)
        : m_offset(offset_x, offset_y)
{
    // nothing
}

Translation::Translation(sf::Vector2f const& offset)
        : Translation(offset.x, offset.y)
{
    // nothing
}

Translation::~Translation()
{
    // nothing
}

sf::Transform Translation::getMatrix(float factor) const
{
    sf::Transform matrix;
    matrix.translate(m_offset.x * factor, m_offset.y * factor);

    return matrix;
}

void Translation::combineArguments(TransformArguments & arg)
{
    arg.position += m_offset;
}

void Translation::translate(float offset_x, float offset_y)
{
    m_offset.x += offset_x;
    m_offset.y = offset_y;
}

void Translation::translate(sf::Vector2f const& offset)
{
    translate(offset.x, offset.y);
}

sf::Vector2f const& Translation::getPosition() const
{
    return m_offset;
}

void Translation::reset()
{
    m_offset.x = 0.0f;
    m_offset.y = 0.0f;
}
