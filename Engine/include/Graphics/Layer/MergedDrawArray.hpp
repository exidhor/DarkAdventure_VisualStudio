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
		 * \class	MergedDrawArray
		 * \brief	It stores the display configuration for some renderComponent.
		 *			It try to do the minimal number of draw by merging the VertexArray
		 *			when it's possible.
		 */
		class ENGINE_API MergedDrawArray
		{
		public :

			/**
			 * \brief	Construct a void Merged Draw Array
			 */
			MergedDrawArray();

			/**
			 * \brief	Construct an Merged Draw Array and allocate some memory
			 * \param	capacity : the memory to allocate
			 */
			MergedDrawArray(size_t capacity);

			/**
			 * \brief	Allocate or reallocate the memory
			 *			It can't reduce the capacity but extend it. It doesn't affect
             *			the data in array.
			 * \param	capacity : the memory to allocate
			 */
			void reserve(size_t capacity);

			/**
			 * \brief	Clear the intern data
			 */
			void clear();

			/**
			 * \brief	Add the configuration and try to merge it with the existant
			 *			data. It merges if the TextureID AND the primitive are equals.
			 * \param	textureID : the ID of the texture
			 * \param	primitive : the primitive of the draw 
			 * \param	numberOfVertices : the number of vertices associated with this
			 *			configuration
			 * \param	separateDraw : if we don't want to try to merge this 
			 */
			void add(TextureID const& textureID, 
					 sf::PrimitiveType primitive, 
					 size_t numberOfVertices,
					 bool separateDraw = false);

			/**
			 * \brief	Return the TextureID associated to the index specified.
			 * \param	index : the index specified correspond to a "draw" i.e. a specific
			 *			configuration for drawing a specific number of vertices.
			 * \return	the TextureID
			 */
			TextureID const& getTextureID(unsigned index) const;

			/**
			 * \brief	Return the Primitive associated to the index specified
			 * \param	index : the index specified correspond to a "draw" i.e. a specific
			 *			configuration for drawing a specific number of vertices.
			 * \return	the Primitive 
			 */
			sf::PrimitiveType getPrimitive(unsigned index) const;

			/**
			 * \brief	Return the number of vertices associated to the index specified
			 * \param	index : the index specified correspond to a "draw" i.e. a specific
			 *			configuration for drawing a specific number of vertices.
			 * \return	the number of vertices
			 */
			size_t getSize(unsigned index) const;

			/**
			 * \brief	Return the number of draw 
			 * \return the number of draw
			 */
			size_t size() const;

		private :
			TextureID const& getLastTextureID() const;
			sf::PrimitiveType getLastPrimitive() const;

			bool m_lastIsSperateDraw;
			std::vector <TextureID> m_textureID;
			std::vector <sf::PrimitiveType> m_primitives;
			std::vector <size_t> m_sizes;
		};
	}
}