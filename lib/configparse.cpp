#include "configparse.h"
#include "appearance.h"
#include "system_settings.cpp"

ConfigData::ConfigData(const std::string& config_file) {
    std::ifstream file(config_file, std::ios::in);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file\n");
    }

    json income_data = json::parse(file);

    number_of_cities = income_data["number_of_cities"];
    number_of_days = income_data["number_of_days"];
    freq_of_updating = income_data["updating_frequency"];
    list_of_the_cities = income_data["cities"];
    curr_city = 0;
}

int ConfigData::getNumberOfCitites() const {
    return number_of_cities;
}

std::string ConfigData::getCity() {
    return list_of_the_cities[curr_city];
}

int ConfigData::getNumberOfDays() const {
    return number_of_days;
}

int ConfigData::getFreqOfUpdating() const {
    return freq_of_updating;
}

void ConfigData::nextCity() {
    ++curr_city;
    if (curr_city == number_of_cities)
        curr_city = 0;

    clearScreen();
}

void ConfigData::prevCity() {
    --curr_city;
    if (curr_city == 0)
        curr_city = number_of_cities - 1;

    clearScreen();
}

void ConfigData::increaseNumberOfDays() {
    ++number_of_days;
    if (number_of_days > 16) {
        std::cout << "You've reached maximum number of days for forecast. \n";
        number_of_days = 16;
    } else {
        clearScreen();
    }
}

void ConfigData::decreaseNumberOfDays() {
    --number_of_days;
    if (number_of_days < 1) {
        std::cout << "There are no more days for ";
        number_of_days = 0;
    } else {
        clearScreen();
    }
}
