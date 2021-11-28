cmake_minimum_required(VERSION 3.14)
project(mp)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp MpEngine.cpp MpEngine.hpp Plane.cpp Plane.hpp FreeCam.hpp FreeCam.hpp CameraManager.cpp CameraManager.hpp GenericCharacter.cpp GenericCharacter.hpp  Popsickle.cpp Popsickle.hpp Deimos.cpp Deimos.hpp ArcBallCam.cpp ArcBallCam.hpp Flashlight.cpp Flashlight.hpp  Block.cpp Block.hpp Tree.cpp Tree.hpp Skier.cpp Skier.hpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Windows with MinGW Installations
if( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" AND MINGW )
    # if working on Windows but not in the lab
    # update the include directory location
    include_directories("C:/CSCI441/include")
    # update the lib directory location
    target_link_directories(${PROJECT_NAME} PUBLIC "C:/CSCI441/lib")
    target_link_libraries(${PROJECT_NAME} opengl32 glfw3 glew32.dll gdi32)
# OS X Installations
elseif( APPLE AND ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )
    # update the include directory location
    include_directories("/usr/local/include")
    # update the lib directory location
    target_link_directories(${PROJECT_NAME} PUBLIC "/usr/local/lib")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreVideo" glfw3 glew)
# Blanket *nix Installations
elseif( UNIX AND ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
    # update the include directory location
    include_directories("/home/cmmeyers/Dropbox/Graphics/include")
    # update the lib directory location
    target_link_directories(${PROJECT_NAME} PUBLIC "/usr/local/lib")
    target_link_libraries(${PROJECT_NAME} OpenGL glfw GLEW)
endif()