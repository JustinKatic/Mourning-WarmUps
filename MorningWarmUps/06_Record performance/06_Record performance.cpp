#include <iostream>
#include <chrono>

int DoSomeLongRunningThing()
{
	int counter = 0;
	for (int i = 0; i < 9000; i++)
	{
		std::cout << " " << std::endl;
		counter += 1;
	}
	return counter;
}

  

int main(int argc, char** argv)
{
	auto startTime = std::chrono::high_resolution_clock::now();
	std::cout << "Hello World" << std::endl;
	auto endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeDiff = endTime - startTime;

	

	startTime = std::chrono::high_resolution_clock::now();
	DoSomeLongRunningThing();
	endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeDiff1 = endTime - startTime;

	std::cout << "first function: "<< timeDiff.count() << std::endl;
	std::cout << "second function: " << timeDiff1.count() << std::endl;

}