#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <Rook.h>
#include <Bishop.h>

#include "Queen.h"


Queen::Queen(char direction, char symbol) : Piece(direction, symbol)
{
	this->direction = direction;
	this->symbol = symbol;
	this->rook = new Rook(direction, 'R');  
	this->bishop = new Bishop(direction, 'B'); 
	assert(direction == 'w' || direction == 'b');
	assert(symbol != ' ');
}

int* Queen::moveLogic(int* move, char GameBoardArray[][8], int row)
{
    int across_from = *move;
    move++;
    int down_from = *move;
    move++;
    int across_to = *move;
    move++;
    int down_to = *move;

    int directionalDifferenceXAxis = across_from-across_to;
    int directionalDifferenceYAxis = down_from-down_to;

    if(directionalDifferenceXAxis == 0 || directionalDifferenceYAxis == 0){
        return rook->moveLogic(move, GameBoardArray, row);
    }else if(directionalDifferenceXAxis == directionalDifferenceYAxis){
        return bishop->moveLogic(move, GameBoardArray, row);
    }

	return nullptr;
}

void Queen::testKingCheck(char GameBoardArray[][8], int x, int y)
{
	rook->testKingCheck(GameBoardArray, x, y);
	bishop->testKingCheck(GameBoardArray, x, y);
}
