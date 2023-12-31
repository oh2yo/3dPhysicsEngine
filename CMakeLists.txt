cmake_minimum_required(VERSION 3.22)

project(3dPhysicsEngine)

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES)

target_sources(${PROJECT_NAME}
    PRIVATE
        macros.h
        mesh.h
        Object.h
        world.h
        bodyInstance.h
        physicsComponent.h
        collisionGeometry.h
        physicsDefinition.h
        topology.h
        AABB.h
        modelInit.h
        shader.h
)

target_sources(${PROJECT_NAME}
    PRIVATE
        mesh.cpp
        Object.cpp
        world.cpp
        bodyInstance.cpp
        topology.cpp
        AABB.cpp
        modelInit.cpp
        shader.cpp
)


if(APPLE OR WIN32)

    find_package(OpenGL REQUIRED)
    find_library(glfwLIB NAMES glfw glfw3 PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib)

    target_include_directories(${PROJECT_NAME}
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/include/glfw
            ${CMAKE_CURRENT_SOURCE_DIR}/include/glad
    )
    target_sources(${PROJECT_NAME}
        PRIVATE
            glad.c
            renderInit.cpp
    )
    target_sources(${PROJECT_NAME}
        PRIVATE
            stb_image.h
            camera.h
            renderInit.h
    )

    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} ${glfwLIB})

endif()


if(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COREVIDEO_LIBRARY CoreVideo)
    target_link_libraries(${PROJECT_NAME}
            "${COCOA_LIBRARY}"
            "${IOKIT_LIBRARY}"
            "${COREVIDEO_LIBRARY}"
    )
endif()











