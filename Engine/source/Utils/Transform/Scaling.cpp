#include "Utils/Transform/Scaling.hpp"

using namespace dae::utils;

Scaling::Scaling()
    : Scaling(1.0f, 1.0f)
{
    // nothing
}

Scaling::Scaling(float scale_x, float scale_y)
        : m_scale(scale_x, scale_y)
{
    // nothing
}

Scaling::Scaling(sf::Vector2f const& scale)
        : Scaling(scale.x, scale.y)
{
    // nothing
}

Scaling::~Scaling()
{
    // nothing
}

sf::Transform Scaling::getMatrix(float factor) const
{
    sf::Transform matrix;
    matrix.scale(m_scale.x * factor, m_scale.y * factor);

    return matrix;
}

void Scaling::combineArguments(TransformArguments & arg)
{
    arg.scale.x *= m_scale.x;
    arg.scale.y *= m_scale.y;
}

void Scaling::scale(float scale_x, float scale_y)
{
    scale(sf::Vector2f(scale_x, scale_y));
}

void Scaling::scale(sf::Vector2f const& scale)
{
    m_scale.x = scale.x;
    m_scale.y = scale.y;
}

sf::Vector2f const& Scaling::getScale() const
{
    return m_scale;
}

void Scaling::reset()
{
    m_scale.x = 1.0f;
    m_scale.y = 1.0f;
}
