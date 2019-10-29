#include "CppUnitTest.h"
#include "../2DEngine/pch.h"
#include "../2DEngine/WindowMgr.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2DEngineNativeTests
{
	TEST_CLASS(My2DEngineNativeTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(0, WindowMgr::getHeight());
			Assert::AreEqual(0, WindowMgr::getWidth());
			WindowMgr::setSize(800, 600);
			Assert::AreEqual(600, WindowMgr::getHeight());
			Assert::AreEqual(800, WindowMgr::getWidth());
		}
	};
}
