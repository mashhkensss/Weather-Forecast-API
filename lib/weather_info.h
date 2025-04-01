#pragma once

#ifdef  OK
#undef	OK
#endif

#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include "configparse.h"

using json = nlohmann::json;

#define DAYPARTS 4 // morn, day, even & night

struct DayInfo {
    std::string city_name;
    std::string daypart;
    std::string date;

    int* WMO_weather_code = new int[DAYPARTS];
    int* temp = new int[DAYPARTS];
    int* wind_speed = new int[DAYPARTS];
    int* wind_direction = new int[DAYPARTS];
    int* visibility = new int[DAYPARTS];
    double* precipitation = new double[DAYPARTS];
    int* precipitation_probability = new int[DAYPARTS];
    int* humidity = new int[DAYPARTS];


    DayInfo() {
        for (int i = 0; i < DAYPARTS; ++i) {
            WMO_weather_code[i] = -1;
            temp[i] = -273;
            wind_speed[i] = -1;
            wind_direction[i] = -1;
            visibility[i] = -1;
            precipitation[i] = -1;
            precipitation_probability[i] = -1;
            humidity[i] = -1;
        }
    }

    ~DayInfo() = default;

};

namespace DayWeather {
    std::pair<double, double> getCoordinates(std::string& city_name, std::string& Api_key);

    std::vector<DayInfo> getWeatherForecast(std::string& city_name, int days_count, std::string& Api_key);
};
