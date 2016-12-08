#pragma once

#include "Config.hpp"
#include "Utils/Container/MapTableStorable.hpp"
#include "Graphics/Layer/Layer.hpp"
#include "Graphics/Layer/LayerKey.hpp"

namespace dae
{
	namespace graphics
	{
		
		/**
		 * \struct	Compare_layer
		 * \brief	This structure is used to compare two layers
		 *			to be able to sort them.
		 *			It compares their depth Level value.
		 */
		struct Compare_layer
		{
			// it needs to be able to access to the depthLevel value of the
			// Layer to compare them
			const std::vector<Layer> & layers;

			
			/**
			 * \brief	Create the structure to compare Layers.
			 * \param	layers : all the Layers which will be compared 
			 */
			Compare_layer(const std::vector<Layer> & layers)
				: layers(layers)
			{
				// nothing
			}


			/**
			 * \brief	Compare two Layer.
			 * \param	a : the index of the first Layer
			 * \param	b : the index of the second Layer
			 * \return	true if the first Layer has a smaller depth level
			 *			value, false otherwise
			 */
			bool compare(int a, int b) const
			{
				return layers[a].getDepthLevel() <= layers[b].getDepthLevel();
			}
		};
		

		/**
		 * \class	LayerFactory
		 * \brief	Implements the ID Table Storable to create Layers.
		 */
		class ENGINE_API LayerFactory : public utils::MapTableStorable<Layer, 
			                                                      LayerKey, 
			                                                      Compare_layer,
		                                                          utils::Hash_string_key>
		{
		public :

			friend class DEBUG_GraphicsView; // to be able to display internal infos

			/**
			 * \brief	Create a layer into the ID Table
			 * \param	depthLevel : the depthLevel of the Layer 
			 * \param	vertexCapacity : the vertex capacity to reserve
			 *			into the Layer 
			 * \param	mergedDrawCapacity : the merged draw capacity
			 *			to reserve into the Layer
			 * \param	key : the key of the Layer 
			 */
			void AddLayer(unsigned depthLevel,
			              size_t vertexCapacity,
			              size_t mergedDrawCapacity,
			              std::string const& key);

			/**
			 * \brief	Return the capacity of the factory
			 * \return  the capacity of the factory
			 */
			size_t capacity() const;

		private :

		};

	}
}