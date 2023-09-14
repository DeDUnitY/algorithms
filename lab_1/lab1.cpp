#include <iostream>
#include <stack>
#include <set>

bool check_brackets(std::string str) {
	std::stack<char> brackets;
	std::set<char> a { '(', ')', '{', '}', '[', ']' };
	if (str[0] == ')' || str[0] == ']' || str[0] == '}')
		return false;
	else
		for (int i = 0; i < str.size(); i++) {
			if (a.count(str[i])==1)
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
				brackets.push(str[i]);
			else
				if (!brackets.empty()) {
					if ((str[i] == ')' && brackets.top() == '(') || (str[i] == ']' && brackets.top() == '[') || (str[i] == '}' && brackets.top() == '{'))
						brackets.pop();
				}
				else {
					return false;
				}
		}

	if (brackets.empty())
		return true;
	else
		return false;
}


int main()
{
	setlocale(LC_ALL, "ru");
	std::string str;
	std::cout << "Введите строку:\n";
	std::cin >> str;
	if (check_brackets(str))
		std::cout << "Строка существует"; 
	else
		std::cout << "Строка не существует";
}
