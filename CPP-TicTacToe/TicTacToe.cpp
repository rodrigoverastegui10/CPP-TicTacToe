#include "TicTacToe.h"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe()
{
	// Initialize the board with empty spaces
	for (int i = 0; i < 9; ++i)
	{
		m_board[i] = ' ';
	}
	m_currentPlayer = 0; // Player 1 starts
}

bool TicTacToe::IsGameOver() const
{
	int wins[8][3] = {
		{0, 1, 2},{3, 4, 5},{6, 7, 8}, //Rows
		{0, 3, 6},{1, 4, 7},{2, 5, 8}, //Columns
		{0, 4, 8},{2, 4, 6} //Diagonals
	};

	for (auto& win : wins)
	{
		if (m_board[win[0]] != ' ' &&
			m_board[win[0]] == m_board[win[1]] &&
			m_board[win[1]] == m_board[win[2]])
		{
			return true; // A player has won
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		if (m_board[i] == ' ')
		{
			return false; // Game is still going
		}
	
	
	}
}

void TicTacToe::Display() const
{
	system("cls"); // Clear the console (Windows specific)
	cout << "Current board:\n";
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << m_board[i * 3 + j];
			if (j < 2) cout << "|";
		}
		cout << "\n";
		if (i < 2) cout << "-----\n";
	}
}

void TicTacToe::TakeTurn()
{
	int move;
	cout << "Player " << (m_currentPlayer + 1) << ", enter your move (1-9): ";
	cin >> move;
	move = move - 1; // Convert to 0-based index;
	if (move < 0 || move > 8 || m_board[move] != ' ')
	{
		cout << "Invalid move. Try again.\n";
		TakeTurn(); // Retry the turn
	}
	else
	{
		m_board[move] = (m_currentPlayer == 0) ? 'X' : 'O';
		m_currentPlayer = 1 - m_currentPlayer; // Switch players
	}
}



