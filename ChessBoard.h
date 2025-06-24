#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>


#include "Piece.h"
#include "ChessGame.h"
#include "Move.h"
#include "Subject.h"
#include "Observer.h"
#include "ChessBoard.instance.h"

class ChessBoard
{
private:
	vector<string> moveHistory;

	static Piece* gameBoard[8][8];

	static ChessBoard *instance;

	Piece* piece[32];
	ChessGame chessGame;
	Move move;
	Subject subject;
	Observer observer;

private:
	bool swap(int* move);

protected:
    ChessBoard();

	~ChessBoard() {
		// Clean up resources if necessary
	}

public:
	ChessBoard(const ChessBoard&) = delete; // Prevent copying
 	
	ChessBoard& operator=(const ChessBoard&) = delete; // Prevent assignment

	static ChessBoard *getInstance();

	vector<string> getMoveHistory(int prevMoves);

	void updateBoard(string move);
		
    Piece* getGameBoard(int row, int col);

	void setGameBoard(int row, int col, Piece* piece);

	void initializeBoard();
};
#endif
