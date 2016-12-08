#pragma once

#ifndef DEF_DISPLAY_LAYER_HPP
#define DEF_DISPLAY_LAYER_HPP

#include <Config.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include "Graphics/Render/VertexArray.hpp"
#include "Graphics/Texture/TextureID.hpp"
#include "Graphics/Layer/MergedDrawArray.hpp"
#include "Graphics/Texture/TextureManager.hpp"
#include "LayerKey.hpp"

namespace dae
{
    namespace graphics
    {
	    /*!
	     * \class   Layer
	     * \brief   It's a big array of stuff to draw.
	     *			It has a depthLevel which represents the time
	     *			when this layer will be drawn compared to the
	     *			other layer.
	     */
	    class ENGINE_API Layer
        {

			friend class DEBUG_GraphicsView; // to be able to display internal infos

        public :

			/*!
			* \brief	Construct the layer and reserve memory.
			* \param	depthLevel : to set the draw order, the smallest will
			*			be drawn in first 
			* \param	vertexCapacity : the number of elements reserved
			*			in the layer
			* \param	mergedDrawCapacity : the size reserved for
			*			the merged draw array. It represents the different 
			*			type of draw we can do.
			*/
			Layer(std::string const& key,
				  unsigned depthLevel, 
				  size_t vertexCapacity,
				  size_t mergedDrawCapacity);


			/*!
			* \brief   Create a correct copy of the layer, only for save
			*          usage, or memory deplacement (like in std::vector)
			* \param   layer : the layer to copy
			* \warning IDs are copied, then it safeless to use in the LayerManager
			*/
			Layer(Layer const& layer);


            /*!
             * \brief   Set the DepthLevel value.
             * \param   depthLevel : the DepthLevel value
             */
            void setDepthLevel(unsigned depthLevel);


            /*!
             * \brief   Copy the vertices of the VertexArray
             *          into the layer and try to merge it with the
             *          precedent draw stored
             * \param   vertexArray : it contains the vertices
             * \param	textureID : the id of the texture
             * \param	primitive : the sf::PrimitiveType need to draw it
             * \param	separateDraw : if this draw has to be alone ie not
             *			trying to merge it
             */
            void addVertices(VertexArray const& vertexArray, 
            				 TextureID const& textureID,
            				 sf::PrimitiveType primitve,
            				 bool separateDraw = false);


            /*!
             * \brief   Remove all the vertices into the layer
             */
            void clear();


            /*!
             * \return return the DepthLevel
             */
            unsigned getDepthLevel() const;


		    /**
			 * \brief Draw all the vertices on the RenderTarger.
			 * \param renderTarget : the target of the draw
			 * \param textureManager : where we find the texture
			 * \param renderState : classical state for the draw
			 *		  (see SFML doc for more details)
			 */
			void draw(sf::RenderTarget & renderTarget,
					  TextureManager const& textureManager,
					  sf::RenderStates renderState = sf::RenderStates::Default);

        private :
			// we need to store it to be able to retreive it
        	// and display it in the DEBUG_View
			LayerKey m_key;

            unsigned m_depthLevel;

            VertexArray m_vertexArray;
			MergedDrawArray m_mergedDrawArray;
        };
        
    }
}

#endif // DEF_DISPLAY_LAYER_HPP
