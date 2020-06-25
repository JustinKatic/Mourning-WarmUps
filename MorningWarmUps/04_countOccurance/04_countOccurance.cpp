#include <iostream>
#include <string>

int CountOccurances(const std::string& phrase, const std::string& searchTerm)
{
	if (phrase.empty() || searchTerm.empty())
	{
		return 0;
	}
	int count = 0;
	int pos = 0;

	while ((pos = phrase.find(searchTerm, pos)) != -1)
	{
		pos += 1;
		count++;
	}
	return count;
}
int main(int argc, char** argv)
{
	std::string phrase1 = "the quick brown fox jumps over the lazy dog";
	std::string phrase2 = "hello world";
	std::string phrase3 = "aaaaaaaaaaa";
	std::cout << CountOccurances(phrase1, "the") << std::endl;  // -> 2
	std::cout << CountOccurances(phrase1, "o") << std::endl;    // -> 4
	std::cout << CountOccurances(phrase2, "l") << std::endl;    // -> 3
	std::cout << CountOccurances(phrase2, "ll") << std::endl;   // -> 1
	std::cout << CountOccurances(phrase3, "aaa") << std::endl;  // -> 9
	std::cout << CountOccurances(phrase3, "a") << std::endl;    // -> 11
	std::cout << CountOccurances(phrase3, "") << std::endl;   // -> 0
	std::cout << CountOccurances("", "a") << std::endl;   // -> 0
	std::cout << CountOccurances("", "") << std::endl;    // -> ????
	return 0;
}