#pragma once

#ifndef DEF_LAYER_ID_HPP
#define DEF_LAYER_ID_HPP

#include "Config.hpp"
#include "Utils/Identifier/UintID.hpp"

namespace dae
{
    namespace graphics
    {
        
        /*!
         * \class	LayerID
         * \brief	Small class which represent the layer id.
		 *			It used to ensure that we use right values.
         */
        class ENGINE_API LayerID : public utils::UintID
        {
        public :
			
			LayerID()
				: UintID()
        	{
				// nothing
			}

            LayerID(unsigned id)
				: UintID(id)
            {
				// nothing
            }
        };
        
    }
}

#endif // DEF_LAYER_ID_HPP