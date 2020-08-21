
#include <iostream>
#include <string>
#include <vector>


int SockPairs(const std::string& socks)
{
	int numOfPairs = 0;
	char currentSock;
	bool alreadyProcessed = false;
	std::vector<char> processedList;


	for (int i = 0; i < socks.size(); i++)
	{
		alreadyProcessed = false;
		currentSock = socks[i];

		for (auto match : processedList)
		{
			if (match == currentSock)
			{
				alreadyProcessed = true;
			}
		}

		if (alreadyProcessed == false)
		{
			for (int j = 0; j < socks.size(); j++)
			{
				if (socks[j] == currentSock)
				{
					numOfPairs += 1;
					processedList.push_back(currentSock);
				}
			}
		}
	}

	return numOfPairs /2;
}

int main(int argc, char** argv)
{
	std::cout << SockPairs("AA") << std::endl;       // ➞ 1
	std::cout << SockPairs("ABABC") << std::endl;    // ➞ 2
	std::cout << SockPairs("CABBACCC") << std::endl; // ➞ 4
	std::cout << SockPairs("CABBACCCDDEEFF") << std::endl; // ➞ 7
}

