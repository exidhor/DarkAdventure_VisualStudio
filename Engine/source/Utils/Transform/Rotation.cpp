#include "Utils/Transform/Rotation.hpp"

using namespace dae::utils;

Rotation::Rotation()
    : Rotation(0.0f)
{
    //nothing
}

Rotation::Rotation(float angle)
        : m_angle(angle)
{
    //nothing
}

Rotation::~Rotation()
{
    //nothing
}

sf::Transform Rotation::getMatrix(float factor) const
{
    sf::Transform matrix;
    matrix.rotate(m_angle * factor);

    return matrix;
}

void Rotation::combineArguments(TransformArguments & arg)
{
    arg.angle += m_angle;
}

void Rotation::rotate(float angle)
{
    m_angle += angle;
}

float Rotation::getAngle() const
{
    return m_angle;
}

void Rotation::reset()
{
    m_angle = 0.0f;
}