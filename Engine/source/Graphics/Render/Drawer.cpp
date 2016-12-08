#include "Graphics/Render/Drawer.hpp"

using namespace dae::graphics;

void Drawer::draw(LayerManager & layerManager,
                  TextureManager & textureManager,
                  sf::RenderTarget & renderTarget)
{
	dae::utils::Iterator<unsigned> iterator = layerManager.m_layerFactory.getIterator();

	while(!iterator.isStuck())
	{
		unsigned index = iterator.current();

		layerManager.m_layerFactory[index].draw(renderTarget, textureManager);

		iterator.next();
	}
}