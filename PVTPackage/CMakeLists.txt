# set IDE filters
set(PROJECT_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/source)
set(PROJECT_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/source)

file(GLOB_RECURSE PROJECT_SRC ${PROJECT_SRC_DIR}/*.cpp)
file(GLOB_RECURSE PROJECT_HDR ${PROJECT_SRC_DIR}/*.hpp)

foreach(src IN LISTS PROJECT_HDR PROJECT_SRC)
    file(RELATIVE_PATH rel_scr ${CMAKE_CURRENT_LIST_DIR} ${src})
    get_filename_component(fname "${rel_scr}" NAME)
    string(REPLACE "src/" "" src_grp "${rel_scr}")
    string(REPLACE "${fname}" "" src_grp "${src_grp}")
    string(REPLACE "/" "\\" src_grp "${src_grp}")
    source_group("${src_grp}" FILES "${rel_scr}")
endforeach()

include(FetchContent)

FetchContent_Declare(json
                     GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
                     GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

#target_link_libraries(foo PRIVATE nlohmann_json::nlohmann_json)
# Expose includes
set(PVTPackage_INCLUDE_DIRS ${PROJECT_INC_DIR} CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

set(PVTPackage_target PVTPackage)

set(PVTPackage_headers ${PROJECT_HDR})

set(PVTPackage_sources ${PROJECT_SRC})

#set(PVTPackage_dependencies "")
set(PVTPackage_dependencies nlohmann_json::nlohmann_json)

message("adding PVTPackage library")
blt_add_library(NAME       ${PVTPackage_target}
                SOURCES    ${PVTPackage_sources}
                HEADERS    ${PVTPackage_headers}
                DEPENDS_ON ${PVTPackage_dependencies})

target_include_directories(${PVTPackage_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${PROJECT_SRC_DIR})

	
