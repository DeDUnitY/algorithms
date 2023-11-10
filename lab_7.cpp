#include <iostream>
#include <vector>
#include <ctime>

void print_vector(std::vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void shell(std::vector<int> array) {
	unsigned int start_time = clock();
	for (int s = array.size() / 2; s > 0; s /= 2) { 
	    for (int i = s; i < array.size(); ++i) { 
	        for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) { 
	            std::swap(array[j], array[j+s]);}}}
	std::cout << clock() - start_time << " ms" <<std::endl;
    print_vector(array);
}

int main()
{
	srand(time(0));
	std::vector<int> nums;
	for (int i = 0; i < 10; i++) {
		nums.push_back(rand()%100);
	}
	vibor(nums);
	
	return 0;
}
