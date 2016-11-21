#pragma once

#include "Config.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Graphics/Texture/TextureID.hpp"

namespace dae
{
	namespace graphics
	{

		/**
		 * \class	SeparateVertexArray
		 * \brief	It stores the display configuration for some renderComponent.
		 *			It try to do the minimal draw by merging the VertexArray when 
		 *			it's possible.
		 */
		class ENGINE_API SeparateVertexArray
		{
		public :

			/**
			 * \brief	Construct a void Separate Vertex Array
			 */
			SeparateVertexArray();

			/**
			 * \brief	Construct an Separate Vertex Array and allocate some memories
			 * \param	reservedSize : the memory to allocate
			 */
			SeparateVertexArray(unsigned reservedSize);

			/**
			 * \brief	Allocate or reallocate the memory
			 * \param	size : the memory to allocate
			 */
			void reserve(unsigned size);

			/**
			 * \brief	Clear all the intern data
			 */
			void clear();

			/**
			 * \brief	Add the configuration and try to merge it with the existant
			 *			data. It merges if the TextureID AND the primitive are equals.
			 * \param	textureID : the ID of the texture
			 * \param	primitive : the primitive of the draw 
			 * \param	size : the number of vertex we want to draw with this configuration
			 * \param	separateDraw : if we want to try to merge this 
			 */
			void add(TextureID const& textureID, 
					 sf::PrimitiveType primitive, 
					 unsigned size,
					 bool separateDraw = false);

			/**
			 * \brief	Return the TextureID associated to the index specified
			 * \param	index : the index specified 
			 * \return	the TextureID
			 */
			TextureID const& getTextureID(unsigned index) const;

			/**
			 * \brief	Return the Primitive associated to the index specified
			 * \param	index : the index specified 
			 * \return	the Primitive 
			 */
			sf::PrimitiveType getPrimitive(unsigned index) const;

			/**
			 * \brief	Return the size associated to the index specified
			 * \param	index : the index specified  
			 * \return	the size
			 */
			unsigned getSize(unsigned index) const;

			/**
			 * \brief	Return the number of draw 
			 * \return the number of draw
			 */
			unsigned size() const;

		private :
			TextureID const& getLastTextureID() const;
			sf::PrimitiveType getLastPrimitive() const;

			std::vector <TextureID> m_textureID;
			std::vector <sf::PrimitiveType> m_primitives;
			std::vector <unsigned> m_sizes;
		};
	}
}