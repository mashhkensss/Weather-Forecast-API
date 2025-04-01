#include <iostream>
#include <string>
#include <vector>

#undef border

#include <ftxui/dom/elements.hpp>  // for text, operator|, vbox, border, Element, Fit, hbox
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator
#include "ftxui/dom/node.hpp"      // for Render
#include <sstream>

#include "appearance.h"
#include "weather_info.h"
#include "configparse.h"

void Printer::printHeader() {
    std::cout << "                    _   _                  __                             _   \n"
                 "                   | | | |                / _|                           | |  \n"
                 "__      _____  __ _| |_| |__   ___ _ __  | |_ ___  _ __ ___  ___ __ _ ___| |_ \n"
                 "\\ \\ /\\ / / _ \\/ _` | __| '_ \\ / _ \\ '__| |  _/ _ \\| '__/ _ \\/ __/ _` / __| __|\n"
                 " \\ V  V /  __/ (_| | |_| | | |  __/ |    | || (_) | | |  __/ (_| (_| \\__ \\ |_ \n"
                 "  \\_/\\_/ \\___|\\__,_|\\__|_| |_|\\___|_|    |_| \\___/|_|  \\___|\\___\\__,_|___/\\__|\n"
                 "                                                                              \n"
                 "                                                                              " << std::endl;

}

std::vector<std::string> splitStringIntoLines(const std::string& str) {
    std::vector<std::string> lines;
    std::istringstream stream(str);
    std::string line;

    while (std::getline(stream, line)) {
        lines.push_back(line);
    }

    return lines;
}

void Printer::printForecast(int number_of_days_for_forecast, std::string& city, std::string& Api_key) {
    std::vector<DayInfo> forecast = DayWeather::getWeatherForecast(city, number_of_days_for_forecast, Api_key);
    Printer::printHeader();

    std::cout << city << std::endl;

    std::vector<ftxui::Element> days_elements;

    for (int i = 0; i < number_of_days_for_forecast; ++i) {
        auto date_element = ftxui::hbox({ ftxui::text(forecast[i].date) | ftxui::border | ftxui::center | ftxui::flex });

        std::vector<ftxui::Element> day_parts_elements;

        for (int j = 0; j < DAYPARTS; ++j) {

            auto weatherPictureLines = splitStringIntoLines(Assets::getWeatherArt(forecast[i].WMO_weather_code[j]));
            std::vector<ftxui::Element> pictureElements;
            for (const auto& line : weatherPictureLines) {
                pictureElements.push_back(ftxui::text(line));
            }

            auto day_part = ftxui::vbox({
                                                ftxui::text("[" + Assets::getDayPart(j) + "]"),
                                                ftxui::text(Assets::getWeatherType(forecast[i].WMO_weather_code[j])),
                                                ftxui::vbox(pictureElements),
                                                ftxui::text("Temperature: " + std::to_string(forecast[i].temp[j]) + "°C"),
                                                ftxui::text("Wind: " + Assets::getWindDirection(
                                                        forecast[i].wind_direction[j]) + " " + std::to_string(forecast[i].wind_speed[j]) + "km/h"),
                                                ftxui::text("Humidity: " + std::to_string(forecast[i].humidity[j]) + "%"),
                                                ftxui::text("Visibility: " + std::to_string(forecast[i].visibility[j] / 1000) + "km"),
                                                ftxui::text("Precipitation: " + std::to_string(forecast[i].precipitation[j] / 100) + "mm"),
                                                ftxui::text("Precipitation probability: " + std::to_string(forecast[i].precipitation_probability[j]) + "%")
                                        }) | ftxui::border | ftxui::flex;

            day_parts_elements.push_back(day_part);
        }
        auto day_container = ftxui::hbox(day_parts_elements);

        days_elements.push_back(ftxui::vbox({date_element, day_container}));
    }

    auto main_container = ftxui::vbox(days_elements) | ftxui::border;

    auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(main_container));
    ftxui::Render(screen, main_container);
    screen.Print();
}

