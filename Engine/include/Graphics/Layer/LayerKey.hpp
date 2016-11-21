#pragma once

#include "Config.hpp"
#include <string>
#include "Utils/Identifier/KeyString.hpp"

namespace dae
{
	namespace graphics
	{
		
		/**
		 * \class	LayerKey
		 * \brief	Use to find the LayerID corresponding to
		 *			this Layer.
		 */
		class ENGINE_API LayerKey : public utils::KeyString
		{
		public :
			explicit LayerKey(std::string const& key)
				: KeyString(key)
			{
				// nothing
			}
			
		};

	}
}
