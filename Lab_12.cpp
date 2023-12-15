#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void Qsort(int* arr, int begin, int end)
{
    int i = begin;
    int j = end;
    int mid_element = arr[(end + begin) / 2];

    while (i <= j)
    {

        while (arr[i] < mid_element)
        {
            i++;
        }

        while (arr[j] > mid_element)
        {
            j--;
        }
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);

            i++;
            j--;
        }
    }

    if (i < end)
    {
        Qsort(arr, i, end);
    }

    if (j >= begin)
    {
        Qsort(arr, begin, j);
    }
}



void Mult_sort(std::string input_path, std::string output_path, unsigned int free_mem)
{
    std::ifstream input(input_path);
    std::ofstream output(output_path, std::ios::app);
    std::ofstream temp;
    int size = free_mem;
    int* arr = new int[size];
    int i = 0;
    int count = 0;

    if (input.is_open())
    {
        while (!input.eof())
        {
            input >> arr[i++];

            if (i == size)
            {
                Qsort(arr, 0, i - 1);

                temp.open("temp" + std::to_string(count) + ".txt", std::ios::app);
                for (int j = 0; j < i; j++)
                {
                    temp << arr[j];
                    if (j < i - 1)
                    {
                        temp << "\n";
                    }
                }
                count++;
                i = 0;
                temp.close();
            }
        }
    }
    input.close();
    delete[] arr;


    int min = 10000000;
    int num = 0;
    bool flag = true;
    int n = 0;
    while (flag)
    {
        flag = false;
        int* arr = new int[size];

        for (int j = 0; j <= count - 1; j++)
        {
            std::ifstream temp;
            temp.open("temp" + std::to_string(j) + ".txt");

            if (temp.peek() == EOF)
            {
                continue;
            }

            int tmp;
            temp >> tmp;

            if (tmp <= min)
            {
                flag = true;
                min = tmp;
                num = j;
                while (!temp.eof())
                {
                    temp >> arr[i++];
                }
                n = i;
            }
            i = 0;
            temp.close();
        }

        if (min != 10000000)
        {
            output << min << "\n";
            output.flush();
        }

        std::ofstream temp;
        temp.open("temp" + std::to_string(num) + ".txt");
        while (i < n)
        {
            temp << arr[i++];
            if (i < n)
            {
                temp << "\n";
            }
        }
        i = 0;
        min = 10000000;
        temp.close();
        delete[] arr;
       
    }
    output.close();
}

int main()
{
    int n;
    std::cin >> n;
    std::ofstream input("input.txt");

    for (int i = 0; i < n; i++)
    {
        input << rand() % n + 1;
        if (i != n - 1)
        {
            input << "\n";
        }
    }

    input.close();

    Mult_sort("input.txt", "output.txt", 4);
}
