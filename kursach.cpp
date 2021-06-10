#define CURL_STATICLIB
#include<string>
#include<iostream>
#include<vector>
#include<fstream>

#include<curl\curl.h>
#include<nlohmann/json.hpp>

/*
curl_easy_setopt - Устанавливает параметр для curl easy handle
ПАРАМЕТРЫ:
CURLOPT_WRITEFUNCTION - Эта функция вызывается в Libcurl, как только есть полученные данные, которые должны быть сохранены.
CURLOPT_WRITEDATA - записывает данные в поток FILE*, получая указатель из CURLOPT_WRITEFUNCTION
*/

static size_t write_data(char* ptr, size_t size, size_t nmemb, std::string* data)//функция для записи
/*
char * ptr — указатель на принимаемые данные(содержание страницы).
size_t(unsigned int) size — размер принимамого блока данных(size = 1)
size_t nmemb — общее количество блоков данных(количество байт).
string* data — это параметр опции CURLOPT_WRITEDATA, в который производится запись — наш буфер.
*/
{
    if (data)
    {
        data->append(ptr, size * nmemb);//метод класса string(добавляет к строке data данные из ptr)
        return size * nmemb; //Функция должна возвращать количество обработанных байт (size* nmemb)
    }
    else
        return 0;  // будет ошибка
}


