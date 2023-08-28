#include "rdpch.h"
#include "Application.h"
#include <GLFW/glfw3.h>

namespace RoyalDragon {
#define BIND_EVENT_FN(fn) std::bind(&Application::##fn, this, std::placeholders::_1)
	
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}
	
	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::Run()
	{
		onInit();
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			for (Layer* layer : m_LayerStack)
			{
				layer->onUpdate();
			}
			m_Window->OnUpdate();
		}
		onShutdown();
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(onWindowResize));
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	bool Application::onWindowResize(WindowResizeEvent& e)
	{
		return false;
	}
	
	bool Application::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return false;
	}
}
