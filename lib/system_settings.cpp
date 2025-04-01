#include "system_settings.h"
#include <curl/curl.h>

bool InternetConectionIsOk() {
    CURL *curl = curl_easy_init();
    if (curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1); // Не нужно тело ответа, только проверка соединения
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10); // Таймаут на соединение

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            return true;
        }
    }
    return false;
}

void clearScreen() {
#if defined(_WIN32) || defined(_WIN64) // For Windows
    system("cls");
#else
    system("clear"); // For Unix (Linux, macOS)
#endif
}