int main()
{
    setlocale(LC_ALL, "ru");
    int iVybor = 0;			//переменная, куда запишется выбор пользователя
    std::string sKodGoroda;	//переменная, куда запишется код города, выбранного пользователем
    std::string content;	//переменная, куда запишется результат

    std::cout << "1  - London" << "\n";
    std::cout << "2  - Washington" << "\n";
    std::cout << "3  - Moscow" << "\n";
    std::cout << "4  - Saint Petersburg" << "\n";
    std::cout << "5  - Paris" << "\n";
    std::cout << "6  - Budapest" << "\n";
    std::cout << "7  - Berlin" << "\n";
    std::cout << "8  - Munich" << "\n";
    std::cout << "9  - Prague" << "\n";
    std::cout << "10 - Lviv" << "\n";
    std::cout << "11 - Mogilëv" << "\n";
    std::cout << "12 - Minsk" << "\n";
    std::cout << "13 - Ufa" << "\n";
    std::cout << "14 - Tokyo" << "\n";
    std::cout << "15 - Beijing" << "\n";
    std::cout << "16 - Rio de Janeiro" << "\n";
    std::cout << "17 - Rybinsk" << "\n";
    std::cout << "18 - Brussels" << "\n";
    std::cout << "19 - New York City" << "\n";
    std::cout << "20 - Austin" << "\n\n";

    std::cout << "Введите номер города и нажите Enter : ";

    std::cin >> iVybor;
    switch (iVybor) {
    case 1: sKodGoroda = "2643743";		// 1 - London
        break;
    case 2: sKodGoroda = "4880731";		// 2 - Washington
        break;
    case 3: sKodGoroda = "524901";		// 3 - Moscow
        break;
    case 4: sKodGoroda = "498817";		// 4 - Saint Petersburg
        break;
    case 5: sKodGoroda = "2968815";		// 5 - Paris
        break;
    case 6: sKodGoroda = "3054638";		// 6 - Budapest
        break;
    case 7: sKodGoroda = "2950158";		// 7 - Berlin
        break;
    case 8: sKodGoroda = "2867714";		// 8 - Munich
        break;
    case 9: sKodGoroda = "3067696";		// 9 - Prague
        break;
    case 10: sKodGoroda = "702550";		// 10 - Lviv
        break;
    case 11: sKodGoroda = "700924";		// 11 - Mogilëv
        break;
    case 12: sKodGoroda = "625144";		// 12 - Minsk
        break;
    case 13: sKodGoroda = "479561";		// 13 - Ufa
        break;
    case 14: sKodGoroda = "1850147";	// 14 - Tokyo
        break;
    case 15: sKodGoroda = "1816670";	// 15 - Beijing
        break;
    case 16: sKodGoroda = "3451189";	// 16 - Rio de Janeiro
        break;
    case 17: sKodGoroda = "500004";		// 17 - Rybinsk
        break;
    case 18: sKodGoroda = "2800866";	// 18 - Brussels
        break;
    case 19: sKodGoroda = "5128581";	// 19 - New York City
        break;
    case 20: sKodGoroda = "5016884";	// 20 - Austin
        break;
    }

    if (iVybor <= 20)
    {
        std::cout << "Вы выбрали " << iVybor << " ( " << sKodGoroda << ") \n\n";
    }
    else
    {
        std::cout << "введите число из списка!" << std::endl;
        exit(0);
    }
    

    CURL* curl_handle;
    curl_handle = curl_easy_init();//инициализация  
    nlohmann::json objJson;

    //std::cin >> city;

    if (curl_handle)
    {
        //curl_easy_setopt(curl_handle, CURLOPT_URL, sZapros);
        //curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=498817&appid=b14a922e9650b7e5050eb0a92ff20dcb");

        std::ofstream fout;
        fout.open("Json2.json");

        switch (iVybor)
        {
        case 1: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=2643743&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 1 - London
            break;
        case 2: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=4880731&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 2 - Washington
            break;
        case 3: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=524901&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 3 - Moscow
            break;
        case 4: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=498817&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 4 - Saint Petersburg
            break;
        case 5: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=2968815&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 5 - Paris
            break;
        case 6: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=3054638&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 6 - Budapest
            break;
        case 7: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=2950158&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 7 - Berlin
            break;
        case 8: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=2867714&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 8 - Munich
            break;
        case 9: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=3067696&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 9 - Prague
            break;
        case 10: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=702550&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 10 - Lviv
            break;
        case 11: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=700924&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 11 - Mogilëv
            break;
        case 12: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=625144&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 12 - Minsk
            break;
        case 13: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=479561&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 13 - Ufa
            break;
        case 14: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=1850147&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");	// 14 - Tokyo
            break;
        case 15: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=1816670&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");	// 15 - Beijing
            break;
        case 16: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=3451189&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");	// 16 - Rio de Janeiro
            break;
        case 17: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=500004&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");		// 17 - Rybinsk
            break;
        case 18: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=2800866&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");	// 18 - Brussels
            break;
        case 19: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=5128581&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");	// 19 - New York City
            break;
        case 20: curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=5016884&units=metric&appid=b14a922e9650b7e5050eb0a92ff20dcb");	// 20 - Austin
            break; 
        }
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &content);

        CURLcode res = curl_easy_perform(curl_handle);	//Эта функция вызывается после инициализации и всех вызовов curl_easy_setopt 
        //std::cout << content << std::endl;
        if (!fout.is_open())
        {
            std::cout << "File error";
        }
        else
        {
            fout << content;
        }
        std::cerr << curl_easy_strerror(res) << std::endl;

        curl_easy_cleanup(curl_handle);//отчистка
        fout.close();
    }

    std::fstream fileInput;
    fileInput.open("Json2.json");
    fileInput >> objJson;
    fileInput.close();
    std::string city_name = objJson["name"];
    float temp = objJson["main"]["temp"];
    float temp_max = objJson["main"]["temp_max"];
    float temp_min = objJson["main"]["temp_min"];
    int pressure = objJson["main"]["pressure"];
    int humidity = objJson["main"]["humidity"];
    float wind = objJson["wind"]["speed"];

    std::cout << "weather in " << city_name << "" << '\n';
    std::cout << "current temperature: " << ceil(temp) << "°C" << '\n';
    std::cout << "max temperature: " << ceil(temp_max) << "°C" << '\n';
    std::cout << "min temperature: " << ceil(temp_min) << "°C" << '\n';
    std::cout << "humidity: " << humidity << "%" << '\n';
    std::cout << "pressure: " << pressure << "Pa" << '\n';
    std::cout << "wind speed: " << wind << "m/s" << '\n';

    return 0;
}
