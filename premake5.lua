workspace "SFML-Space-Shooter"

	configurations
	{
		"Debug",
		"Release"
	}
	
	  platforms
	  {
		  "x86",
		  "x86_64"
	  }
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "SpaceShooter"
	location "SpaceShooter"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/res/**"
	}

	includedirs
	{
		"deps/SFML/include"
	}
	
	libdirs
	{
		"deps/SFML/lib"
	}
	
	defines
	{
		"SFML_STATIC"
	}
	
	filter "system:Windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
		links
		{
			"sfml-system-s-d", 
			"sfml-window-s-d", 
			"sfml-graphics-s-d"
		}
		
	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
		links
		{
			"sfml-system-s", 
			"sfml-window-s", 
			"sfml-graphics-s"
		}
		
	filter "configurations:*"
		links
		{
			"opengl32",
			"freetype",
			"winmm",
			"gdi32"
		}