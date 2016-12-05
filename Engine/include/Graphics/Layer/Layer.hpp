#pragma once

#ifndef DEF_DISPLAY_LAYER_HPP
#define DEF_DISPLAY_LAYER_HPP

#include <Config.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include "Graphics/Render/VertexArray.hpp"
#include "Graphics/Texture/TextureID.hpp"
#include "Graphics/Layer/MergedDrawArray.hpp"
#include "Graphics/Texture/TextureManager.hpp"

namespace dae
{
    namespace graphics
    {
	    /*!
	     * \class   DisplayLayer
	     * \brief   It's a big array of stuff to draw.
	     *			It has a depthLevel which represents the time
	     *			when this layer will be drawn compared to the
	     *			other layer.
	     */
	    class ENGINE_API Layer
        {

			friend class DEBUG_GraphicsView; // to be able to display internal infos

        public :

		    /**
			 * \brief	Construct a default Layer.
			 *			The depth level default value is 0.
			 */
			Layer();


		    /**
			 * \brief	Construct a Layer with a depthLevel value
			 * \param	depthLevel : the depthLevel value
			 */
			Layer(unsigned depthLevel);


			/*!
			* \brief	Construct the layer and reserve memory.
			* \param	depthLevel : represents the time
			*			when this layer will be drawn compared to the
			*			other layer.
			* \param	vertexCapacity : the number of elements reserved
			*			in the layer
			* \param	mergedDrawCapacity : the size reserved for
			*			the merged draw array. It represents the different 
			*			type of draw we can do.
			*/
			Layer(unsigned depthLevel, 
				  size_t vertexCapacity,
				  size_t mergedDrawCapacity);


			/*!
			* \brief   Create a correct copy of the layer, only for save
			*          usage.
			* \param   displayLayer : the layer to copy
			* \warning IDs are copied, then it safeless to use in  the LayerManager
			*/
			Layer(Layer const& displayLayer);


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
            
        protected :
			// nothing

        private :
            unsigned m_depthLevel;

            VertexArray m_vertexArray;
			MergedDrawArray m_separateVertexArray;
        };
        
    }
}

#endif // DEF_DISPLAY_LAYER_HPP
