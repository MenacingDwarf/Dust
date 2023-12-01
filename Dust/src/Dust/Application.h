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

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() const { return *m_Window; }

	private:
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To be defined in Dust client applications
	Application* CreateApplication();
	inline Application* Application::s_Instance = nullptr;
}


