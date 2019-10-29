#include "pch.h"
#include <set>
#include "SingletonMgr.h"
#include "Singleton.h"

namespace
{
	struct Singleton_Members
	{
		typedef std::set<SingletonMgr::SingletonReleaseFunc*> Set;
		Set		m_setSingletonReleases;
		Singleton_Members();
		virtual ~Singleton_Members();
		bool registerSingleton(SingletonMgr::SingletonReleaseFunc*);
	};
}

Singleton_Members::Singleton_Members() {}

Singleton_Members::~Singleton_Members() {
	for (auto pRelease : m_setSingletonReleases) {
		_ASSERT(!SingletonMgr::areEqual(pRelease));
		pRelease();
	}
}

bool Singleton_Members::registerSingleton(SingletonMgr::SingletonReleaseFunc* pRelease)
{
	if (!SingletonMgr::areEqual(pRelease))
	{
		m_setSingletonReleases.insert(pRelease);
	}
	return true;
}


typedef SingletonBase<Singleton_Members> Singleton;
DECLARE_SINGLETON_STATICS(Singleton);

bool SingletonMgr::areEqual(SingletonReleaseFunc* pSingletonRelease) {
	return pSingletonRelease == Singleton::release;
}


void SingletonMgr::registerSingleton(SingletonReleaseFunc* pSingletonRelease) {

}