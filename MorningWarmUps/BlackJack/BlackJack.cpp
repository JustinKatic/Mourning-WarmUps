
#include <iostream>
#include <vector>
#include <functional>



bool overTwentyOne(std::vector<char> cards)
{
	int count = 0;
	bool hasAce = false;
	int aceCount = 0;

	for (size_t i = 0; i < cards.size(); i++)
	{
		
		if (cards[i] == 'J' || cards[i] == 'K' || cards[i] == 'Q' )
		{
			count += 10;
		}
		else if (cards[i] == 'A')
		{
			count += 11;
			hasAce = true;
			aceCount += 1;
		}
		else
		{
			count += cards[i] -48;
		}
	}	

	if (count > 21 && hasAce == true)
	{		
		while (aceCount > 0 || count > 21)
		{
			aceCount -= 1;
			if (count <= 21)
			{
				break;
			}
			count -= 10;
		}
	}
	if (count > 21)
	{
		return true;
	}
	return false;
}

int main()
{
	std::vector<char> vec1 = { '2', '8', 'J' };
	std::vector<char> vec2 = { 'A', 'J', 'K' };
	std::vector<char> vec3 = { '5', '5', '3','9' };
	std::vector<char> vec4 = { '2', '6', '4', '4' ,'5' };
	std::vector<char> vec5 = { 'J', 'Q', 'K' };
	std::vector<char> vec6 = { 'A', 'A', '9' };


	std::cout << overTwentyOne(vec1) << std::endl;				// ➞ false
	std::cout << overTwentyOne(vec2) << std::endl;				// ➞ false
	std::cout << overTwentyOne(vec3) << std::endl;				// ➞ true
	std::cout << overTwentyOne(vec4) << std::endl;				// ➞ false
	std::cout << overTwentyOne(vec5) << std::endl;				// ➞ true
	std::cout << overTwentyOne(vec6) << std::endl;				// ➞ false
}

