#pragma once

#ifndef DEF_TRANSLATION_HPP
#define DEF_TRANSLATION_HPP

#include "Config.hpp"
#include <SFML/Graphics.hpp>
#include "Utils/Transform/TransformArguments.hpp"

namespace dae
{
	namespace utils
	{

		/*!
		* \class Translation
		* \brief
		*
		*/
		class Translation
		{
		public:
			/*!
			* \brief
			*/
			Translation();

			Translation(float offset_x, float offset_y);

			Translation(sf::Vector2f const& offset);

			/*!
			* \brief
			*/
			virtual ~Translation();

			void reset();

			sf::Transform getMatrix(float factor = 1.0f) const;
			void combineArguments(TransformArguments & arg);

			void translate(float offset_x, float offset_y);
			void translate(sf::Vector2f const& offset);

			sf::Vector2f const& getPosition() const;

		protected:


		private:
			sf::Vector2f m_offset;
		};

	}
}

#endif // DEF_TRANSLATION_HPP
