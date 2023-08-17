#pragma once

#include "RoyalDragon/Core/Window.h"
#include <GLFW/glfw3.h>

namespace RoyalDragon {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_EventCallbackFn = callback; }
		void SetVSync(bool enabled);
		bool IsVSync() const;
		
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		EventCallbackFn m_EventCallbackFn;
		
		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;
		};
		
		WindowData m_Data;
	};
}
