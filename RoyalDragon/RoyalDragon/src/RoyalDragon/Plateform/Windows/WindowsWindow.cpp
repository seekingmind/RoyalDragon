#include "rdpch.h"
#include "WindowsWindow.h"

namespace RoyalDragon {
	Window::~Window()
	{
	}
	
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Title = props.Title;
		m_Width = props.Width;
		m_Height = props.Height;

		// TODO: GLFW
		RD_CORE_INFO("Creating window {0} ({1}, {2})", m_Title, m_Width, m_Height);
	}

	void WindowsWindow::Shutdown()
	{
	}

	void WindowsWindow::OnUpdate()
	{
		RD_CORE_INFO("WindowsWindow::OnUpdate");
	}
}