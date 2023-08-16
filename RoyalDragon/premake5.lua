workspace "RoyalDragon"
    architecture "x64"
    targetdir "build"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

local outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "RoyalDragon"
    location "RoyalDragon"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

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
    
    dependson 
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
        
        links
        {
            "RoyalDragon"
        }

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