#include "Utils/Transform/TransformArguments.hpp"

using namespace dae::utils;

TransformArguments::TransformArguments()
    : position(0.0f, 0.0f),
      scale(1.0f, 1.0f),
      angle(0.0f)
{
    // nothing
}

TransformArguments::TransformArguments(sf::Vector2f const& position,
                                       sf::Vector2f const& scale,
                                       float angle)
    : position(position),
      scale(scale),
      angle(angle)
{
    // nothing
}

TransformArguments& TransformArguments::operator+=(TransformArguments const& transformArguments)
{
    angle += transformArguments.angle;
    position += transformArguments.position;
    scale += transformArguments.scale;

    return *this; // return the result by reference
}