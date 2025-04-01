cmake_minimum_required(VERSION 3.12)

project(
        weather_app
        VERSION 1.0
        DESCRIPTION "C++ Weather Forecast"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# Declare and fetch CPR
FetchContent_Declare(
        cpr
        GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 742fb6f1a5ed40efe8f3a994e0559c6aff52f2d7
)
FetchContent_MakeAvailable(cpr)

# Declare and fetch JSON
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG 0457de21cffb298c22b629e538036bfeb96130b7
)
FetchContent_MakeAvailable(nlohmann_json)

# Declare and fetch FTXUI
FetchContent_Declare(
        ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
        GIT_TAG 898b8d672ef2cea386048b79276db26867997bae
)
FetchContent_MakeAvailable(ftxui)

add_subdirectory(lib)
add_subdirectory(bin)
