#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

/* Жанр */
enum Genre {
    romcom = 1, //Романтическая комедия
    scifi = 2, //Научная фантастика
    horror = 3, //Фильм ужасов
    documentary = 4, //Документальный фильм
    action = 5, //Боевик
    drama = 6 //Драма
};

/* Фильм */
struct Film{
    string name;
    string date;
    int price;
    int genre;
    Film(string name, string date, int price, int genre);
    friend string Genre(Film* film);
};

Film::Film(string name, string date, int genre, int price) : name(name), date(date), genre(genre), price(price) {};

void SplitString(string str, char separator, vector<string>& strings) {
    int startIndex = 0, endIndex = 0;
    for (size_t i = 0; i <= str.size(); i++) {

        // If we reached the end of the word or the end of the input.
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
}

string Genre(int genre){
    switch (genre) {
        case 1: return "Романтическая комедия";
        case 2: return "Научная фантастика";
        case 3: return "Фильм ужасов";
        case 4: return "Документальный фильм";
        case 5: return "Боевик";
        case 6: return "Драма";
        default: throw exception("Неизвестный жанр");
    }
}

string Genre(Film* film) {
    switch (film->genre) {
        case 1: return "Романтическая комедия";
        case 2: return "Научная фантастика";
        case 3: return "Фильм ужасов";
        case 4: return "Документальный фильм";
        case 5: return "Боевик";
        case 6: return "Драма";
        default: throw exception("Неизвестный жанр");
    }

}

int main() {
    setlocale(LC_ALL, "ru");
    
    int count; // Количество фильмов
    cout << "Введите количество фильмов от 1 до 10" << endl;
    while (true) {
          cin >> count;
          if (cin.fail()) { 
              cout << "Неверный ввод" << endl;
              cin.clear();
              cin.ignore();
              continue; 
          }
          if (count < 1 || count > 10) {
            cout << "Количество фильмов должно быть от 1 до 10" << endl;
            continue; 
        }
        break;
     }


    Film** films = new Film*[count];

    int currentIndex = 0;
    string name;
    string date;
    int price;
    int genre;



    while (currentIndex < count){
        cin.clear();
        cin.ignore();
        cout << endl << currentIndex + 1 << "." << endl << "Введите название" << endl;
        getline(cin, name);

        cout << "Жанр:" << endl <<
            "1 - Романтическая комедия" << endl <<
            "2 - Научная фантастика" << endl <<
            "3 - Фильм ужасов" << endl <<
            "4 - Документальный фильм" << endl <<
            "5 - Боевик" << endl <<
            "6 - Драма" << endl;

        while (true) {
            cout << "Введите жанр" << endl;
            cin >> genre;

            if (cin.fail()) {
                cout << "Неверный ввод" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }

            if (genre < 1 || genre > 6) {
                cout << "Жанр:" << endl <<
                    "1 - Романтическая комедия" << endl <<
                    "2 - Научная фантастика" << endl <<
                    "3 - Фильм ужасов" << endl <<
                    "4 - Документальный фильм" << endl <<
                    "5 - Боевик" << endl <<
                    "6 - Драма" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            break;
        }

        cout << "Жанр -- " << Genre(genre) << endl;

        while (true) {
            cout << "Введите дату выхода в формате ДД/ММ/ГГГГ" << endl;
            cin >> date;

            if (!regex_match(date, std::regex(R"((0[1-9]|[12][0-9]|3[01])[/](0[1-9]|1[012])[/](19|20)\d\d)"))) {
                cin.clear();
                cin.ignore();
                cout << "Дата должна быть в формате ДД/ММ/ГГГГ" << endl;
                continue;
            }
            break;
        }


        while (true) {
            cout << "Введите цену" << endl;
            cin >> price;

            if (cin.fail() || price <= 0) {
                cout << "Неверный ввод" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }

            break;
        }
        
        films[currentIndex] = new Film(name, date, genre, price);
        ++currentIndex;
    }

    cout << endl << "Выбранные фильмы" << endl;

    for (int i = 0; i < count; i++) {
        cout << (i + 1) << "." << endl <<
                            "Название: " << films[i]->name << endl << 
                            "Жанр: " << Genre(films[i]) << endl <<
                            "Дата: " << films[i]->date << endl <<
                            "Цена: " << films[i]->price << endl << endl;
    }

    cout << "Выберите параметр поиска:" << endl <<
        "0 -- Год выпуска" << endl <<
        "1 -- Жанр" << endl;
    int searchParam;

    while (true) {
        cin >> searchParam;

        if (cin.fail()) {
            cout << "Неверный ввод" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        if (searchParam < 0 || searchParam > 1) {
            cout << "Неверный ввод" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        break;
    }

    vector<Film*> foundFilms;

    if (searchParam == 0) { // Поиск по году
        string year;
        cout << "Введите год выпуска" << endl;
        cin >> year;

        for (int i = 0; i < count; i++) {
            vector<string> strings;
            SplitString(films[i]->date, '/', strings);
            if (strings[2] == year) {
                foundFilms.push_back(films[i]);
            }
        }

        if (foundFilms.size()) {
            cout << "Количество найденных фильмов: " << foundFilms.size() << endl <<
                    "Год выпуска: " << year << endl;
            int i = 1;
            for (Film* film : foundFilms) {
                    cout << i << "." << endl <<
                        "Название: " << film->name << endl <<
                        "Жанр: " << Genre(film) << endl <<
                        "Дата: " << film->date << endl <<
                        "Цена: " << film->price << endl << endl;
                    ++i;
     
            }
        }else {
            cout << "Фильмы не найдены" << endl;
        }

    }


    if(searchParam == 1) { //Поиск по жанру
        cout << "Жанр:" << endl <<
            "1 - Романтическая комедия" << endl <<
            "2 - Научная фантастика" << endl <<
            "3 - Фильм ужасов" << endl <<
            "4 - Документальный фильм" << endl <<
            "5 - Боевик" << endl <<
            "6 - Драма" << endl;

        while (true) {
            cout << "Введите жанр" << endl;
            cin >> genre;

            if (cin.fail()) {
                cout << "Неверный ввод" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }

            if (genre < 1 || genre > 6) {
                cout << "Жанр:" << endl <<
                    "1 - Романтическая комедия" << endl <<
                    "2 - Научная фантастика" << endl <<
                    "3 - Фильм ужасов" << endl <<
                    "4 - Документальный фильм" << endl <<
                    "5 - Боевик" << endl <<
                    "6 - Драма" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            break;
        }
       
        for (int i = 0; i < count; i++) {
            if (films[i]->genre == genre) {
                foundFilms.push_back(films[i]);
            }
        }
    
        if (foundFilms.size()) {
            cout << "Количество найденных фильмов: " << foundFilms.size() << endl <<
                "Жанр: " << Genre(genre) << endl;
            int i = 1;
            for (Film* film : foundFilms) {
                cout << i << "." << endl <<
                    "Название: " << film->name << endl <<
                    "Жанр: " << Genre(film) << endl <<
                    "Дата: " << film->date << endl <<
                    "Цена: " << film->price << endl << endl;
                ++i;

            }
        }
        else {
            cout << "Фильмы не найдены" << endl;
        }

    }

    cout << "--ЗАВЕРШЕНИЕ ПРОГРАММЫ--" << endl;

    return 0;
}
