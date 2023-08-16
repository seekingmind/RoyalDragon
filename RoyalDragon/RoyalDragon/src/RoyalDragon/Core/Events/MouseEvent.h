#pragma once

#include "Event.h"

namespace RoyalDragon {
	class ROYALDRAGON_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y, float dx, float dy)
			: m_MouseX(x), m_MouseY(y), m_DeltaX(dx), m_DeltaY(dy) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX, m_MouseY;
		float m_DeltaX, m_DeltaY;
	};

	class ROYALDRAGON_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : m_Button(button) {}

		int m_Button;
	};

	class ROYALDRAGON_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button, int repeatCount)
			: MouseButtonEvent(button), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		EVENT_CLASS_TYPE(MouseButtonPressed)
	private:
		int m_RepeatCount;
	};

	class ROYALDRAGON_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
