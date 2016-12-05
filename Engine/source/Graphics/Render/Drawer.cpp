#include "Graphics/Render/Drawer.hpp"

using namespace dae::graphics;

Drawer::Drawer()
{
    // nothing
}

Drawer::~Drawer()
{
    // nothing
}

void Drawer::draw(LayerManager & displayManager,
                  TextureManager & textureManager,
                  sf::RenderTarget & renderTarget)
{
	dae::utils::Iterator<unsigned> iterator = displayManager.m_layerFactory.getIterator();

	while(!iterator.isStuck())
	{
		unsigned index = iterator.current();

		displayManager.m_layerFactory[index].draw(renderTarget, textureManager);

		iterator.next();
	}
}