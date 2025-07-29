#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ChessBoard.h"

Piece *ChessBoard::gameBoard[8][8];
ChessBoard *ChessBoard::instance = nullptr;

ChessBoard::ChessBoard() {
          // Initialize all positions to nullptr or set up the board as needed
          for (int i = 0; i < 8; ++i) {
               for (int j = 0; j < 8; ++j) {
                    gameBoard[i][j] = nullptr;
               }
          }
          // You can add piece initialization here if needed
		  initializeBoard();
		  instance = this; // Set the singleton instance
}

ChessBoard* ChessBoard::getInstance()
{
     // Return the singleton instance of ChessBoard

	if (instance == nullptr) {
        instance = new ChessBoard();
    }
    return instance;
}

vector<string> ChessBoard::getMoveHistory(int prevMoves)
{
    // Placeholder for move history retrieval
    return vector<string>();
}

void ChessBoard::updateBoard(int* move)
{
	//uses the move class to update the game board
	//use Move class to convert the move into a format that can be used to update the game board
}

bool ChessBoard::swap(int* move)
{
	return false;
}

Piece* ChessBoard::getGameBoard(int row, int col) {
	if (row < 0 || row >= 8 || col < 0 || col >= 8) {
    	return nullptr; // Out of bounds
  	}
  	return gameBoard[row][col];
}

void ChessBoard::setGameBoard(int row, int col, Piece* piece) {
 if (row < 0 || row >= 8 || col < 0 || col >= 8) {
	 return; // Out of bounds
   }
   gameBoard[row][col] = piece;
}

void ChessBoard::initializeBoard() {
    // Initialize the game board with pieces
    // Example: Set up pawns, rooks, knights, etc.
	// This is just a placeholder; you would need to create actual Piece objects

	gameBoard[0][0] = new Piece('b', 'r'); // Black rook
 	gameBoard[0][1] = new Piece('b', 'n'); // Black knight
 	gameBoard[0][2] = new Piece('b', 'b'); // Black bishop
 	gameBoard[0][3] = new Piece('b', 'q'); // Black queen
	gameBoard[0][4] = new Piece('b', 'k'); // Black king
	gameBoard[0][5] = new Piece('b', 'b'); // Black bishop
	gameBoard[0][6] = new Piece('b', 'n'); // Black knight
	gameBoard[0][7] = new Piece('b', 'r'); // Black rook

	for (int i = 0; i < 8; ++i) {
		gameBoard[1][i] = new Piece('b', 'p'); // Black pawns
		gameBoard[6][i] = new Piece('w', 'P'); // White pawns
	}
	// Add other pieces like rooks, knights, bishops, queens, and kings
	// You would need to create specific classes for each piece type
	for(int i = 0; i < 8; ++i) {
		gameBoard[2][i] = new Piece('_', '_'); 
		gameBoard[3][i] = new Piece('_', '_');
  		gameBoard[4][i] = new Piece('_', '_');
		gameBoard[5][i] = new Piece('_', '_'); 
	}	

	gameBoard[7][0] = new Piece('w', 'R'); // White rook
	gameBoard[7][1] = new Piece('w', 'N'); // White knight
	gameBoard[7][2] = new Piece('w', 'B'); // White bishop
	gameBoard[7][3] = new Piece('w', 'Q'); // White queen
	gameBoard[7][4] = new Piece('w', 'K'); // White king
	gameBoard[7][5] = new Piece('w', 'B'); // White bishop
	gameBoard[7][6] = new Piece('w', 'N'); // White knight
	gameBoard[7][7] = new Piece('w', 'R'); // White rook
				   
}
