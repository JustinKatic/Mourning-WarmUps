#include <iostream>
#include <vector>

typedef std::vector<std::vector<char>> OthelloBoardState;


bool IsValidMove(char player, int x, int y, const OthelloBoardState& grid)
{
	// It is assumed that 'grid' will have exactily 8x8 rows/cols
	// TODO: calculate if a given coordinate is a valid move.
	bool opposite = false;
	if (grid[y][x] != ' ')
	{
		return false;
	}

	char other;
	if (player == 'B')
	{
		other = 'W';
	}
	else
	{
		other = 'B';
	}


	//RIGHT CHECK
	for (int xi = x + 1; xi < 8; xi++)
	{
		if (grid[y][xi] == other)
		{
			opposite = true;
			continue;
		}
		if (grid[y][xi] == ' ')
		{
			break;
		}
		if (grid[y][xi] == player && opposite == true)
		{
			return true;
		}

	}
	opposite = false;
	//LEFT CHECK
	for (int xi = x - 1; xi > 0; xi--)
	{
		if (grid[y][xi] == other)
		{
			opposite = true;
			continue;
		}
		if (grid[y][xi] == ' ')
		{
			break;
		}
		if (grid[y][xi] == player && opposite == true)
		{
			return true;
		}
	}
	opposite = false;
	//UP CHECK
	for (int yi = y + 1; yi < 8; yi++)
	{
		if (grid[yi][x] == other)
		{
			opposite = true;
			continue;
		}
		if (grid[yi][x] == ' ')
		{
			break;
		}
		if (grid[yi][x] == player && opposite == true)
		{
			return true;
		}
	}
	opposite = false;
	//DOWN CHECK
	for (int yi = y - 1; yi > 0; yi--)
	{
		if (grid[yi][x] == other)
		{
			opposite = true;
			continue;
		}
		if (grid[yi][x] == ' ')
		{
			break;
		}
		if (grid[yi][x] == player && opposite == true)
		{
			return true;
		}
	}
	opposite = false;
	//TOP LEFT
	for (int i = 1; i < 8; i++)
	{
		int xi = x - i;
		int yi = y - i;

		if (xi < 0 || xi >= 8 || yi < 0 || yi >= 8)
			break;

		if (grid[yi][xi] == other)
		{
			opposite = true;
			continue;
		}

		if (grid[yi][xi] == ' ')
		{
			break;
		}

		if (grid[yi][xi] == player && opposite == true)
		{
			return true;
		}
	}
	opposite = false;
	//TOP RIGHT
	for (int i = 1; i < 8; i++)
	{
		int xi = x + i;
		int yi = y - i;

		if (xi < 0 || xi >= 8 || yi < 0 || yi >= 8)
			break;

		if (grid[yi][xi] == other)
		{
			opposite = true;
			continue;
		}

		if (grid[yi][xi] == ' ')
		{
			break;
		}

		if (grid[yi][xi] == player && opposite == true)
		{
			return true;
		}
	}
	opposite = false;
	//BOTTOM RIGHT
	for (int i = 1; i < 8; i++)
	{
		int xi = x + i;
		int yi = y + i;

		if (xi < 0 || xi >= 8 || yi < 0 || yi >= 8)
		{
			break;
		}

		if (grid[yi][xi] == other)
		{
			opposite = true;
			continue;
		}

		if (grid[yi][xi] == ' ')
		{
			break;
		}

		if (grid[yi][xi] == player && opposite == true)
		{ 
			return true;
		}
	}
	opposite = false;
	//BOTTOM LEFT
	for (int i = 1; i < 8; i++)
	{
		int xi = x - i;
		int yi = y + i;

		if (xi < 0 || xi >= 8 || yi < 0 || yi >= 8)
		{
			break;
		}

		if (grid[yi][xi] == other)
		{
			opposite = true;
			continue;
		}

		if (grid[yi][xi] == ' ')
		{
			break;
		}

		if (grid[yi][xi] == player && opposite == true)
		{
			return true;
		}
	}
	return false;
}

//  the given coordinate must adhere to the rules of othello for 
//  determining if the move is valid


OthelloBoardState MakeMove(char player, int x, int y, OthelloBoardState grid)
{
	// if the move was not valid, just return the origional...
	if (IsValidMove(player, x, y, grid) == false)
		return grid;
	// TODO: This is optionan, but gitve it a go if you have time ;)
	// update 'grid' so that the approprate tiles have been flipped.
	return grid;
}

int main(int argc, char** argv)
{
	OthelloBoardState state1 =
	{//   0    1    2    3    4    5    6    7 
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 1
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 2
		{' ', ' ', ' ', 'W', 'B', ' ', ' ', ' '}, // 3
		{' ', ' ', ' ', 'B', 'W', ' ', ' ', ' '}, // 4
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
	};											 
	auto ShouldBe = [](auto result, auto expected) {
		std::cout << (result == expected ? "\033[32m [PASS]" : "\033[31m [FAIL]") << "\033[0m" << std::endl;
	};
	ShouldBe(IsValidMove('B', 5, 4, state1), true); // true
	ShouldBe(IsValidMove('B', 2, 4, state1), false); // false
	ShouldBe(IsValidMove('B', 3, 2, state1), true); // true
	ShouldBe(IsValidMove('B', 3, 5, state1), false); // false
	ShouldBe(IsValidMove('B', 5, 5, state1), false); // false
	ShouldBe(IsValidMove('W', 5, 4, state1), false); // false
	ShouldBe(IsValidMove('W', 2, 4, state1), true); // true
	ShouldBe(IsValidMove('W', 3, 2, state1), false); // false
	ShouldBe(IsValidMove('W', 3, 5, state1), true); // true
	ShouldBe(IsValidMove('W', 5, 5, state1), false); // false

	OthelloBoardState state2 =
	{//   0    1    2    3    4    5    6    7
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
		{' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '}, // 1
		{' ', ' ', 'B', 'W', ' ', ' ', ' ', ' '}, // 2
		{' ', ' ', 'B', 'W', 'B', ' ', ' ', ' '}, // 3
		{' ', ' ', 'W', 'W', 'W', ' ', ' ', ' '}, // 4
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
	};

	ShouldBe(IsValidMove('B', 2, 5, state2), true); // true
	ShouldBe(IsValidMove('B', 3, 5, state2), false); // false
	ShouldBe(IsValidMove('B', 4, 5, state2), true); // true
	ShouldBe(IsValidMove('B', 3, 1, state2), false); // false
	ShouldBe(IsValidMove('B', 4, 2, state2), true); // true
	ShouldBe(IsValidMove('B', 4, 1, state2), true); // true

	ShouldBe(IsValidMove('W', 2, 5, state2), false); // false
	ShouldBe(IsValidMove('W', 2, 0, state2), true); // true
	ShouldBe(IsValidMove('W', 3, 1, state2), false); // false
	return 0;
}