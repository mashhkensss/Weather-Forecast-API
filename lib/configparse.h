#pragma once

#include <vector>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

class ConfigData {
private:
    int number_of_cities;
    int curr_city;
    std::vector<std::string> list_of_the_cities;
    int number_of_days;
    int freq_of_updating;

public:
    explicit ConfigData(const std::string& config_file);

    int getNumberOfCitites() const;

    std::string getCity();

    int getNumberOfDays() const;

    int getFreqOfUpdating() const;

    void nextCity();

    void prevCity();

    void increaseNumberOfDays();

    void decreaseNumberOfDays();
};

