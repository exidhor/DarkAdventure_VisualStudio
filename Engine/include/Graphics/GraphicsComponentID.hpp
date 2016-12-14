#pragma once

#include "Config.hpp"
#include "Utils/Identifier/UintID.hpp"

namespace dae
{
	namespace graphics
	{
		/*!
		* \class TextureID
		* \brief
		*
		*/
		class ENGINE_API GraphicsComponentID : public utils::UintID
		{
		public:

			GraphicsComponentID()
				: UintID()
			{
				// nothing
			}

			explicit GraphicsComponentID(unsigned id)
				: UintID(id)
			{
				// nothing
			}
		};
	}
}