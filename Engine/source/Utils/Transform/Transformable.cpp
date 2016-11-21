#include "Utils/Transform/Transformable.hpp"

using namespace dae::utils;

Transformable::Transformable()
    : m_matrixIsUpToDate(false),
      m_arg(),
      m_transformMatrix()

{
    // nothing
}

Transformable::~Transformable()
{
    // nothing
}

void Transformable::reset()
{
    m_arg.position.x = 0.0f;
    m_arg.position.y = 0.0f;

    m_arg.angle = 0.0f;

    m_arg.scale.x = 1.0f;
    m_arg.scale.y = 1.0f;

    clearCache();
}

void Transformable::clearCache()
{
    m_translation.reset();
    m_scale.reset();
    m_orientation.reset();
}

sf::Transform Transformable::getMatrix(float factor)
{
    manageCache(factor);

    return m_transformMatrix;
}

void Transformable::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

void Transformable::setPosition(sf::Vector2f const& position)
{
    m_matrixIsUpToDate = false;

    m_translation.reset();
    m_arg.position = position;
}

void Transformable::move(float offset_x, float offset_y)
{
    m_matrixIsUpToDate = false;

    m_translation.translate(offset_x, offset_y);
}

void Transformable::move(sf::Vector2f const& offset)
{
    move(offset.x, offset.y);
}

void Transformable::setOrientation(float angle)
{
    m_matrixIsUpToDate = false;

    m_orientation.reset();
    m_orientation.rotate(angle);
}

void Transformable::rotateOrientation(float angle)
{
    m_matrixIsUpToDate = false;

    m_orientation.rotate(angle);
}

void Transformable::rotatePosition(float angle, float center_x, float center_y)
{
    m_matrixIsUpToDate = false;

    // computation of the final point with the actual position
    sf::Vector2f movement = Math::rotatePoint(m_arg.position,
                                              sf::Vector2f(center_x, center_y),
                                              angle);

    m_translation.translate(movement);
}

void Transformable::rotatePosition(float angle, sf::Vector2f const center)
{
    rotatePosition(angle, center.x, center.y);
}

void Transformable::setScale(float scale_x, float scale_y)
{
    m_matrixIsUpToDate = false;

    m_scale.reset();
    m_scale.scale(scale_x, scale_y);
}

void Transformable::setScale(sf::Vector2f const& scale)
{
    setScale(scale.x, scale.y);
}

void Transformable::scale(float scale_x, float scale_y)
{
    m_matrixIsUpToDate = false;

    m_scale.scale(scale_x, scale_y);
}

void Transformable::scale(sf::Vector2f const& scaleValue)
{
    scale(scaleValue.x, scaleValue.y);
}

sf::Vector2f const& Transformable::gePosition()
{
    updateArg();

    return m_arg.position;
}

sf::Vector2f const& Transformable::getScale()
{
    updateArg();

    return m_arg.scale;
}

float Transformable::getOrientation()
{
    updateArg();

    return m_arg.angle;
}

void Transformable::manageCache(float factor)
{
    if(!m_matrixIsUpToDate)
    {
        updateMatrix(factor);
    }
}

void Transformable::updateMatrix(float factor)
{
    updateArg();

    float cosine = Math::cosine(-m_arg.angle);
    float sine = Math::sine(-m_arg.angle);

    float csx = cosine * m_arg.scale.x;
    float csy = cosine * m_arg.scale.y;
    float ssx = sine * m_arg.scale.x;
    float ssy = sine * m_arg.scale.y;

    float cTx = csx * m_originOrientation.x;
    float cTy = csy * m_originOrientation.y;
    float sTx = ssx * m_originOrientation.x;
    float sTy = ssy * m_originOrientation.y;

    float tx = -cTx - sTy + m_originOrientation.x
               + m_arg.position.x - m_originPosition.x;
    float ty = sTx - cTy + m_originOrientation.y
               + m_arg.position.y - m_originOrientation.y;

    m_transformMatrix = sf::Transform(csx,  ssy,  tx,
                                      -ssx, csy,  ty,
                                      0.0f, 0.0f, 1.0f);

    m_matrixIsUpToDate = true;
}

void Transformable::updateArg()
{
    m_scale.combineArguments(m_arg);
    m_orientation.combineArguments(m_arg);
    m_translation.combineArguments(m_arg);

    m_scale.reset();
    m_orientation.reset();
    m_translation.reset();
}