#pragma once  
#include "Game.h"  

class TicTacToe : public Game  
{  
private:  
   char m_board[9]; // Add this declaration to define m_board  
   int m_currentPlayer;  

   char GetBoardValue(int index) const  
   {  
       return m_board[index];  
   }  
   int GetCurrentPlayer() const {  
       return m_currentPlayer;  
   }  

public:  
   TicTacToe();  

   bool IsGameOver() const override;  
   void Display() const override;  
   void TakeTurn() override;  
};
