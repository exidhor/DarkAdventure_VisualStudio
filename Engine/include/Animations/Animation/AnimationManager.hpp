#pragma once

#include "Config.hpp"
#include "Utils/Container/IDContainer.hpp"
#include "Animations/Animation/Animation.hpp"
#include "Animations/Animation/AnimationKey.hpp"
#include "Animations/Animation/AnimationID.hpp"

namespace dae
{
	namespace animations
	{

		class ENGINE_API AnimationManager
		{
		public:
			AnimationManager();

			AnimationID createAnimation(TileGroupID const& tileGroupID,
								   TimeID const& timeID,
								   std::string const& key);

			Animation const& getAnimation(AnimationID const& animationID) const;

			AnimationID getAnimationID(AnimationKey const& animationKey) const;

		private:
			utils::IDContainer<Animation, AnimationKey, utils::Hash_string_key> m_idContainer;
		};

	}
}
