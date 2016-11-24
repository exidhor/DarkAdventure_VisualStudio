#pragma once

#ifndef DEF_DISPLAY_LAYER_HPP
#define DEF_DISPLAY_LAYER_HPP

#include <Config.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include "Graphics/Render/VertexArray.hpp"
#include "Graphics/Texture/TextureID.hpp"
#include "Graphics/Layer/LayerID.hpp"
#include "Graphics/Layer/LayerKey.hpp"
#include "Graphics/Layer/SeparateVertexArray.hpp"
#include "Graphics/Texture/TextureManager.hpp"

namespace dae
{
    namespace graphics
    {
	    /*!
	     * \class   DisplayLayer
	     * \brief   Regroup the vertices from the same display
	     *          information into an array to draw it once
	     */
	    class ENGINE_API Layer
        {

        public :

			Layer();

			/*!
			* \brief   Construct the layer with default values
			* \param   id : the id of the layer
			* \param   vertexNumberMax : the number of elements reserved
			*          in the layer
			* \param	differentVertexNumberMax : the size reserved for
			*			the separate vertex array
			* \warning the texture is set to 0 (no texture) by default
			* \warning the primitive is not set
			* \warning the depth level is set to 0 by default
			*/
			Layer(unsigned id,
				  unsigned vertexNumberMax,
				  unsigned differentVertexNumberMax);

			/*!
			* \brief   Create a correct copy of the layer, only for save
			*          usage.
			* \param   displayLayer : the layer to copy
			* \warning IDs are copied, then it safeless to use in DisplayManager
			*/
			Layer(Layer const& displayLayer);

            virtual ~Layer();

            /*!
             * \brief   Set the DepthLevel
             * \param   depthLevel : the DepthLevel value
             */
            void initDepthLevel(unsigned depthLevel);

            /*!
             * \brief   Copy the vertices of the VertexArray
             *          into the layer
             * \param   vertexArray : it contains the vertices
             * \param	textureID : the id of the texture
             * \param	primitive : the sf::PrimitiveType need to draw it
             * \param	separateDraw : if this draw has to be alone
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

            /*!
             * \brief   modify the value of the ID
             * \param   newID : the value of the new ID
             */
            void setID(unsigned newID);

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
        
        private :
            LayerID m_id;
            unsigned m_depthLevel;

            VertexArray m_vertexArray;
			SeparateVertexArray m_separateVertexArray;
        };
        
    }
}

#endif // DEF_DISPLAY_LAYER_HPP
