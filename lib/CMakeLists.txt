add_library(weather_info weather_info.cpp weather_info.h)
add_library(configparse configparse.cpp configparse.h)
add_library(appearance appearance.cpp appearance.h)
add_library(system_settings system_settings.cpp system_settings.h)

target_link_libraries (weather_info PRIVATE cpr::cpr)
target_link_libraries(weather_info PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries (configparse PRIVATE cpr::cpr)
target_link_libraries(configparse PRIVATE nlohmann_json::nlohmann_json)

target_link_libraries(appearance
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
)