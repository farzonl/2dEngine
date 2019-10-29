#pragma once

#include "Singleton.h"

class SingletonMgr {
public:
	typedef void (SingletonReleaseFunc)();
	static void registerSingleton(SingletonReleaseFunc* pSingletonRelease);
	static bool areEqual(SingletonReleaseFunc* pSingletonRelease);
private:
	SingletonMgr() = delete;
};

