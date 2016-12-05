#pragma once

#include "Config.hpp"
#include "Utils/Container/IDTableStorable.hpp"
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
			// it needs to be able to access tot the depthLevel value of the
			// Layer to compare them
			const std::vector<Layer> & v_layer;

			
			/**
			 * \brief	Create the structure to compare Layers.
			 * \param	v_layer : all the Layers which will be compared 
			 */
			Compare_layer(const std::vector<Layer> & v_layer)
				: v_layer(v_layer)
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
				return v_layer[a].getDepthLevel() <= v_layer[b].getDepthLevel();
			}
		};
		

		/**
		 * \class	LayerFactory
		 * \brief	Implements the ID Table Storable to create Layers.
		 */
		class ENGINE_API LayerFactory : public utils::IDTableStorable<Layer, 
			                                                      LayerKey, 
			                                                      Compare_layer,
		                                                          utils::Hash_string_key>
		{
		public :

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

		private :

		};

	}
}