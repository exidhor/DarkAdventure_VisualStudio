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
         * \brief   Static class in charge of the draw of each elements 
         *			from the layers
         */
	    class ENGINE_API Drawer
	    {
		public :
			/*!
			* \brief   Draw all the stuff in the LayerManager.
			* \param   layerManager : the LayerManager where
			*          all the datas are.
			* \param   textureManager : the TextureManager where
			*          all the textures are.
			* \param   renderTarget : where all the stuff will be
			*          drawn.
			*/
			static void draw(LayerManager & layerManager,
							 TextureManager & textureManager,
							 sf::RenderTarget & renderTarget);
		};
        
    }
}

#endif // DEF_DRAWER_HPP