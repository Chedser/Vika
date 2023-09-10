#include <iostream>
#include <array>
#include <algorithm>
#include <functional>

using namespace std;

/* Перестановка элементов */
template<typename T>void Swap(T* first, T* second, T* third) {
    array<T, 3> arr = { *first, *second, *third };
    std::sort(arr.begin(), arr.end());
    *first = arr[0];
    *second = arr[1];
    *third = arr[2];
}

int main(){
    setlocale(LC_ALL, "ru");
    float first = 3;
    float second = 2;
    float third = 1;

    cout << "Начальные элементы:" << endl;
    cout << "Первый: " << first << endl;
    cout << "Второй: " << second << endl;
    cout << "Третий: " << third << endl;

    cout << endl;
    
    Swap(&first, &second, &third);

    cout << "Конечные элементы:" << endl;
    cout << "Первый: " << first << endl;
    cout << "Второй: " << second << endl;
    cout << "Третий: " << third << endl;
    
    return 0;
}
