#pragma once

#ifndef DEF_DRAWER_HPP
#define DEF_DRAWER_HPP

#include "Config.hpp"
#include "SFML/Graphics.hpp"
#include "Graphics/Layer/LayerManager.hpp"
#include "Graphics/Texture/TextureManager.hpp"

namespace dae
{
    namespace graphics
    {
        
        /*!
         * \class   Drawer
         * \brief   In charge of the draw of each elements during
         *          the frame.
         */
        class ENGINE_API Drawer
        {
        public :
            /*!
             * \brief   nothing
             */
            Drawer();
            
            /*!
             * \brief   nothing
             */
            virtual ~Drawer();

            /*!
             * \brief   Draw all the stuff in the DisplayManager.
             * \param   displayManager : the DisplayManager where
             *          all the datas are.
             * \param   textureManager : the TextureManager where
             *          all the textures are.
             * \param   renderTarget : where all the stuff will be
             *          drawn.
             */
            void draw(LayerManager & displayManager,
                      TextureManager & textureManager,
                      sf::RenderTarget & renderTarget);
            
        protected :
        
        private :
        
        };
        
    }
}

#endif // DEF_DRAWER_HPP