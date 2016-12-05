#pragma once
#include "SFML/Graphics.hpp"
#include "Utils/DEBUG_View/DEBUG_InfoType.hpp"

#define COEF_SPACE 0.5

namespace dae
{
	namespace utils
	{
		class DEBUG_Line; // forward declaration

		class DEBUG_String : public sf::Text
		{
		public:
			DEBUG_String();

			void setPositionNextTo(DEBUG_String const& string);
			void setPositionNextTo(DEBUG_Line const& line);

			void setInfoType(DEBUG_InfoType type);

			void draw(sf::RenderTarget & renderTarget);

			DEBUG_InfoType getType() const;

		private:
			DEBUG_InfoType m_type;
		};

	}
}