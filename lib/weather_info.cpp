#include "weather_info.h"
#include "configparse.h"
#include <string>

#define MORNHOUR 7  // 7AM
#define NOONHOUR 13  // 1PM
#define EVEHOUR 19  // 7PM
#define NIGHTHOUR 23  // 11PM


// получение координат города ч/ API Api-Ninjas
std::pair<double, double> DayWeather::getCoordinates(std::string& city_name, std::string& Api_key) {
    cpr::Response city_response = cpr::Get(cpr::Url{"https://api.api-ninjas.com/v1/city?name=" + city_name},
                                  cpr::Header{{"X-Api-Key", Api_key}});

    if (city_response.status_code == 0) {
        throw std::runtime_error("City response error \n");
    }

    json city_data = json::parse(city_response.text);

    double latitude = city_data[0]["latitude"];
    double longitude = city_data[0]["longitude"];

    return std::make_pair(latitude, longitude);
}


// получение прогноза погоды по координатам ч/ API Open-Meteo
std::vector<DayInfo> DayWeather::getWeatherForecast(std::string& city_name, int days_count, std::string& Api_key) {
    std::pair<double, double> coords = getCoordinates(city_name, Api_key);
    auto latitude = coords.first;
    auto longitude = coords.second;
    cpr::Response weather_response = cpr::Get(cpr::Url{"https://api.open-meteo.com/v1/forecast"},
                                     cpr::Header{{"X-Api-Key", Api_key}},
                                     cpr::Parameters{{"latitude", std::to_string(latitude)},
                                                     {"longitude", std::to_string(longitude)},
                                                     {"forecast_days", std::to_string(days_count)},
                                                     {"hourly", "weathercode"},
                                                     {"hourly", "temperature_2m"},
                                                     {"hourly", "relativehumidity_2m"},
                                                     {"hourly", "windspeed_10m"},
                                                     {"hourly", "winddirection_10m"},
                                                     {"hourly", "visibility"},
                                                     {"hourly", "precipitation"},
                                                     {"hourly", "precipitation_probability"}});

    if (weather_response.status_code == 0) {
        throw std::runtime_error("Weather response error \n");
    }

    json weather_information = json::parse(weather_response.text);

    std::vector<DayInfo> forecast;

    for (int i = 0; i < days_count; ++i) {
        DayInfo new_day;
        std::string date_we_got = weather_information["hourly"]["time"][i * 24];
        new_day.date = date_we_got.substr(0, date_we_got.find("T"));

        new_day.WMO_weather_code[0] = weather_information["hourly"]["weathercode"][i * 24 + MORNHOUR];
        new_day.WMO_weather_code[1] = weather_information["hourly"]["weathercode"][i * 24 + NOONHOUR];
        new_day.WMO_weather_code[2] = weather_information["hourly"]["weathercode"][i * 24 + EVEHOUR];
        new_day.WMO_weather_code[3] = weather_information["hourly"]["weathercode"][i * 24 + NIGHTHOUR];

        new_day.temp[0] = weather_information["hourly"]["temperature_2m"][i * 24 + MORNHOUR];
        new_day.temp[1] = weather_information["hourly"]["temperature_2m"][i * 24 + NOONHOUR];
        new_day.temp[2] = weather_information["hourly"]["temperature_2m"][i * 24 + EVEHOUR];
        new_day.temp[3] = weather_information["hourly"]["temperature_2m"][i * 24 + NIGHTHOUR];

        new_day.wind_speed[0] = weather_information["hourly"]["windspeed_10m"][i * 24 + MORNHOUR];
        new_day.wind_speed[1] = weather_information["hourly"]["windspeed_10m"][i * 24 + NOONHOUR];
        new_day.wind_speed[2] = weather_information["hourly"]["windspeed_10m"][i * 24 + EVEHOUR];
        new_day.wind_speed[3] = weather_information["hourly"]["windspeed_10m"][i * 24 + NIGHTHOUR];

        new_day.wind_direction[0] = weather_information["hourly"]["winddirection_10m"][i * 24 + MORNHOUR];
        new_day.wind_direction[1] = weather_information["hourly"]["winddirection_10m"][i * 24 + NOONHOUR];
        new_day.wind_direction[2] = weather_information["hourly"]["winddirection_10m"][i * 24 + EVEHOUR];
        new_day.wind_direction[3] = weather_information["hourly"]["winddirection_10m"][i * 24 + NIGHTHOUR];

        new_day.visibility[0] = weather_information["hourly"]["visibility"][i * 24 + MORNHOUR];
        new_day.visibility[1] = weather_information["hourly"]["visibility"][i * 24 + NOONHOUR];
        new_day.visibility[2] = weather_information["hourly"]["visibility"][i * 24 + EVEHOUR];
        new_day.visibility[3] = weather_information["hourly"]["visibility"][i * 24 + NIGHTHOUR];

        new_day.precipitation[0] = weather_information["hourly"]["precipitation"][i * 24 + MORNHOUR];
        new_day.precipitation[1] = weather_information["hourly"]["precipitation"][i * 24 + NOONHOUR];
        new_day.precipitation[2] = weather_information["hourly"]["precipitation"][i * 24 + EVEHOUR];
        new_day.precipitation[3] = weather_information["hourly"]["precipitation"][i * 24 + NIGHTHOUR];

        new_day.precipitation_probability[0] = weather_information["hourly"]["precipitation_probability"][i * 24 + MORNHOUR];
        new_day.precipitation_probability[1] = weather_information["hourly"]["precipitation_probability"][i * 24 + NOONHOUR];
        new_day.precipitation_probability[2] = weather_information["hourly"]["precipitation_probability"][i * 24 + EVEHOUR];
        new_day.precipitation_probability[3] = weather_information["hourly"]["precipitation_probability"][i * 24 + NIGHTHOUR];

        new_day.humidity[0] = weather_information["hourly"]["relativehumidity_2m"][i * 24 + MORNHOUR];
        new_day.humidity[1] = weather_information["hourly"]["relativehumidity_2m"][i * 24 + NOONHOUR];
        new_day.humidity[2] = weather_information["hourly"]["relativehumidity_2m"][i * 24 + EVEHOUR];
        new_day.humidity[3] = weather_information["hourly"]["relativehumidity_2m"][i * 24 + NIGHTHOUR];

        forecast.push_back(new_day);
    }

    return forecast;
}
