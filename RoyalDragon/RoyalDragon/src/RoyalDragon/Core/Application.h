#pragma once

#include "Core.h"
#include "Window.h"

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
		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();
}

