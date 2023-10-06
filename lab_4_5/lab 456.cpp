#include <iostream>
#include <vector>
#include <ctime>

void print_vector(std::vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void rascheska(std::vector<int> _nums) 
{
	double scale_factor = 1.247;
	int step = _nums.size() - 1;

	while (step >= 1)
	{
		for (int i = 0; i + step < _nums.size(); i++)
		{
			if (_nums[i] > _nums[i + step])
			{
				std::swap(_nums[i], _nums[i + step]);
			}
		}
		step /= scale_factor;
		if (step == 10 or step == 9) step = 11;
	}
	//print_vector(_nums);
}

void Vstavki(std::vector<int> _nums) {
	for (int i = 1; i < _nums.size(); i++) {
		for (int j = i; j > 0 && _nums[j - 1] > _nums[j]; j--) {
			int tmp = _nums[j - 1];
			_nums[j - 1] = _nums[j];
			_nums[j] = tmp;
		}
	}
	//print_vector(_nums);
}

int main()
{
	srand(time(0));
	std::vector<int> nums;
	for (int i = 0; i < 10000; i++) {
		nums.push_back(rand());
	}
	unsigned int start_time = clock();
	rascheska(nums);
	std::cout << clock() - start_time << " ms" << std::endl;
	start_time = clock();
	Vstavki(nums);
	std::cout << clock() - start_time << " ms" << std::endl;
	return 0;
}
