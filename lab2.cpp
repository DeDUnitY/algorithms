#include <iostream>
#include <stack>
#include <vector>
#include<string>

int main()
{
	setlocale(LC_ALL, "ru");
	std::stack <char> arr;
	std::string str;
	std::cout << "Ââåäèòå ïðèìåð: ";
	std::cin >> str;
	bool error = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') 
		{
			arr.push(str[i]);
		}
		else if ((str[i] == ')' && arr.top() == '(')) 
		{
			arr.pop();
		}
	}
	if (!arr.empty()) 
	{
		error = 1;
		std::cout << "íå êîððåêòíûé ïðèìåð" << "\n";
	}

	std::stack<char> Operator;
	std::vector<std::string> nums;

	std::string tmp = "";
	if (!error) 
	{
		for (int i = 0; i < str.size(); i++) 
		{
			if (48 <= str[i] && str[i] <= 57) 
			{
				tmp += str[i];
			}

			else 
			{

				if (tmp.size() != 0) 
				{
					nums.push_back(tmp);
					tmp = "";
				}

				int n = Operator.size() - 1;
				if (str[i] == '*' || str[i] == '/')
					{

					if (Operator.size() == 0 || Operator.top() == '+' || Operator.top() == '-' || Operator.top() == '(') 
					{
						Operator.push(str[i]);
					}

					else 
					{
						while (Operator.top() == '*' || Operator.top() == '/')
						{
							std::string a = "";
							a += Operator.top();
							nums.push_back(a);
							Operator.pop();
							if (Operator.size() == 0) 
							{
								break;
							}
						}
						Operator.push(str[i]);
					}

				}

				else if (str[i] == '+' || str[i] == '-') 
				{
					if (Operator.size() == 0)
					{
						Operator.push(str[i]);
					}

					else 
					{
						while (Operator.top() == '*' || Operator.top() == '/' || Operator.top() == '+' || Operator.top() == '-') 
						{
							std::string a = "";
							a += Operator.top();
							nums.push_back(a);
							Operator.pop();
							if (Operator.size() == 0)
							{
								break;
							}
						}
						Operator.push(str[i]);
					}
				}

				else if (str[i] == '(') 
				{
					Operator.push(str[i]);
				}

				else if (str[i] == ')') 
				{
					while (Operator.top() != '(') 
					{
						std::string a = "";
						a += Operator.top();
						nums.push_back(a);
						Operator.pop();
						if (Operator.size() == 0)
						{
							break;
						}
					}
					Operator.pop();
				}

				else if (str[i] == '=') 
				{
					while (Operator.size() != 0) 
					{
						std::string a = "";
						a += Operator.top();
						nums.push_back(a);
						Operator.pop();
					}
				}

				else 
				{
					error = 1;
					std::cout << "íåêêîðåêòíûé ñèìâîë" << "\n";
					break;
				}

			}


		}
	}
	std::vector <double> conclusion;
	if (!error) 
	{
		for (int i = 0; i < nums.size(); i++) 
		{
			if (48 <= nums[i][0] && nums[i][0] <= 57) 
			{
				conclusion.push_back(std::stod(nums[i]));
			}
			else
			{
				double a = conclusion[conclusion.size() - 1];
				double b = conclusion[conclusion.size() - 2];
				double result;
				switch (nums[i][0])
				{
				case'*':
					result = a * b;
					break;
				case'/':
					if (a == 0)
					{
						error = 1;
						std::cout << "äåëåíèå íà 0" << "\n";
						break;
					}
					result = b / a;
					break;
				case '+':
					result = a + b;
					break;
				case'-':
					result = b - a;
					break;
				}
				conclusion.pop_back();
				conclusion.pop_back();
				conclusion.push_back(result);
			}
		}
	}

	if (!error) {
		std::cout << str << conclusion[0] << "\n";
	}

	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << " ";
	}

}
