#pragma once

#ifndef DEF_ROTATION_HPP
#define DEF_ROTATION_HPP

#include "Config.hpp"
#include <SFML/Graphics.hpp>
#include "Utils/Transform/TransformArguments.hpp"

namespace dae
{
	namespace utils
	{

		/*!
		* \class Rotation
		* \brief
		*
		*/
		class ENGINE_API Rotation
		{
		public:
			/*!
			* \brief
			*/
			Rotation();

			Rotation(float angle);

			/*!
			* \brief
			*/
			virtual ~Rotation();

			void reset();

			sf::Transform getMatrix(float factor = 1.0f) const;
			void combineArguments(TransformArguments & arg);

			void rotate(float angle);

			float getAngle() const;

		protected:


		private:
			float m_angle;
		};

	}
}

#endif // DEF_ROTATION_HPP