
#include <iostream>
#include<vector>
#include <string>

std::vector<std::string> splitGroups(std::string s) 
{
	std::vector<std::string> result;
	std::string substring;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == s[i + 1])
		{
			substring.push_back(s[i]);
		}

		else
		{
			substring.push_back(s[i]);
			result.push_back(substring);
			substring.clear();
		}
	}
	return result;
}

void PrintOutput(std::vector<std::string> result)
{
	for (auto& w : result) 
	{
		std::cout << w << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> result;
	result = splitGroups("555"); //["555"]
	PrintOutput(result);

	result = splitGroups("5556667788"); //["555", "666", "77", "88"]
	PrintOutput(result);

	result = splitGroups("aaabbbaabbab"); //["aaa", "bbb", "aa", "bb", "a", "b"]
	PrintOutput(result);

	result = splitGroups("abbbcc88999&&!!!_"); //["a", "bbb", "cc", "88", "999", "&&", "!!!", "_"]
	PrintOutput(result);
}


