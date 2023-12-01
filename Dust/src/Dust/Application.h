#pragma once

#include "Core.h"
#include "Dust/Window.h"

namespace Dust {

	class WindowCloseEvent;
	
	class DUST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in Dust client applications
	Application* CreateApplication();

}

