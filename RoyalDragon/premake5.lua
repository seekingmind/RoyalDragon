workspace "RoyalDragon"
    architecture "x64"
    targetdir "build"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "RoyalDragon/vendor/GLFW/include"

include "RoyalDragon/vendor/GLFW"

project "RoyalDragon"
    location "RoyalDragon"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "rdpch.h"
    pchsource "RoyalDragon/src/rdpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include/",
        "%{IncludeDir.GLFW}"
    }
    
    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "RD_PLATEFORM_WINDOWS",
            "ROYALDRAGON_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/StartApp")
        }
        
    filter "configurations:Debug"
        defines "RD_DEBUG"
        symbols "On"
        
    filter "configurations:Release"
        defines "RD_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "RD_DIST"
        optimize "On"

project "StartApp"
    location "StartApp"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    links
    {
        "RoyalDragon"
    }
    
    files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp"
	}

    includedirs 
	{
        "RoyalDragon/src",
        "RoyalDragon/vendor/spdlog/include/",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "RD_PLATEFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines "RD_DEBUG"
            symbols "On"
                
        filter "configurations:Release"
            defines "RD_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "RD_DIST"
            optimize "On"
            
        filter { "system:windows", "configurations:Release" }
            buildoptions "/MT"  