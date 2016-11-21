#pragma once

#ifndef DEF_TRANSFORMABLE_HPP
#define DEF_TRANSFORMABLE_HPP

#include "Config.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Utils/Math/Math.hpp"
#include "Utils/Transform/Scaling.hpp"
#include "Utils/Transform/Rotation.hpp"
#include "Utils/Transform/Translation.hpp"
#include "Utils/Transform/TransformArguments.hpp"

namespace dae
{
	namespace utils
	{

		/*!
		* \class Transformable
		* \brief
		*
		*/
		class ENGINE_API Transformable
		{
		public:
			/*!
			* \brief
			*/
			Transformable();

			/*!
			* \brief
			*/
			virtual ~Transformable();

			void reset();

			void clearCache();

			sf::Transform getMatrix(float factor = 1.0f);

			void setPosition(float x, float y);
			void setPosition(sf::Vector2f const& position);

			void move(float offset_x, float offset_y);
			void move(sf::Vector2f const& offset);

			void setOrientation(float angle);
			void rotateOrientation(float angle);

			void rotatePosition(float angle, float center_x, float center_y);
			void rotatePosition(float angle, sf::Vector2f const center);

			void setScale(float scale_x, float scale_y);
			void setScale(sf::Vector2f const& scale);

			void scale(float scale_x, float scale_y);
			void scale(sf::Vector2f const& scale);

			sf::Vector2f const& gePosition();
			sf::Vector2f const& getScale();
			float getOrientation();

		protected:

		private:
			void manageCache(float factor);
			void updateMatrix(float factor);

			void updateArg();

		private:
			bool m_matrixIsUpToDate;

			sf::Vector2f m_originPosition;
			sf::Vector2f m_originOrientation;

			TransformArguments m_arg;                       // arg up to date

															// transform of the current frame
			Translation m_translation;
			Scaling m_scale;
			Rotation m_orientation;

			sf::Transform m_transformMatrix;
		};

	}
}

#endif // DEF_TRANSFORMABLE_HPP
