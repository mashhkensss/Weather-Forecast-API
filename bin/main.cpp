#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <ncurses.h>
#include "../lib/system_settings.cpp"
#include "../lib/weather_info.h"
#include "../lib/appearance.cpp"

void run(ConfigData& data_to_use, std::string& Api_Key) {
    clock_t start_time = clock();

    while (true) {
        if ((clock() - start_time) / CLOCKS_PER_SEC > data_to_use.getFreqOfUpdating()) {
            endwin();
            system("clear");
            std::string city = data_to_use.getCity();
            Printer::printForecast(data_to_use.getNumberOfDays(), city, Api_Key);
            start_time = clock();
            initscr();
            cbreak();
            noecho();
            keypad(stdscr, TRUE);
        }
    }
};


int main(int argc, char** argv) {
    // Info
    std::cout << "Application info: \n"
                 "To switch between cities, press 'n'(next) or 'p'(previous) \n"
                 "To change number of days for forecast press '+' or '-' \n"
                 "To quit the program press 'Esc'" << std::endl;

    // Checking Api Key input & working with it;
    std::string Api_key;

    if (argc == 1) {
        std::cout << "Enter the API-Key: ";
        std::getline(std::cin, Api_key);
        if (Api_key.empty()) {
            throw std::runtime_error("API-Key was not entered.");
        }
    } else {
        Api_key = argv[1];
    }

    clearScreen();

    // Opening config & working with it;
    std::string config_path;
    std::cout << "Enter path to your config-file: " << std::endl;
    std::getline(std::cin, config_path);
    ConfigData data_to_use(config_path);

    std::string city = data_to_use.getCity();

    if (InternetConectionIsOk()) {
        Printer::printForecast(data_to_use.getNumberOfDays(), city, Api_key);
    } else {
        std::cout << "No internet connection :( \n"
                     "Try again later." << std::endl;
    }

    std::thread weather_update_thread([&]() {
        run(data_to_use, Api_key);
    });

    // Working w/ user
    noecho(); // Не отображать вводимые символы
    cbreak();   // Отключить буферизацию строк, получать символы сразу
    initscr();
    keypad(stdscr, TRUE); // Включить поддержку функциональных клавиш

    int key_pressed;
    bool is_working = true;
    while (is_working) {
        key_pressed = getch();
        endwin();
        switch (key_pressed) {
            case '+':
                data_to_use.increaseNumberOfDays();
                Printer::printForecast(data_to_use.getNumberOfDays(), city, Api_key);
                break;
            case '-':
                data_to_use.decreaseNumberOfDays();
                Printer::printForecast(data_to_use.getNumberOfDays(), city, Api_key);
                break;
            case 'n':
                data_to_use.nextCity();
                Printer::printForecast(data_to_use.getNumberOfDays(), city, Api_key);
                break;
            case 'p':
                data_to_use.prevCity();
                Printer::printForecast(data_to_use.getNumberOfDays(), city, Api_key);
                break;
            case 27:
                is_working = false;
                break;
            default:
                break;
        }
        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
    }

    weather_update_thread.detach();
    endwin();

    return 0;
}
