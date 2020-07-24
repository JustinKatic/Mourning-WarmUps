#include <iostream>
#include <vector>
#include <functional>



int findOdd(std::vector<int> arr)
{
	int i = 0;
	int x = 0;
	int j = 0;

	for (size_t i = 0; i < arr.size(); i++)
	{
		for (size_t i = 0; i < arr.size(); i++)
		{
			if (arr[x] == arr[i])
			{
				j += 1;
			}
		}
		x++;

		if (j % 2 != 0)
		{
			return arr[i];
		}
	}
	
}
int main()
{

	std::vector<int> set1 = { 1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5 };
	std::vector<int> set2 = { 20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5 };
	std::vector<int> set3 = { 10 };

	int number1 = findOdd(set1); // number1 = -1
	int number2 = findOdd(set2); // number2 =  5
	int number3 = findOdd(set3); // number3 =  10

	std::cout << number1 << ", " << number2 << ", " << number3;
}


