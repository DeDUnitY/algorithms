void vibor(std::vector<int> _nums) {
	unsigned int start_time = clock();
	for (int i = 0; i < _nums.size() - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < _nums.size(); j++)
		{
			if (_nums[j] < _nums[min_index])
				min_index = j;
		}
		if (min_index != i)
			std::swap(_nums[i], _nums[min_index]);
	}
	std::cout << clock() - start_time << " ms" << std::endl;
}

int main()
{
	srand(time(0));
	std::vector<int> nums;
	for (int i = 0; i < 10000; i++) {
		nums.push_back(rand());
	}
	vibor(nums);
	
	return 0;
}
