#pragma once

#include "Config.hpp"
#include "Graphics/Render/RenderComponent.hpp"
#include "Utils/Container/Iterator.hpp"
#include "Animations/Animation/AnimationID.hpp"
#include "Animations/Animation/AnimationManager.hpp"
#include "Animations/Tile/TileID.hpp"
#include "Animations/Tile/TileManager.hpp"
#include "Animations/AnimationPlayer.hpp"
#include "Animations/Machine/AnimationMachine.hpp"

namespace dae
{
	namespace animations
	{
		class ENGINE_API AnimationComponent
		{
		public :
			static void setManagersPtr(AnimationManager* animationManager,
									   TileManager* tileManager);

			AnimationComponent();

			void reset();

			void setAnimationMachine(AnimationMachine const& animationMachine);

			void update(graphics::RenderComponent & renderComponent, unsigned time);

			AnimationID getCurrentAnimationID() const;


		private :
			void ActualizePlayerWithState();

			AnimationPlayer m_player;
			AnimationMachine m_machine;

			static const AnimationManager * s_animationManager;
			static const TileManager * s_tileManager;
		};
		
	}
}
