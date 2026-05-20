cmake_minimum_required(VERSION 3.15)
project(Glyphix LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE ALL_SOURCES
    "sources/*.cpp"
    "letters/*.cpp"
)

add_executable(glyphix ${ALL_SOURCES})

if (EMSCRIPTEN)
    target_link_options(glyphix PRIVATE
        "--no-entry"
        "-sMODULARIZE=1"
        "-sEXPORT_ES6=1"
        "-sEXPORTED_RUNTIME_METHODS=['stringToNewUTF8','UTF8ToString']"
        "-sEXPORTED_FUNCTIONS=['_run_glyphix','_free_json']"
    )
endif()

# set_target_properties(glyphix PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
# )
