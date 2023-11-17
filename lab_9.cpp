#include <iostream>
#include <vector>
#include <ctime>

// Функция для преобразования в max-кучу (поддержание свойства пирамиды)
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // Индекс левого потомка
    int right = 2 * i + 2; // Индекс правого потомка

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый потомок больше, чем самый большой элемент на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если самый большой элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция для сортировки пирамидальной
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Построение (преобразование в max-кучу) массива
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Извлекаем элементы из кучи по одному
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);

        // Вызываем функцию heapify на уменьшенной куче
        heapify(arr, i, 0);
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
    heapSort(nums);
    std::cout << clock() - start_time << " ms" << std::endl;
    std::cout << "end vector: ";
    printArray(nums);

    return 0;
}
