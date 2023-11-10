#include <iostream>
#include <vector>

// Функция для слияния двух подмассивов
void merge(std::vector<int> &arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Создаем временные массивы
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Слияние временных массивов обратно в arr[left..right]
    int i = 0; // Индекс первого подмассива
    int j = 0; // Индекс второго подмассива
    int k = left; // Индекс отсортированного подмассива
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L, если они есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R, если они есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Функция для сортировки слиянием
void mergeSort(std::vector<int> &arr, int left, int right) {
    if (left < right) {
        // Находим среднюю точку
        int middle = left + (right - left) / 2;

        // Рекурсивно сортируем первую и вторую половины
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Слияние сортированных половин
        merge(arr, left, middle, right);
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
    mergeSort(nums, 0, nums.size() - 1);
    std::cout << clock() - start_time << " ms" << std::endl;
    std::cout << "end vector: ";
    printArray(nums);

    return 0;
}
