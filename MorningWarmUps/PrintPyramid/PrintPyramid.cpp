
#include <iostream>
#include <vector>
#include <string>

void print_pyramid(int height)
{
	if (height > 0)
	{
		for (int i = 1; i <= height; i++)
		{
			for (int j = 0; j < height - i; j++)
			{
				std::cout << " ";
			}
			for (int k = 0; k < i * 2; k++)
			{
				std::cout << "*";
			}
			std::cout << std::endl;
		}
	}
	else if (height < 0)
	{
		height *= -1;
		for (int i = 0; i <= height - 1; i++)
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << ' ';
			}
			for (int j = 0; j < (height - i) * 2; j++)
			{
				std::cout << '*';
			}
			std::cout << std::endl;
		}
	}
}



int main(int argc, char** argv)
{
	std::cout << "=======================================" << std::endl;
	print_pyramid(6);
	std::cout << "=======================================" << std::endl;
	print_pyramid(7);
	std::cout << "=======================================" << std::endl;
	print_pyramid(-1);
	std::cout << "=======================================" << std::endl;
	print_pyramid(-6);

}

