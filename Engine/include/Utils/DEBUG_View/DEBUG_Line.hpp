#pragma once
#include <vector>
#include "Utils/DEBUG_View/DEBUG_String.hpp"

#define DEBUG_COEF_SPACE 1

namespace dae
{
	namespace utils
	{
		class DEBUG_Line
		{
		public :
			DEBUG_Line();

			void setLabel(std::string const& label);

			void setFont(sf::Font const& font);

			void setInfo1(std::string const& info);

			void setInfo2(std::string const& info);

			void setInfo3(std::string const& info);

			void draw(sf::RenderTarget & renderTarget);

			void setPosition(sf::Vector2f const& position);

			void setPositionNextTo(DEBUG_String const& string);

			void setPositionNextTo(DEBUG_Line const& line);

			DEBUG_String const& getLabel() const;

		private :
			void computeOffset();

			DEBUG_String m_label ;

			DEBUG_String m_info_1;
			DEBUG_String m_info_2;
			DEBUG_String m_info_3;
		};
	}
}