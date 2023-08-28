#pragma once

#include "Base.h"
#include "Window.h"
#include "RoyalDragon/Core/Events/ApplicationEvent.h"
#include "RoyalDragon/Core/LayerStack.h"

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
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		bool onWindowResize(WindowResizeEvent& e);
		bool onWindowClose(WindowCloseEvent& e);
	};

	Application* CreateApplication();
}

