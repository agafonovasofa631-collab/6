//#include <iostream>
//using namespace std;
//
//// Задача 1: Факториал числа (n!)
//
//long long factorial(int n) {
//    // Базовый случай (условие выхода из рекурсии):
//    
//    if (n <= 1) {
//        return 1;
//    }
//
//    // Рекурсивный шаг: 
//    // Мы умножаем текущее число n на факториал предыдущего числа (n - 1).
//    return n * factorial(n - 1);
//}
//
//// Задача 2: Числа Фибоначчи
//// Каждое число равно сумме двух предыдущих. 
//
//int fibonacci(int n) {
//    // Базовые случаи (первые два числа последовательности известны заранее):
//    if (n == 0) {
//        return 0;
//    }
//    if (n == 1) {
//        return 1;
//    }
//
//    // Рекурсивный шаг: 
//    // Число под индексом n — это сумма чисел под индексами (n-1) и (n-2).
//    return fibonacci(n - 1) + fibonacci(n - 2);
//}
//
//// Задача 3: Сумма цифр числа
//
//int sumOfDigits(int n) {
//    // Базовый случай: 
//    // Если число стало равно 0, значит мы "разобрали" его до конца.
//    if (n == 0) {
//        return 0;
//    }
//
//    // Рекурсивный шаг:
//    // n % 10 — дает нам последнюю цифру числа (остаток от деления на 10).
//    // n / 10 — отбрасывает последнюю цифру (целочисленное деление на 10).
//    // Мы прибавляем последнюю цифру к сумме цифр "обрезанного" числа.
//    return (n % 10) + sumOfDigits(n / 10);
//}
//
//// Задача 4: Степень числа (a^n)
//
//long long power(int a, int n) {
//    // Базовый случай: 
//    // Любое число в степени 0 равно 1.
//    if (n == 0) {
//        return 1;
//    }
//
//    // Рекурсивный шаг:
//    // Число 'a' в степени 'n' — это 'a', умноженное на 'a' в степени (n-1).
//    return a * power(a, n - 1);
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    cout << "Задача 1: факториал" << endl;
//    int n_fact = 5;
//    cout << n_fact << "! = " << factorial(n_fact) << endl;
//    cout << "10! = " << factorial(10) << endl;
//    cout << endl;
//
//    cout << "Задача 2: числа фибоначчи" << endl;
//    int n_fib = 7;
//    cout << "Число Фибоначчи под индексом " << n_fib << " = " << fibonacci(n_fib) << endl;
//    cout << "Первые 10 чисел Фибоначчи: ";
//    for (int i = 0; i < 10; i++) {
//        cout << fibonacci(i) << " ";
//    }
//    cout << endl << endl;
//
//    cout << "Задача 3: сумма цифр числа " << endl;
//    int number = 9875;
//    cout << "Сумма цифр числа " << number << " = " << sumOfDigits(number) << endl;
//    cout << "Сумма цифр числа 1002 = " << sumOfDigits(1002) << endl;
//    cout << endl;
//
//    cout << "Задача 4: степень числа" << endl;
//    int base = 2;
//    int exp = 10;
//    cout << base << " в степени " << exp << " = " << power(base, exp) << endl;
//    cout << "3 в степени 4 = " << power(3, 4) << endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <chrono>   
#include <random>   
#include <iomanip>  

using namespace std;
using namespace chrono;

// 1. Сортировка пузырьком (Bubble Sort)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Флаг оптимизации (если обменов не было — массив отсортирован)

        // Проходим по неотсортированной части массива
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Меняем местами
                swapped = true;
            }
        }
        // Если за проход ни одного обмена не произошло, массив уже отсортирован
        if (!swapped) break;
    }
}

// 2 Сортировка вставками (Insertion Sort)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Запоминаем текущий элемент
        int j = i - 1;

        // Сдвигаем элементы, которые больше key, на одну позицию вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Ставим key на освободившееся место
        arr[j + 1] = key;
    }
}

// 3 Сортировка выбором (Selection Sort)

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Предполагаем, что минимальный — это первый в неотсорт. части

        // Ищем реальный минимум в оставшейся части
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Если нашли минимум не на текущем месте, меняем их местами
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Генерация случайного массива
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    // Инициализируем генератор случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100000); // Числа от 1 до 100 000

    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}


int main() {
    setlocale(LC_ALL, "Russian");

    const int SIZE = 10000;
    cout << "Генерация случайного массива из " << SIZE << " элементов " << endl;

    // Генерируем один исходный массив
    vector<int> original = generateRandomArray(SIZE);

    // Делаем копии исходного массива для каждой сортировки, 
    // чтобы они сортировали одинаковые данные
    vector<int> arr1 = original;
    vector<int> arr2 = original;
    vector<int> arr3 = original;

    cout << "Начинаем замеры производительности\n" << endl;

    // 1. Замер пузырьковой сортировки 
    auto start1 = high_resolution_clock::now();
    bubbleSort(arr1);
    auto end1 = high_resolution_clock::now();
    auto time1 = duration_cast<milliseconds>(end1 - start1).count();

    // 2. Замер сортировки вставками 
    auto start2 = high_resolution_clock::now();
    insertionSort(arr2);
    auto end2 = high_resolution_clock::now();
    auto time2 = duration_cast<milliseconds>(end2 - start2).count();

    // 3. Замер сортировки выбором 
    auto start3 = high_resolution_clock::now();
    selectionSort(arr3);
    auto end3 = high_resolution_clock::now();
    auto time3 = duration_cast<milliseconds>(end3 - start3).count();

    cout << "--------------------------------------------------" << endl;
    cout << "| Алгоритм сортировки | Время выполнения (мс) |" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "| Пузырьковая         | " << setw(21) << time1 << " |" << endl;
    cout << "| Вставками           | " << setw(21) << time2 << " |" << endl;
    cout << "| Выбором             | " << setw(21) << time3 << " |" << endl;
    cout << "--------------------------------------------------" << endl;

    return 0;
}