#include "Graphics/Texture/TextureManager.hpp"

using namespace dae::graphics;

TextureManager::TextureManager()
{
    loadVoidTexture();
}

TextureManager::~TextureManager()
{
	// nothing
}

TextureID TextureManager::loadTexture(std::string const& path,
									  std::string const& key)
{
	m_textures.push_back(TextureKey(key), sf::Texture());

	unsigned index = m_textures.size() - 1;

	if (!m_textures[index].loadFromFile(path))
		{
		std::cerr<<"ERROR while loading texture"<<std::endl;
		std::cerr<<"\tkey : "<<key<<std::endl;
		std::cerr<<"\tpath : "<<path<<std::endl;
		std::cerr<<"\ttextureID : "<<index<<std::endl;
		}

	return TextureID(index);
}

TextureID TextureManager::loadTexture(std::string const& path,
                                      std::string const& key,
                                      sf::IntRect const& rect)
{
    m_textures.push_back(TextureKey(key), sf::Texture());

    unsigned index = m_textures.size() - 1;

    if (!m_textures[index].loadFromFile(path, rect))
    {
        std::cerr << "ERROR while loading texture" << std::endl;
        std::cerr << "\tkey : " << key << std::endl;
        std::cerr << "\tpath : " << path << std::endl;
        std::cerr << "\trect : top(" << rect.top << "), left(" << rect.left << "), width(" << rect.width << "), height(" << rect.height << ")" << std::endl;
        std::cerr << "\ttextureID : " << index << std::endl;
    }

    return TextureID(index);
}

const sf::Texture* TextureManager::getTexture(TextureID textureID) const
{
    if(textureID.getValue() == 0)
        return nullptr;

    return &m_textures[textureID.getValue()];
}

TextureID TextureManager::getTextureID(TextureKey const& key) const
{
    return TextureID(m_textures.getIndex(key));
}

void TextureManager::loadVoidTexture()
{
    m_textures.push_back(TextureKey(VOID_TEXTURE_KEY), sf::Texture());
}