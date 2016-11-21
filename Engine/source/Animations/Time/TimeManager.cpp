#include "Animations/Time/TimeManager.hpp"

using namespace dae::animations;

TimeManager::TimeManager()
{
	// nothing
}

TimeID TimeManager::createTime(std::vector<unsigned> const& times,
							   std::string const& timeKey)
{
	m_idContainer.push_back(Time(times), TimeKey(timeKey));

	return TimeID(m_idContainer.size() - 1);
}

Time const& TimeManager::getTime(TimeID const& timeID) const
{
	return m_idContainer[timeID.getValue()];
}

TimeID TimeManager::getTimeID(TimeKey const& timeKey) const
{
	return TimeID(m_idContainer.getIndex(timeKey));
}