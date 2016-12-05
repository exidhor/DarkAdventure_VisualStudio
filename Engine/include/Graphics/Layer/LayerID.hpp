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
			
	        /**
			 * \brief	Construct a void LayerID with default value 0
			 */
			LayerID()
				: UintID()
        	{
				// nothing
			}

	        /**
             * \brief	Construct a LayerID
             * \param	id : the ID value 
             */
            LayerID(unsigned id)
				: UintID(id)
            {
				// nothing
            }
        };
        
    }
}

#endif // DEF_LAYER_ID_HPP