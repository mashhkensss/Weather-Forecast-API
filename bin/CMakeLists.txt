add_executable(${PROJECT_NAME} main.cpp)
target_link_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})


target_link_libraries(${PROJECT_NAME} PUBLIC configparse)
target_link_libraries(${PROJECT_NAME} PUBLIC weather_info)
target_link_libraries (${PROJECT_NAME} PRIVATE cpr::cpr)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PRIVATE ncurses)

target_link_libraries(${PROJECT_NAME}
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
)
