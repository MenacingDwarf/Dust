#include "Dust.h"

class Sandbox : public Dust::Application
{
public:
	Sandbox() {};
	~Sandbox() {};
};

Dust::Application* Dust::CreateApplication()
{
	return new Sandbox();
}