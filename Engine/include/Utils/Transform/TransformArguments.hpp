#pragma once

#ifndef DEF_TRANSFORM_ARGUMENTS_HPP
#define DEF_TRANSFORM_ARGUMENTS_HPP

#include "Config.hpp"
#include <SFML/Graphics.hpp>

namespace dae
{
	namespace utils
	{
		/*!
		* \class TransformArguments
		* \brief
		*
		*/
		class ENGINE_API TransformArguments
		{
		public:

			float angle;
			sf::Vector2f position;
			sf::Vector2f scale;

		public:

			TransformArguments();

			TransformArguments(sf::Vector2f const& position, sf::Vector2f const& scale, float angle);

			TransformArguments& operator+=(TransformArguments const& transformArguments);

			// friends defined inside class body are inline and are hidden from non-ADL lookup
			friend TransformArguments operator+(TransformArguments lhs,        // passing lhs by value helps optimize chained a+b+c
				TransformArguments const& rhs) // otherwise, both parameters may be const references
			{
				lhs += rhs; // reuse compound assignment
				return lhs; // return the result by value (uses move constructor)
			}
		};
	}
}


#endif // DEF_TRANSFORM_ARGUMENTS_HPP
