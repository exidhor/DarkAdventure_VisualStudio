#include "Graphics/Layer/LayerFactory.hpp"

using namespace dae::graphics;

void LayerFactory::AddLayer(unsigned depthLevel,
							unsigned id,
							unsigned vertexNumberMax,
							unsigned differentVertexNumberMax,
							std::string const& key)
{
	push_back(LayerKey(key),
			  std::move(Layer(id,
			                  vertexNumberMax,
			                  differentVertexNumberMax)));

	operator[](size() - 1).initDepthLevel(depthLevel);
}