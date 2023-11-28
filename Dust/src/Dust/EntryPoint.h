#pragma once

#ifdef DUST_PLATFORM_WINDOWS

extern Dust::Application* Dust::CreateApplication();

int main(int argc, char** argv)
{
	Dust::Application* application = Dust::CreateApplication();
	application->Run();
	delete application;
	return 0;
}

#endif
