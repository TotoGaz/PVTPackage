include(FetchContent)

FetchContent_Declare(json
                     GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
                     GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

#set(PVTPackage_dump_INCLUDE_DIRS ${PROJECT_INC_DIR} CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

set( PVTPackage_dump_headers
     DebugComponentProperties.hpp
)

set( PVTPackage_dump_sources
     DebugComponentProperties.cpp
)

set(PVTPackage_dump_target PVTPackageDump)
set(PVTPackage_dump_dependencies nlohmann_json::nlohmann_json PVTPackage)

message("adding PVTPackageDump library")
blt_add_library(NAME       ${PVTPackage_dump_target}
                SOURCES    ${PVTPackage_dump_sources}
                HEADERS    ${PVTPackage_dump_headers}
                DEPENDS_ON ${PVTPackage_dump_dependencies})
