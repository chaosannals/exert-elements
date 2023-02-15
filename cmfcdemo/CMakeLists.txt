cmake_minimum_required(VERSION 3.24)

include(FetchContent)

option(VS_LINK_STATIC_MT "static link mt." ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

if (WIN32)
   if (MSVC)
      # 静态运行库 MT
      if (VS_LINK_STATIC_MT)
         set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
         message(STATUS "msvc MT , element md")
      endif()
   endif()
endif()

project(cmfcdemo)

FetchContent_Declare(
    elements
    GIT_REPOSITORY git@github.com:cycfi/elements.git
    # GIT_TAG 
)
# FetchContent_MakeAvailable(elements)

FetchContent_Populate(elements)
# 设置 ELEMENTS_ROOT 指定依赖的 elements 路径
set(ELEMENTS_ROOT ${elements_SOURCE_DIR})

# Make sure ELEMENTS_ROOT is an absolute path to add to the CMake module path
get_filename_component(ELEMENTS_ROOT "${ELEMENTS_ROOT}" ABSOLUTE)
set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${ELEMENTS_ROOT}/cmake")

# 必须取消示例，不然生成 elements 库
include(ElementsConfigCommon)
set(ELEMENTS_BUILD_EXAMPLES OFF) # 这个必须 OFF
add_subdirectory(${ELEMENTS_ROOT} elements)

add_subdirectory(baredemo)
add_subdirectory(customdemo)
