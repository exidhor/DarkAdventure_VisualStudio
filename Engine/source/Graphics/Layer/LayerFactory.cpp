#include "Graphics/Layer/LayerFactory.hpp"

using namespace dae::graphics;

void LayerFactory::AddLayer(unsigned depthLevel,
                            size_t vertexCapacity,
                            size_t mergedDrawCapacity,
                            std::string const& key)
{
	push_back(LayerKey(key),
			  (Layer(key,
			         depthLevel,
			         vertexCapacity,
			         mergedDrawCapacity)));
}

unsigned LayerFactory::capacity() const
{
	return utils::MapTableStorable<Layer, LayerKey, Compare_layer, utils::Hash_string_key>::capacity();
}