#pragma once

#include "Config.hpp"
#include "Utils/Container/IDContainer.hpp"
#include "Animations/Sequence/Sequence.hpp"
#include "Animations/Sequence/SequenceID.hpp"
#include "Animations/Sequence/SequenceKey.hpp"
#include "Animations/Animation/AnimationID.hpp"


namespace dae
{
	namespace animations
	{

		class ENGINE_API SequenceManager
		{
		public:
			SequenceManager();

			SequenceID createSequence(std::vector<AnimationID> animationIDs,
										std::string const& key);

			Sequence const& getSequence(SequenceID const& sequenceID) const;

			SequenceID getSequenceID(SequenceKey const& sequenceKey) const;

		private:
			utils::IDContainer<Sequence, SequenceKey, utils::Hash_string_key> m_idContainer;
		};

	}
}
