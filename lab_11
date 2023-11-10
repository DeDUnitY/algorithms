#include <iostream>
#include <vector>
#include <ctime>

// Функция, выбирающая правильное положение опорного элемента в массиве и разделяющая его на две подгруппы
int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // опорный элемент
    int i = (low - 1); // индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Функция реализующая алгоритм Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); // рекурсивно сортируем элементы перед опорным
        quickSort(arr, pi + 1, high); // рекурсивно сортируем элементы после опорного
    }
}

// Функция для вывода массива на экран
void printArray(std::vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    srand(time(0));
    std::vector<int> nums;
    for (int i = 0; i < 1000; i++) {
        nums.push_back(rand() % 100);
    }
    std::cout << "start vector: ";
    printArray(nums);
    unsigned int start_time = clock();
    quickSort(nums, 0, nums.size() - 1);
    std::cout << clock() - start_time << " ms" << std::endl;
    std::cout << "end vector: ";
    printArray(nums);

    return 0;
}
