workspace "OOP Pong"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "OOP Pong/ThirdParty/GLFW/include"
IncludeDir["Glad"] = "OOP Pong/ThirdParty/Glad/include"

include "OOP Pong/ThirdParty/GLFW"
include "OOP Pong/ThirdParty/Glad"

project "OOP Pong"
    location "OOP Pong"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin/intermediates/" .. outputdir)

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }

    links {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines {
            "PG_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "PG_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PG_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PG_DIST"
        optimize "On"