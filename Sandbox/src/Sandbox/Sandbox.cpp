#include <Dust.h>

class ExampleLayer : public Dust::Layer
{
public:
	ExampleLayer() : Layer("Example") { }

	void OnUpdate() override
	{
		DUST_INFO("ExampleLayer::Update");
	}

	void OnEvent(Dust::Event& e) override
	{
		DUST_TRACE("{0}", e.ToString());
	}
};

class Sandbox : public Dust::Application
{
public:
	Sandbox() : Dust::Application()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Dust::ImGuiLayer());
	};
	~Sandbox() {};
};

Dust::Application* Dust::CreateApplication()
{
	return new Sandbox();
}