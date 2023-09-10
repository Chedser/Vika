#include <iostream>

using namespace std;

/* Печать массива */
template<typename T> void Print(T* arr, const int count) {
    for (int i = 0; i < count; i++) {
        cout << arr[i] << endl;
    }
}

int GetRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}


template<typename T> void SwapArray(T* arr, int n){
    T temp;
    for (int i = 0; i < n; i += 2){
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    const int COUNT = 20;
    int arr[COUNT];

    srand(time(NULL));
    /* Заполнение массива случайными числами */
    for (int i = 0; i < COUNT; i++) {
        arr[i] = GetRandomNumber(1, 9);
    }

    cout << "Элементы массива до перестановки:";
    Print(arr, COUNT);

    SwapArray(arr, COUNT);
    cout << endl;
    cout << "Элементы массива после перестановки:" << endl;
    Print(arr, COUNT);

    return 0;
}
