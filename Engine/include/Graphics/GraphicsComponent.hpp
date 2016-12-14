#pragma once

#ifndef DEF_GRAPHICS_COMPONENT_HPP
#define DEF_GRAPHICS_COMPONENT_HPP

#include "Config.hpp"
#include "Utils/Container/Vec2.hpp"
#include "Graphics/Render/DisplayPackage.hpp"
#include "Graphics/Render/VertexArray.hpp"
#include "Graphics/Layer/LayerKey.hpp"
#include "Animations/Tile/Tile.hpp"

namespace dae
{
    namespace graphics
    {
        class GraphicsEngine; // foreward declaration

        /*!
         * \class	RenderComponent
         * \brief	
         *
         */
        class ENGINE_API GraphicsComponent
        {
        public :

            friend class GraphicsEngine;

		    // todo : see if we can use default constructor     	
        	// RenderComponent(sf::PrimitiveType primitiveType = sf::PrimitiveType::Quads);
            
        	/*!
             * \brief	todo
             */
            GraphicsComponent(std::vector<utils::Vec2f> const& vertexPosition, 
							sf::PrimitiveType primitiveType);
            
            /*!
             * \brief	void
             */
            virtual ~GraphicsComponent();

	        /**
			 * \brief	Set the tile to the component.
			 * \param	tile : the tile to set
			 */
			void setTile(animations::Tile const tile);

	        /**
             * \brief	Set the color to the component. The color
             *			can be added to the texture to produce a new result
             * \param	color : the color to set
             */
            void setColor(sf::Color const& color);

	        /**
             * \brief	Set the layer. The Layer will determine the order of the draw
             * \param	key : the LayerKey
             */
            void setLayer(std::string const& key);

			/**
			* \brief	Set the parameter which determine if it can be merge
			*			which the other draw, if it's possible
			* \param	isSeparateDraw : True if we want NOT merge, False otherwise
			*/
			void setSeparateDraw(bool isSeparateDraw);

			// todo 
	        /**
			 * \brief	
			 * \param	displayPackage : 
			 */
			void setDisplayPackage(DisplayPackage const& displayPackage);

	        /**
			 * \brief 
			 * \param vertexArray : 
			 */
			void setVertexArray(VertexArray const& vertexArray);

	        /**
             * \brief 
             * \return 
             */
            sf::Color const& getColor() const;

	        /**
			 * \brief 
			 * \return 
			 */
			LayerKey const& getLayerKey() const;

	        /**
             * \brief 
             * \param graphicsEngine : 
             * \param renderStates : 
             */
            void draw(GraphicsEngine & graphicsEngine, 
					  sf::RenderStates renderStates = sf::RenderStates());

        private :
            DisplayPackage m_displayPackage;
            VertexArray m_vertexArray;

        };
    }
}

#endif // DEF_GRAPHICS_COMPONENT_HPP
