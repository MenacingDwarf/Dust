#pragma once

#include "Core.h"
#include "Dust/Window.h"
#include "Dust/Layer/LayerStack.h"

namespace Dust {

	class WindowCloseEvent;
	
	class DUST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in Dust client applications
	Application* CreateApplication();

}

