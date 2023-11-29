#pragma once

#ifdef DUST_PLATFORM_WINDOWS

extern Dust::Application* Dust::CreateApplication();

int main(int argc, char** argv)
{
	Dust::Log::Init();

	Dust::Application* application = Dust::CreateApplication();
	application->Run();
	delete application;

	Dust::Log::Deinit();

	return 0;
}

#endif
