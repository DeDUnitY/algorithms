#include <iostream>
#include <stack>

bool check_brackets(std::string str) {
	std::stack<char> brackets;
	if (str[0] == ')' || str[0] == ']' || str[0] == '}')
		return false;
	else
		for (int i = 0; i < str.size(); i++) {
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
	std::string str;
	std::cout << "Input string:\n";
	std::cin >> str;
	if (check_brackets(str))
		std::cout << "String maybe real"; 
	else
		std::cout << "String not real";
}
