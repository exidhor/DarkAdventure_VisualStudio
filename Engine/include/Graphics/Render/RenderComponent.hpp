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
        class ENGINE_API RenderComponent
        {
        public :

            friend class GraphicsEngine;

            /*!
             * \brief
             */
            RenderComponent(std::vector<utils::Vec2f> const& vertexPosition, 
							sf::PrimitiveType primitiveType);
            
            /*!
             * \brief
             */
            virtual ~RenderComponent();

			void setTile(animations::Tile const tile);

            void setColor(sf::Color const& color);

            void setLayer(std::string const& key);

			/**
			* \brief	Set the parameter which determine if it can be merge
			*			which the other draw, if it's possible
			* \param	isSeparateDraw : True if we want NOT merge, False otherwise
			*/
			void setSeparateDraw(bool isSeparateDraw);

			void setDisplayPackage(DisplayPackage const& displayPackage);

			void setVertexArray(VertexArray const& vertexArray);

            sf::Color const& getColor() const;

			LayerKey const& getLayerKey() const;

            void draw(GraphicsEngine & graphicsEngine, 
					  sf::RenderStates renderStates = sf::RenderStates());


            
        protected :

        private :
            DisplayPackage m_displayPackage;
            VertexArray m_vertexArray;

        };
    }
}

#endif // DEF_GRAPHICS_COMPONENT_HPP
