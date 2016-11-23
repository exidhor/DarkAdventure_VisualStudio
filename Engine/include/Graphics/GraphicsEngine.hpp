#pragma once

#ifndef DEF_GRAPHICS_ENGINE_HPP
#define DEF_GRAPHICS_ENGINE_HPP

#include "Config.hpp"
#include <SFML/Graphics.hpp>
#include "Graphics/Layer/DisplayManager.hpp"
#include "Graphics/Render/Drawer.hpp"
#include "Graphics/Texture/TextureManager.hpp"
#include "Graphics/Render/RenderComponent.hpp"

namespace dae
{
    namespace graphics
    {
        /*!
         * \class GraphicsEngine
         * \brief
         */
        class ENGINE_API GraphicsEngine
        {
        public :

            /*!
             * \brief
             */
            GraphicsEngine();

            /*!
             * \brief
             */
            virtual ~GraphicsEngine();

            void init(unsigned numberOfLayer);


			void addLayer(unsigned depthLevel,
						  std::string const& key);

	
			void addLayer(unsigned depthLevel,
						  unsigned vertexLayerSize,
						  std::string const& key);

			void addLayer(unsigned depthLevel,
						  unsigned vertexLayerSize,
						  unsigned differentVertexSize,
						  std::string const& key);

			TextureID loadTexture(std::string const& path,
								  std::string const& key);

            TextureID loadTexture(std::string const& path,
                                  std::string const& key,
                                  sf::IntRect const& rect);

            void clear();

            void draw(RenderComponent & renderComponent);

            void display();

			void setDefaultLayerSizes(unsigned vertexSize, unsigned differentPrimitiveSize);

            void setWindowPtr(sf::RenderWindow * ptr_window);

            sf::RenderWindow const* getWindowPtr() const;

        protected :
        
        private :
            sf::RenderWindow * m_window;

            DisplayManager m_displayManager;
            Drawer         m_drawer;
            TextureManager m_textureManager;
        };
    }
}

#endif // DEF_GRAPHICS_ENGINE_HPP
