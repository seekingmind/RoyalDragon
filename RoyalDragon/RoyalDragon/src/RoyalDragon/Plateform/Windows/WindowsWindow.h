#pragma once

#include "RoyalDragon/Core/Window.h"

namespace RoyalDragon {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void Init(const WindowProps& props);
		void Shutdown();

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_EventCallbackFn = callback; }
		inline unsigned int GetWidth() const override { return m_Width; }
		inline unsigned int GetHeight() const override { return m_Height; }
	protected:
		std::string m_Title;
		unsigned int m_Width, m_Height;
		EventCallbackFn m_EventCallbackFn;
	};
}
