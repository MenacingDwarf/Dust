#pragma once

#include "Event.h"

namespace Dust {

	class DUST_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(int x, int y) : m_MouseX(x), m_MouseY(y) {};
		
		inline int GetMouseX() const { return m_MouseX; }
		inline int GetMouseY() const { return m_MouseY; };
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		int m_MouseX, m_MouseY;
	};

	class DUST_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(int offsetX, int offsetY) : m_OffsetX(offsetX), m_OffsetY(offsetY) {};

		inline int GetOffsetX() const { return m_OffsetX; }
		inline int GetOffsetY() const { return m_OffsetY; };
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_OffsetX << ", " << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		int m_OffsetX, m_OffsetY;
	};

	class DUST_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_ButtonCode; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryMouse | EventCategoryInput);

	protected:
		MouseButtonEvent(int buttonCode) : m_ButtonCode(buttonCode) {};

		int m_ButtonCode;
	};

	class DUST_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int buttonCode) : MouseButtonEvent(buttonCode) {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_ButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class DUST_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int buttonCode) : MouseButtonEvent(buttonCode) {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_ButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}