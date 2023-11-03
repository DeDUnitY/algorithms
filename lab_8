#include <iostream>
#include <vector>
#include <ctime>

void print_vector(std::vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}
// Функция для нахождения максимального числа в массиве
int findMax(std::vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];}
    }
    return max;
}

// Функция поразрядной сортировки по определенному разряду (exp)
void countingSort(std::vector<int>& arr, int exp) {
    const int radix = 10; // Основание системы счисления
    std::vector<int> output(arr.size());
    std::vector<int> count(radix, 0);

    // Подсчет количества элементов с одинаковыми разрядами
    for (int i = 0; i < arr.size(); i++) {
    count[(arr[i] / exp) % radix]++;
}

    // Изменение count[i] так, чтобы count[i] содержал актуальное
    // положение данного разряда в output
    for (int i = 1; i < radix; i++) {
    count[i] += count[i - 1];
 }

    // Создание отсортированного массива (output)
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }

    // Копирование отсортированного массива обратно в исходный
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// Функция для поразрядной сортировки
void radixSort(std::vector<int>& arr) {
    // Находим максимальное число в массиве для определения количества разрядов
    int max = findMax(arr);

    // Проводим сортировку для каждого разряда, начиная с младшего
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    srand(time(0));
    std::vector<int> arr;
	for (int i = 0; i < 100; i++) {
		arr.push_back(rand()%1000);
	}
    unsigned int start_time = clock();
    radixSort(arr);
    std::cout << clock() - start_time << " ms" <<std::endl;

    print_vector(arr);

    return 0;
}
