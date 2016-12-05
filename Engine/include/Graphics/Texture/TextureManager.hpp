#pragma once

#ifndef DEF_TEXTURE_MANAGER_HPP
#define DEF_TEXTURE_MANAGER_HPP

#include "Config.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Utils/Container/IDTable.hpp"
#include "Graphics/Texture/TextureID.hpp"
#include "Graphics/Texture/TextureKey.hpp"

#define VOID_TEXTURE_KEY "void"

namespace dae
{
    namespace graphics
    {
        
        /*!
         * \class TextureManager
         * \brief
         *
         */
        class ENGINE_API TextureManager
        {
        public :
            /*!
             * \brief
             */
            TextureManager();
            
            /*!
             * \brief
             */
            virtual ~TextureManager();

			TextureID loadTexture(std::string const& path,
								  std::string const& key);

            TextureID loadTexture(std::string const& path, 
            					  std::string const& key, 
            					  sf::IntRect const& rect);

            const sf::Texture* getTexture(TextureID textureID) const;

            TextureID getTextureID(TextureKey const& key) const;
            
        protected :
        
        private :
            void loadVoidTexture();

            utils::IDTable<sf::Texture, TextureKey, utils::Hash_string_key> m_textures;
        };
        
    }
}

#endif // DEF_TEXTURE_MANAGER_HPP