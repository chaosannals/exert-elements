set(ELEMENTS_APP_PROJECT "baredemo")
set(ELEMENTS_APP_TITLE "baredemo")
set(ELEMENTS_APP_COPYRIGHT "Copyright (c) 2023")
set(ELEMENTS_APP_ID "com.cycfi.empty-starter")
set(ELEMENTS_APP_VERSION "1.0")

set(ELEMENTS_APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
file(GLOB BAREDEMO_VIEW_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/view/*.cpp)
file(GLOB BAREDEMO_VIEW_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/view/*.h)
list(APPEND ELEMENTS_APP_SOURCES ${BAREDEMO_VIEW_SOURCES})
list(APPEND ELEMENTS_APP_SOURCES ${BAREDEMO_VIEW_HEADERS})

set(ELEMENTS_APP_RESOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/res/WenQuanYiMicroHei.ttf
)

include(AppIcon)
include(ElementsConfigApp)
