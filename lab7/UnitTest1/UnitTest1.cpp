#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7/lab7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			AbstractFactory* F = new NYFactory();
			PostCard* m;
			m = F->createPostCard();
			Assert::IsTrue(m->give() == "NYCard::give()");
		}

		TEST_METHOD(TestMethod2)
		{
			AbstractFactory* F = new NYFactory();
			Present* b;
			b = F->createPresent();
			Assert::IsTrue(b->give() == "NYPresent::give()");
		}

		TEST_METHOD(TestMethod3)
		{
			AbstractFactory* F = new NYFactory();
			Cake* d;
			d = F->createCake();
			Assert::IsTrue(d->give()== "NYCake::give()");
		}

		TEST_METHOD(TestMethod4)
		{
			AbstractFactory* F = new BDFactory();
			PostCard* m;
			m = F->createPostCard();
			Assert::IsTrue(m->give() == "BDCard::give()");
		}

		TEST_METHOD(TestMethod5)
		{
			AbstractFactory* F = new BDFactory();
			Present* b;
			b = F->createPresent();
			Assert::IsTrue(b->give() == "BDPresent::give()");
		}


		TEST_METHOD(TestMethod6)
		{
			AbstractFactory* F = new BDFactory();
			Cake* d;
			d = F->createCake();
			Assert::IsTrue(d->give() == "BDCake::give()");
		}

		TEST_METHOD(TestMethod7)
		{
			AbstractFactory* F = new  MarchFactory();
			PostCard* m;
			m = F->createPostCard();
			Assert::IsTrue(m->give() == "MarchCard::give()");
		}

		TEST_METHOD(TestMethod8)
		{
			AbstractFactory* F = new MarchFactory();
			Present* b;
			b = F->createPresent();
			Assert::IsTrue(b->give() == "MarchPresent::give()");
		}

		TEST_METHOD(TestMethod9)
		{
			AbstractFactory* F = new MarchFactory();
			Cake* d;
			d = F->createCake();
			Assert::IsTrue(d->give() == "MarchCake::give()");
		}

	};
}
