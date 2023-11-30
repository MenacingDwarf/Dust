#pragma once

#include "Core.h"
#include "Dust/Window.h"

namespace Dust {

	class DUST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in Dust applications
	Application* CreateApplication();

}

