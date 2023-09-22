// TicTac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool CheckHorizontalWin(char* Board,char Turn)
{
	int ThreeInLine = 0;
	for (int i = 0; i < 9; i++)
	{
		if (Board[i] == Turn)
		{
			if (!(i % 3)) ThreeInLine = 0;

			ThreeInLine++;

			if (ThreeInLine == 3)
			{
				std::cout << Turn << " Horizontal win" << std::endl;
				return true;
			}
		}
		else ThreeInLine = 0;
	}
	return false;
}

bool CheckVerticalWin(char* Board, char Turn)
{
	for (int i = 0; i < 3; i++)
	{
		if (Board[i] == Turn && Board[i + 3] == Turn && Board[i + 6] == Turn)
		{
			std::cout << Turn << " Vertical win" << std::endl;
			return true;
		}
	}
	return false;
}

bool CheckCruzWin(char* Board, char Turn)
{
	if (Board[0] == Turn && Board[4] == Turn && Board[8] == Turn)
	{
		std::cout << Turn << " Cruz Win" << std::endl;
		return true;
	}
		

	if (Board[2] == Turn && Board[4] == Turn && Board[6] == Turn) 
	{
		std::cout << Turn << "Cruz Win" << std::endl;
		return true;
	}

	return false;
}

bool CheckWin(char* Board, char Turn)
{
	return (CheckHorizontalWin(Board, Turn) || CheckVerticalWin(Board, Turn) || CheckCruzWin(Board, Turn));
}

int NewPosition()
{
	int position = 0;
	while (!(position > 0 && position < 10))
	{
		std::cout << "To play introduce 1 number between 1 to 9" << std::endl;
		std::cin >> position;

	}
	return position;
}

void PrintBoard(char* Board, int position, char Turn)
{
	if (Board[position - 1] == '-')
		Board[position - 1] = Turn;
	else
	{
		std::cout << "Already used space" << std::endl;
		PrintBoard(Board, NewPosition(), Turn);
		return;
	}
		

	for (int i = 0; i < 9; i++)
	{
		if (i % 3 || i == 0)
			std::cout << Board[i];
		else 
			std::cout << std::endl << Board[i];
	}
	std::cout << std::endl;
}

void GameLoop(char& Board, char &Turn)
{
	if (Turn == 'X') Turn = 'O';
	else Turn = 'X';

	
	PrintBoard(&Board, NewPosition(), Turn);

}

int main()
{
	char Turn = 'X';
	char Board[9] = { '-','-','-','-','-','-','-','-','-' };

	while (!CheckWin(Board, Turn))
	{
		GameLoop(*Board, Turn);
	}
	std::cin;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
