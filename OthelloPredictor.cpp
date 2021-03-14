/*
Program Name: Othello Project
Programmer Name: Johnathan Khalil
Date: 2/15/19
*/

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Board {

	char board[8][8]; // each square holds 'b', 'w', or ' '

public:
	Board() //makes all spaces on the board blank
	{
		for (int c = 0; c <= 7; c++)
		{
			for (int v = 0; v <= 7; v++)
			{
				board[c][v] = ' ';
			}
		}
	}
	void set(int row, int col, char color) //sets the color to the respective place on the board
	{
		board[row - 1][col - 1] = color;
	} 

	int count(char color) //counts the number of disks on the board of the color passed
	{
		int count = 0;

		for (int i = 0; i <= 7; i++)
		{
			for (int j = 0; j <= 7; j++)
			{
				if (board[i][j] == color)
				{
					count++;
				}
			}
		}

		return count;
	}

	int resultOfMove(int row, int col, char color) 
	{
		char flip;
		int flipped = 0;
		int num = 0;
		int count;

		if (color == 'b') //compares white if black
		{
			flip = 'w';
		}
		else if (color == 'w') //compares black if white
		{
			flip = 'b';
		}
		else
		{
			cout << "No color to place on the board" << endl;
		}

		do //check up
		{
			count = num + 1;
			if (board[row + count][col] == flip)
			{
				num++;
			}
			else if (board[row + count][col] == ' ')
			{
				num = 0;
			}
			else if (board[row + count][col] == color)
			{
				flipped += num;
				num = 0;
			}
			else
			{
				num = 0;
			}
		} while (num != 0);

		do //check down
		{
			count = num + 1;
			if (board[row - count][col] == flip)
			{
				num++;
			}
			else if (board[row - count][col] == ' ')
			{
				num = 0;
			}
			else if (board[row - count][col] == color)
			{
				flipped += num;
				num = 0;
			}
			else
			{
				num = 0;
			}
		} while (num != 0);

		do //check right
		{
			count = num + 1;
			if (board[row][col + count] == flip)
			{
				num++;
			}
			else if (board[row][col + count] == ' ')
			{
				num = 0;
			}
			else if (board[row][col + count] == color)
			{
				flipped += num;
				num = 0;
			}
			else
			{
				num = 0;
			}
		} while (num != 0);

		do //check left
		{
			count = num + 1;
			if (board[row][col - count] == flip)
			{
				num++;
			}
			else if (board[row][col - count] == ' ')
			{
				num = 0;
			}
			else if (board[row][col - count] == color)
			{
				flipped += num;
				num = 0;
			}
			else
			{
				num = 0;
			}
		} while (num != 0);

		do //check diagonal up right
		{
			count = num + 1;
			if (board[row + count][col + count] == flip)
			{
				num++;
			}
			else if (board[row + count][col + count] == ' ')
			{
				num = 0;
			}
			else if (board[row + count][col + count] == color)
			{
				flipped += num;
				num = 0;
			}
			else
			{
				num = 0;
			}
		} while (num != 0);

		do //check diagonal up left
		{
			count = num + 1;
			if (board[row + count][col - count] == flip)
			{
				num++;
			}
			else if (board[row + count][col - count] == ' ')
			{
				num = 0;
			}
			else if (board[row + count][col - count] == color)
			{
				flipped += num;
				num = 0;
			}
			else
			{
				num = 0;
			}
		} while (num != 0);

		do //check diagonal down right
		{
			count = num + 1;
			if (board[row - count][col + count] == flip)
			{
				num++;
			}
			else if (board[row - count][col + count] == ' ')
			{
				num = 0;
			}
			else if (board[row - count][col + count] == color)
			{
				flipped += num;
				num = 0;
			}
			else
			{
				num = 0;
			}
		} while (num != 0);

		do //check diagonal down left
		{
			count = num + 1;
			if (board[row - count][col - count] == flip)
			{
				num++;
			}
			else if (board[row - count][col - count] == ' ')
			{
				num = 0;
			}
			else if (board[row - count][col - count] == color)
			{
				flipped += num;
				num = 0;
			}
			else
			{
				num = 0;
			}
		} while (num != 0);
		
		return flipped;
	}
	void flip(int row, int col, char color)
	{
		int x = row;
		int y = col;
		board[row][col] = color;
		
		
		while(board[x + 1][y] == 'b')
		{
			board[x + 1][y] = 'w';
			x++;
		}
		

		while (board[x - 1][y] == 'b')
		{
			board[x - 1][y] = 'w';
			x--;
		}
		

		while (board[x][y + 1] == 'b')
		{
			board[x][y + 1] = 'w';
			y++;
		}

		while (board[x][y - 1] == 'b')
		{
			board[x][y - 1] = 'w';
			y--;
		}

		while (board[x + 1][y + 1] == 'b')
		{
			board[x + 1][y + 1] = 'w';
			x++;
			y++;
		}
		x = row;
		y = col;

		while (board[x + 1][y - 1] == 'b')
		{
			board[x + 1][y - 1] = 'w';
			x++;
			x--;
		}
		x = row;
		y = col;

		while (board[x - 1][y + 1] == 'b')
		{
			board[x - 1][y + 1] = 'w';
			x--;
			y++;
		}
		x = row;
		y = col;

		while (board[x - 1][y - 1] == 'b')
		{
			board[x - 1][y - 1] = 'w';
			x--;
			y--;
		}
		x = row;
		y = col;

	}

	int bestMove(int &row, int &col, char color) //alters the x and y values to be that for the best possible move
	{
		int max = 0;
		int count = 0;
		int x;
		int y;

		for (int i=0; i <=7; i++)
		{
			for (int j = 0; j <= 7; j++)
			{	
				count = resultOfMove(i, j, color);
				if (max < count) //compares the total number of disks flipped at each space
				{
					max = count;
					row = i; //alters the x coordinate in main
					col = j; //alters the y coordinate in main
				}
				else if (max == count) //if they are equal, use the smaller row and column
				{
					if (row < i)
					{
						row = row;
					}
					if (col < j)
					{
						col = col;
					}
				}
			}
		}

		return max;
	}
};

