#pragma once

#include "Core.h"
#include "Window.h"
#include "RoyalDragon/Core/Events/ApplicationEvent.h"

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

		virtual void onEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	private:
		bool onWindowResize(WindowResizeEvent& e);
		bool onWindowClose(WindowCloseEvent& e);
	};

	Application* CreateApplication();
}

