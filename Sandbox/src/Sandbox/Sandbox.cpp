#include <Dust.h>

class Sandbox : public Dust::Application
{
public:
	Sandbox() : Dust::Application() {};
	~Sandbox() {};
};

Dust::Application* Dust::CreateApplication()
{
	return new Sandbox();
}