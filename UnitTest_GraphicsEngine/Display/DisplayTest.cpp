#include <SFML/Graphics.hpp>
#include "CppUnitTest.h"
#include "Graphics/Display/Layer.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_GraphicsEngine
{
	TEST_CLASS(UnitTest_DisplayLayer)
	{
	public:

		TEST_METHOD(UnitTest_InitPrimitive)
		{
			unsigned id = 2;
			unsigned size = 10;
			std::string key("layer_key");
			dae::graphics::Layer displayLayer(id, size, key);

			sf::PrimitiveType primitive(sf::PrimitiveType::Triangles);

			displayLayer.initPrimitive(primitive);
			
			Assert::AreEqual(
				// Expected value:
				primitive,
				// Actual value:
				displayLayer.getPrimitive(),
				// Message:
				L"InitPrimitive test failed",
				// Line number - used if there is no PDB file:
				LINE_INFO());
		}

	};
}