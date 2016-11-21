#pragma once

#ifndef DEF_SCALING_HPP
#define DEF_SCALING_HPP

#include "Config.hpp"
#include <SFML/Graphics.hpp>
#include "Utils/Transform/TransformArguments.hpp"


namespace dae
{
	namespace utils
	{
		/*!
		* \class Scaling
		* \brief
		*
		*/
		class ENGINE_API Scaling
		{
		public:
			/*!
			* \brief
			*/
			Scaling();

			Scaling(float scale_x, float scale_y);

			Scaling(sf::Vector2f const& scale);

			/*!
			* \brief
			*/
			virtual ~Scaling();

			void reset();

			sf::Transform getMatrix(float factor = 1.0f) const;
			void combineArguments(TransformArguments & arg);

			void scale(float scale_x, float scale_y);
			void scale(sf::Vector2f const& scale);

			sf::Vector2f const& getScale() const;

		protected:


		private:
			sf::Vector2f m_scale;
		};
	}
}


#endif // DEF_SCALING_HPP