#include "dustpch.h"

#include "ImGuiLayer.h"

#include "Dust/Application.h"
#include "Dust/Events/MouseEvent.h"
#include "Dust/Events/KeyEvent.h"
#include "Dust/Events/ApplicationEvent.h"
#include "Dust/Platforms/OpenGL/ImGuiOpenGLRenderer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Dust
{	
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
    
		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// TEMPORARY: should eventually use Hazel key codes
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
    
	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		const Window& window = Application::Get().GetWindow();
		io.DisplaySize = ImVec2(window.GetWidth(), window.GetHeight());
    
		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0 / 60.f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);
    
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		
		dispatcher.Dispatch<MouseButtonPressedEvent>(DUST_BIND_EVENT_FUNC(ImGuiLayer::OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(DUST_BIND_EVENT_FUNC(ImGuiLayer::OnMouseButtonReleased));
		dispatcher.Dispatch<MouseMovedEvent>(DUST_BIND_EVENT_FUNC(ImGuiLayer::OnMouseMoved));
		dispatcher.Dispatch<MouseScrolledEvent>(DUST_BIND_EVENT_FUNC(ImGuiLayer::OnMouseScrolled));
		
		dispatcher.Dispatch<KeyPressedEvent>(DUST_BIND_EVENT_FUNC(ImGuiLayer::OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(DUST_BIND_EVENT_FUNC(ImGuiLayer::OnKeyReleased));
		dispatcher.Dispatch<KeyTypedEvent>(DUST_BIND_EVENT_FUNC(ImGuiLayer::OnKeyTyped));
		
		dispatcher.Dispatch<WindowResizeEvent>(DUST_BIND_EVENT_FUNC(ImGuiLayer::OnWindowResize));
	}

	bool ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool ImGuiLayer::OnMouseMoved(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetMouseX(), e.GetMouseY());

		return false;
	}

	bool ImGuiLayer::OnMouseScrolled(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel += e.GetOffsetY();
		io.MouseWheelH += e.GetOffsetX();

		return false;
	}

	bool ImGuiLayer::OnKeyPressed(KeyPressedEvent& e)
	{
		SetKeyDown(e.GetKeyCode(), true);
		return false;
	}

	bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent& e)
	{
		SetKeyDown(e.GetKeyCode(), false);
		return false;
	}

	bool ImGuiLayer::OnKeyTyped(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		
		int c = e.GetKeyCode();
		if (c > 0 && c <= 1000)
			io.AddInputCharacter(c);

		return false;
	}

	bool ImGuiLayer::OnWindowResize(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		
		return false;
	}

	void ImGuiLayer::SetKeyDown(int KeyCode, bool IsDown)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[KeyCode] = IsDown;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
	}
}
