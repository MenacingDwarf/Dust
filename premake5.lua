workspace "Dust"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Dust"
	location "Dust"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"DUST_PLATFORM_WINDOWS",
			"DUST_BUILD_DLL"
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

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Dust/vendor/spdlog/include",
		"Dust/src"
	}

	links
	{
		"Dust"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

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
