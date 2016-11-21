#pragma once

#ifndef DEF_MATH_HPP
#define DEF_MATH_HPP

#include "Config.hpp"
#include <cstdint>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Utils/Container/Vec2.hpp"

#define PI 3.14159265

namespace dae
{
	namespace utils
	{

		/*!
		* \class Math
		* \brief
		*
		*/
		namespace Math {
			template<typename T>
			sf::Vector2<T> ENGINE_API abs(sf::Vector2<T> const &vector);

			sf::Vector2f ENGINE_API rotatePoint(sf::Vector2f const& point,
				sf::Vector2f const& centerOfRotation,
				float angleInDegree);

			float ENGINE_API cosine(float angle);

			float ENGINE_API sine(float angle);
		};

		template<typename T>
		sf::Vector2<T> Math::abs(sf::Vector2<T> const &vector) {
			return sf::Vector2<T>(std::abs(vector.x), std::abs(vector.y));
		}

		// source : http://stackoverflow.com/questions/3837266/finding-the-points-of-a-triangle-after-rotation
		sf::Vector2f  Math::rotatePoint(sf::Vector2f const& point,
			sf::Vector2f const& centerOfRotation,
			float angleInDegree)
		{
			sf::Vector2f resultRotation;

			float offset_x = point.x - centerOfRotation.x;
			float offset_y = point.y - centerOfRotation.y;

			// "rotating a point A around point B by C degrees".

			// A.x' = (A.x-B.x) * cos(C) - (A.y-B.y) * sin(C) + B.x
			resultRotation.x = (float)(offset_x * cos(angleInDegree) - offset_y * sin(angleInDegree)
				+ centerOfRotation.x);

			// A.y' = (A.y-B.y) * cos(C) + (A.x-B.x) * sin(C) + B.y
			resultRotation.y = (float)(offset_y * cos(angleInDegree) + offset_x * sin(angleInDegree)
				+ centerOfRotation.y);

			return resultRotation;
		}

		float Math::cosine(float angle)
		{
			return (float)cos(angle * PI / 180);
		}

		float Math::sine(float angle)
		{
			return (float)sin(angle * PI / 180);
		}

	};
}

#endif // DEF_MATH_HPP
