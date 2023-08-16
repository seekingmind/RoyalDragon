#pragma once

#include "Core.h"

namespace RoyalDragon {

	class ROYALDRAGON_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

		virtual void onInit() {}
		virtual void onUpdate() {}
		virtual void onShutdown() {}
	private:
		
	};

	Application* CreateApplication();
}

