workspace "Dust"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["spdlog"] = "Dust/vendor/spdlog/include"
IncludeDir["GLFW"] = "Dust/vendor/GLFW/include"
IncludeDir["Glad"] = "Dust/vendor/Glad/include"
IncludeDir["ImGui"] = "Dust/vendor/imgui"

include "Dust/vendor/GLFW"
include "Dust/vendor/Glad"
include "Dust/vendor/imgui"

project "Dust"
	location "Dust"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dustpch.h"
	pchsource "Dust/src/dustpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"DUST_PLATFORM_WINDOWS",
			"DUST_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DUST_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "DUST_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "DUST_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Dust/src",
		"%{IncludeDir.spdlog}",
	}

	links
	{
		"Dust"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"DUST_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DUST_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "DUST_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "DUST_DIST"
		optimize "On"
