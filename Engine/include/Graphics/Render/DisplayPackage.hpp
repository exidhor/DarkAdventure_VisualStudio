#pragma once

#ifndef DEF_DISPLAY_PACKAGE_HPP
#define DEF_DISPLAY_PACKAGE_HPP

#include "Config.hpp"
#include <SFML/Graphics.hpp>
#include "Graphics/Layer/LayerKey.hpp"
#include "Graphics/Layer/LayerID.hpp"
#include "Graphics/Texture/TextureID.hpp"
#include "Graphics/Layer/Layer.hpp"

namespace dae
{
    namespace graphics
    {

	    /**
	     * \class	DisplayPackage
         * \brief	It contains all the parameters to draw correctly the target
         */
        class ENGINE_API DisplayPackage
        {
        public :

	        /**
             * \brief	Construct the DisplayPackage with default value.
             */
            DisplayPackage();

            virtual ~DisplayPackage();

	        /**
             * \brief	Set the Layer, to define the order of drawing
             * \param	key : the key which define the Layer
             */
            void setLayer(LayerKey const& key);

	        /**
			 * \brief	Set the Texture 
			 * \param	id: the TextureID
			 */
			void setTexture(TextureID id);

            /*!
             * \brief   Set the last DisplayLayerID value, to
             *          use it again if no parameter changed.
             * \param   displayLayerID : the DisplayLayerID value
             */
            void setDisplayLayerID(LayerID displayLayerID);

	        /**
			 * \brief	Set the Primitive for the render
			 * \param	primitiveType : the Primitive 
			 */
			void setPrimitive(sf::PrimitiveType primitiveType);

	        /**
			 * \brief	Set the parameter which determine if it can be merge
			 *			which the other draw, if it's possible
			 * \param	isSeparateDraw : True if we want NOT merge, False otherwise
			 */
			void setSeparateDraw(bool isSeparateDraw);

            /*!
             * \brief   Get the last DisplayLayerID value.
             *          It may be obsolete if the display parameter
             *          changeds since the last draw.
             * \return  the reference to the Layer value
            */
            LayerID getDisplayLayerID() const;

	        /**
			 * \brief	Return the TextureID
			 * \return	the TextureID
			 */
			TextureID getTextureID() const;

	        /**
			 * \brief	Return the Primitive type
			 * \return	The primitive type
			 */
			sf::PrimitiveType getPrimitive() const;

	        /**
			 * \brief	Return the LayerKey
			 * \return	The LayerKey
			 */
			LayerKey const& getLayerKey() const;

	        /**
             * \brief	Inform if the DisplayId is up to date,
             *			which means that it can be used 
             * \return	True if the DisplayID is up to date, False otherwise 
             */
            bool displayIdIsUpToDate() const;

	        /**
			 * \brief	Inform if it can be merge or not
			 * \return	True if it CAN'T be merge, False otherwise
			 */
			bool isSeparateDraw() const;

        protected :

        private :
			TextureID m_textureID;
			sf::PrimitiveType m_displayPrimitive;
			bool m_separateDraw;

			LayerKey m_layerKey;

            bool m_lastID_upToDate;
            LayerID m_lastDisplayLayerID;
        };

    }
}



#endif // DEF_DISPLAY_PACKAGE_HPP