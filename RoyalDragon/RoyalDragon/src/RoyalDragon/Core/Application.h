#pragma once

#include "Core.h"

namespace RoyalDragon {

	class ROYALDRAGON_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	private:
		
	};

	Application* CreateApplication();
}

