#pragma once

#include <string>
#include "weather_info.h"

namespace Assets{
    std::string getWeatherType(int weather_code) {
        std::map<int, std::string> weatherMap = {
                {0,  "Clear sky"},
                {1,  "Mainly clear"},
                {2,  "Partly cloudy"},
                {3,  "Overcast"},
                {45, "Fog"},
                {48, "Depositing rime fog"},
                {51, "Light intensity drizzle"},
                {53, "Moderate intensity drizzle"},
                {55, "Denze intensity drizzle"},
                {56, "Light freezing drizzle"},
                {57, "Denze freezing drizzle"},
                {61, "Slight rain"},
                {63, "Moderate rain"},
                {65, "Heavy rain"},
                {66, "Light intensity freeze rain"},
                {67, "Heavy intensity freeze rain"},
                {71, "Slight intensity snow fall"},
                {73, "Moderate intensity snow fall"},
                {75, "Heavy intensity snow fall"},
                {77, "Snow grains"},
                {80, "Slight rain showers"},
                {81, "Moderate rain showers"},
                {82, "Violent rain showers"},
                {85, "Slight snow showers"},
                {86, "Heavy snow showers"},
                {95, "Thunderstorm"},
                {96, "Thunderstorm with light hail"},
                {99, "Thunderstorm with heavy hail"}
        };

        return weatherMap[weather_code];
    }
    std::string getWeatherArt(int weather_code) {
        std::map<int, std::string> weatherArtMap = {
                {0,  "    \\   /    \n"
                     "     .--.     \n"
                     " -― (    ) –- \n"
                     "     `--'     \n"
                     "    /   \\    \n"},
                {1,  "    \\   /    \n"
                     "     .--.     \n"
                     " -― (    ) –- \n"
                     "     `--'     \n"
                     "    /   \\    \n"},
                {2,  "             \n"
                     "     .--.    \n"
                     "  .-(    ).  \n"
                     " (___.__)__) \n"
                     "             \n"},
                {3,  "             \n"
                     "     .--.    \n"
                     "  .-(    ).  \n"
                     " (___.__)__) \n"
                     "             \n"},
                {45, "             \n"
                     " _ - _ - _ - \n"
                     "  _ - _ - _  \n"
                     " _ - _ - _ - \n"
                     "             \n"},
                {48, "             \n"
                     " _ - _ - _ - \n"
                     "  _ - _ - _  \n"
                     " _ - _ - _ - \n"
                     "             \n"},
                {51, " _`/\"\".-.  \n"
                     "  ,\\_(   ). \n"
                     "   /(___(__) \n"
                     "     ‘   ‘   \n"
                     "   ‘   ‘   ‘ \n"},
                {53, " _`/\"\".-.  \n"
                     "  ,\\_(   ). \n"
                     "   /(___(__) \n"
                     "     ‘ ‘ ‘ ‘ \n"
                     "    ‘ ‘ ‘ ‘  \n"},
                {55, " _`/\"\".-.  \n"
                     "  ,\\_(   ). \n"
                     "   /(___(__) \n"
                     "     ‘ ‘ ‘ ‘ \n"
                     "    ‘ ‘ ‘ ‘ ‘\n"},
                {56, " _`/\"\".-.  \n"
                     "  ,\\_(   ). \n"
                     "   /(___(__) \n"
                     "     ‘ * ‘ ‘ \n"
                     "    ‘ * ‘ *  \n"},
                {57, " _`/\"\".-.  \n"
                     "  ,\\_(   ). \n"
                     "   /(___(__) \n"
                     "     ‘ * ‘ * \n"
                     "  * ‘ * ‘ *  \n"},
                {61, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "    ‘   ‘    \n"
                     "  ‚  ’  ‚ ’  \n"},
                {63, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "   ‚ ‘ ‚ ‘   \n"
                     "    ‚ ’ ‚ ’  \n"},
                {65, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "   ‚‘‚‘‚‘‚‘  \n"
                     "  ‚’‚’‚’‚’   \n"},
                {66, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "   ‚ * ‚ ‘   \n"
                     "    * ’ ‚ *  \n"},
                {67, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "   ‘ * ‘ *   \n"
                     "  * ’ * ’ * ’\n"},
                {71, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "     *   *   \n"
                     "  *    *     \n"},
                {73, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "    *   *    \n"
                     "  *   *   *  \n"},
                {75, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "   * * * *   \n"
                     "  * * * * *  \n"},
                {77, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "     *   *   \n"
                     "   *   *   * \n"},
                {80, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "    ‘   ‘    \n"
                     "  ‚  ’  ‚ ’  \n"},
                {81, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "   ‚ ‘ ‚ ‘   \n"
                     "    ‚ ’ ‚ ’  \n"},
                {82, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "  ‚‘‚‘‚‘‚‘   \n"
                     "  ‚’‚’‚’‚’   \n"},
                {85, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "    *   *    \n"
                     "  *   *   *  \n"},
                {86, "     .-.     \n"
                     "    (   ).   \n"
                     "   (___(__)  \n"
                     "   * * * *   \n"
                     "  * * * * *  \n"},
                {95, "      .-.    \n"
                     "     (   ).  \n"
                     "    (___(__) \n"
                     "      ⚡  ⚡   \n"
                     "    ⚡  ⚡  ⚡  \n"},
                {96, "      .-.    \n"
                     "     (   ).  \n"
                     "    (___(__) \n"
                     "     *   ⚡   \n"
                     "    ⚡  *  ⚡  \n"},
                {99, "      .-.    \n"
                     "     (   ).  \n"
                     "    (___(__) \n"
                     "     * ⚡ *   \n"
                     "    ⚡  *  ⚡  \n"}
        };

        return weatherArtMap[weather_code];
    }
    std::string getWindDirection(int wind_degree) {
        if ((wind_degree >= 0 && wind_degree < 45) || (wind_degree > 315 && wind_degree <= 360))
            return "\u2191";
        if (wind_degree == 45)
            return "\u2197";
        if (wind_degree > 45 && wind_degree < 135)
            return "\u2192";
        if (wind_degree == 135)
            return "\u2198";
        if (wind_degree > 135 && wind_degree < 225)
            return "\u2193";
        if (wind_degree == 225)
            return "\u2199";
        if (wind_degree > 225 && wind_degree < 315)
            return "\u2190";
        if (wind_degree == 315)
            return "\u2196";

        return "?";
    };

    std::string getDayPart(int partNum){
        switch (partNum) {
            case 0:
                return "Morning";
            case 1:
                return "Day";
            case 2:
                return "Evening";
            case 3:
                return "Night";
        }
    }
};

namespace Printer{
    void printForecast(int number_of_days_for_forecast, std::string& city, std::string& Api_key);

    void printHeader();
};
