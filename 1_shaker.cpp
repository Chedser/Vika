#include <iostream>

using std::cout;
using std::endl;


// Направление сортировки
enum class  Direction {
    Ascending,
    Descending
};

/* Печать массива */
template<typename T> void Print(T* arr, const int count) {
    for (int i = 0; i < count; i++) {
        cout << arr[i] << endl;
    }
}

/* Функция Шейкер - сортировки */
template<typename T> void ShakerSort(T* arr, int count, Direction dir = Direction::Ascending){
    int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
    int flag = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // и пока в массиве имеются перемещения
    if (dir == Direction::Ascending) { //  по возрастанию
        while ((left < right) && flag > 0) {
            flag = 0;
            for (int i = left; i < right; i++)  //двигаемся слева направо{
                // если следующий элемент меньше текущего,
                if (arr[i] > arr[i + 1]) {             // меняем их местами
                    T t = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = t;
                    flag = 1;      // перемещения в этом цикле были
                }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
          //двигаемся справа налево
        for (int i = right; i > left; i--) {
            // если предыдущий элемент больше текущего,
            if (arr[i - 1] > arr[i]) {
                // меняем их местами
                T t = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = t;
                flag = 1;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }else { // по убыванию
        while ((left < right) && flag > 0) {
            flag = 0;
            for (int i = left; i < right; i++)  //двигаемся слева направо{
                // если следующий элемент больше текущего,
                if (arr[i] < arr[i + 1]) {             // меняем их местами
                    T t = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = t;
                    flag = 1;      // перемещения в этом цикле были
                }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
          //двигаемся справа налево
        for (int i = right; i > left; i--) {
            // если предыдущий элемент меньше текущего,
            if (arr[i - 1] < arr[i]) {
                // меняем их местами
                T t = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = t;
                flag = 1;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    const int COUNT = 7;
    double arr[] = {4, 7, 1, 8, 7, 3, 9};

    cout << "Элементы массива:" << endl;
    Print(arr, COUNT);
    cout << endl;

    ShakerSort(arr, COUNT); // Сортировка по возрастанию
    cout << "По возрастанию:" << endl;
    Print(arr, COUNT);
    cout << endl;

    ShakerSort(arr, COUNT, Direction::Descending); // Сортировка по убыванию
    cout << "По убыванию:" << endl;
    Print(arr, COUNT);

    return 0;
}
