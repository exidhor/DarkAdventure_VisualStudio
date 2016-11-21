#pragma once

#include "Config.hpp"
#include "Utils/Container/IDContainer.hpp"
#include "Animations/Time/Time.hpp"
#include "Animations/Time/TimeKey.hpp"
#include "Animations/Time/TimeID.hpp"

namespace dae
{
	namespace animations
	{

		class ENGINE_API TimeManager
		{
		public:
			TimeManager();
			
			TimeID createTime(std::vector<unsigned> const& times,
							  std::string const& timeKey);

			Time const& getTime(TimeID const& timeID) const;

			TimeID getTimeID(TimeKey const& timeKey) const;

		private:
			utils::IDContainer<Time, TimeKey, utils::Hash_string_key> m_idContainer;
		};

	}
}
