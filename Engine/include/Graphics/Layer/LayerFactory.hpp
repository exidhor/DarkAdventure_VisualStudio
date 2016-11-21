#pragma once

#include "Config.hpp"
#include "Utils/Container/MappedArray.hpp"
#include "Graphics/Layer/Layer.hpp"
#include "Graphics/Layer/LayerKey.hpp"

namespace dae
{
	namespace graphics
	{
		struct Compare_layer
		{
			const std::vector<Layer> & v_layer;

			Compare_layer(const std::vector<Layer> & v_layer)
				: v_layer(v_layer)
			{
				// nothing
			}

			bool compare(int a, int b) const
			{
				return v_layer[a].getDepthLevel() <= v_layer[b].getDepthLevel();
			}
		};
		
		class ENGINE_API LayerFactory : public utils::MappedArray<Layer, 
			                                                      LayerKey, 
			                                                      Compare_layer,
		                                                          utils::Hash_string_key>
		{
		public :
			void AddLayer(unsigned depthLevel,
						  unsigned id,
						  unsigned vertexNumberMax,
						  unsigned differentVertexNumberMax,
						  std::string const& key);

		private :

		};

	}
}