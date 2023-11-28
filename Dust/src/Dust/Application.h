#pragma once

#include "Core.h"

namespace Dust {

	class DUST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in Dust applications
	Application* CreateApplication();

}

