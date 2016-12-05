#include "Graphics/Layer/LayerFactory.hpp"

using namespace dae::graphics;

void LayerFactory::AddLayer(unsigned depthLevel,
                            size_t vertexCapacity,
                            size_t mergedDrawCapacity,
                            std::string const& key)
{
	push_back(LayerKey(key),
			  (Layer(depthLevel,
			         vertexCapacity,
			         mergedDrawCapacity)));
}