int main()
{
	int n; //white
	int m; //black

	int x;
	int y;

	char white = 'w';
	char black = 'b';

	cout << "Welcome to the Othello Move Predictor" << endl;
	cout << endl;

	Board othello;
	
	cout << "Please enter the number of white disks on the board" << endl;
	cin >> n;
	if (n < 0 || n > 64) // check boundaries for number of white 
	{
		cout << "Error, invalid number of white disks entered" << endl;
		cout << "Please enter the number of white disks on the board" << endl;
		cin >> n;
	}

	cout << "Please enter the number of black disks on the board" << endl;
	cin >> m;
	if (m < 0 || m > 64) // check boundaries for number of black 
	{
		cout << "Error, invalid number of black disks entered" << endl;
		cout << "Please enter the number of black disks on the board" << endl;
		cin >> m;
	}

	for (int i = 1; i <= n; i++) //places each white disk on the board
	{
		cout << "Please enter the xy coordinates for the white disk(s) using a space to seperate the values" << endl;
		cin >> x >> y;
		if ((x > 8 || x < 0) || (y > 8 || y < 0))
		{
			cout << "Error, invalid value for coordinates entered" << endl;
			cout << "Please enter the xy coordinates for the white disk(s) using a space to seperate the values" << endl;
			cin >> x >> y;
		}
		cout << endl;
		othello.set(x, y, white);
	}

	for (int j = 1; j <= m; j++) //places each black disk on the board
	{
		cout << "Please enter the xy coordinates for the black disk(s) using a space to seperate the values" << endl;
		cin >> x >> y;
		if ((x > 8 || x< 0) || (y > 8 || y < 0))
		{
			cout << "Error, invalid value for coordinates entered" << endl;
			cout << "Please enter the xy coordinates for the black disk(s) using a space to seperate the values" << endl;
			cin >> x >> y;
		}
		cout << endl;
		othello.set(x, y, black);
	}

	othello.bestMove(x, y, white);
	othello.flip(x, y, white);


	int numWhite = othello.count(white);       //total number of white disks on board
	int numBlack = othello.count(black);       //total number of black disks on board
	int difference = numWhite - numBlack;      //final difference in number of disks
	x = x + 1;    //adds back to value before array to get original coordinate point for x
	y = y + 1;    //adds back to value before array to get original coordinate point for y
	
	
	cout << x << " " << y << " " << difference << endl;
	cout << "Thank you for using this program made by Johnathan Khalil" << endl;
	system("Pause");
	return 0;
}
