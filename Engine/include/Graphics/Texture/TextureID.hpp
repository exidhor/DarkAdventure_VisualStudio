#pragma once

#ifndef DEF_TEXTURE_ID_HPP
#define DEF_TEXTURE_ID_HPP

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
        class ENGINE_API TextureID : public utils::UintID
        {
            friend class DisplayKey;

        public :

			TextureID()
				: UintID()
        	{
				// nothing
			}

            explicit TextureID(unsigned id)
				: UintID(id)
            {
				// nothing
            }
        };
    }
}

#endif // DEF_TEXTURE_ID_HPP
