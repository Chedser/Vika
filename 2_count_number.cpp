#include <iostream>
#include <time.h>
using namespace std;

// Функция генерирования случайного целочисленного числа в указанных пределах.
// Диапазон чисел: [min, max]
int GetRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

template<typename T> int CountOfNumber(T* x, int i, T numberToFind) {
    if (i < 0) return 0; // выход из рекурсии, когда проверены все элементы
    int n = 0;
    if (x[i] > numberToFind) n = 1;  // если больше, то засчитываем
    return n + CountOfNumber(x, i - 1, numberToFind); // суммируем засчитанные элементы
}

int main() {
    setlocale(LC_ALL, "ru");

    const int COUNT = 20;
    int arr[COUNT];
    int numberToFind;

    srand(time(NULL));
    /* Заполнение массива случайными числами */
    for (int i = 0; i < COUNT; i++) {
        arr[i] = GetRandomNumber(1, 9);
    }

    cout << "Массив из случайных чисел" << endl;

    /* Вывод массива */
    for (int i = 0; i < COUNT; i++) {
        cout << arr[i] << endl;
    }

    cout << endl;
    cout << "Введите число:" << endl;

    cin >> numberToFind;
    cout << endl;

    if (cin.good()) {
        cout << "Количество чисел больших " << numberToFind << ": " << CountOfNumber(arr, COUNT - 1, numberToFind) << endl;
    }
    else {
        cout << "Ошибка ввода";
    }

    return 0;
}
