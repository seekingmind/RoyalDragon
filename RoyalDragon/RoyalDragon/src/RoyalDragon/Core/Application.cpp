#include "rdpch.h"
#include "Application.h"

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

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(onWindowResize));
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		RD_CORE_TRACE("{0}", e);
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
