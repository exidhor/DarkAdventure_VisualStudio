#include "Graphics/Layer/LayerFactory.hpp"

using namespace dae::graphics;

void LayerFactory::AddLayer(unsigned depthLevel,
							unsigned id,
							unsigned vertexNumberMax,
							unsigned differentVertexNumberMax,
							std::string const& key)
{
	push_back(Layer(id,
			        vertexNumberMax,
			        differentVertexNumberMax,
			        key),
			  LayerKey(key));

	operator[](size() - 1).initDepthLevel(depthLevel);
}