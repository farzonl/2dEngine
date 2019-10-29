#ifndef Singleton_H
#define Singleton_H

#include <atomic>
#include <future>
#include <mutex>
#include <thread>
#include <memory>

#include "SingletonMgr.h"

template<class T>
class SingletonBase : public T
{
public:
	//typedef std::unique_ptr<SingletonBase> pointer;
	typedef std::atomic <SingletonBase*> pointer;
	typedef std::unique_lock<std::mutex> Lock;

	static SingletonBase& get();
	Lock getLock() {
		return Lock(m_mutex);
	}
private:
	// prevent this class from ever being instantiated directly
	SingletonBase();
	// to allow for determanistic singleton destruction (only to be called by SingletonMgr)
	static void release();
	static SingletonBase* getPtr();
	// prevent this class from ever being copied or moved
	SingletonBase(const SingletonBase&) = delete;
	SingletonBase(SingletonBase&&) = delete;
	std::mutex m_mutex;
	static std::mutex s_guardMutex;
	static pointer	  m_pInstance;
	friend class SingletonMgr;
	//NOTE: MSVC triggers internal error on the below line.
	//friend SingletonMgr::areEqual(SingletonMgr::SingletonReleaseFunc* pSingletonRelease);
};


#define DECLARE_SINGLETON_STATICS(T)											\
	template<>T::pointer T::m_pInstance;									    \
	std::mutex T::s_guardMutex;													\
																				\
	template<>T::SingletonBase()												\
	{																			\
		SingletonMgr::registerSingleton(T::release);							\
	}																			\
																				\
	template<>void T::release()													\
	{																			\
		delete getPtr();														\
	}																			\
	template<>T* T::getPtr() {													\
		T* ptr = m_pInstance.load(std::memory_order_acquire);					\
		if (!ptr) {																\
			std::lock_guard<std::mutex> Lock(s_guardMutex);						\
			ptr = m_pInstance.load(std::memory_order_relaxed);					\
			if(!ptr) {															\
				ptr = new T();													\
				m_pInstance.store(ptr, std::memory_order_release);				\
			}																	\
		}																		\
		return ptr;																\
	}																			\
																				\
	template<>T& T::get() {														\
		return *getPtr();														\
	}																			\


#endif