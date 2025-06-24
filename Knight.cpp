#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Knight.h"


Knight::Knight(char direction, char symbol) : Piece(direction, symbol)
{
	this->direction = direction;
	this->symbol = symbol;
	this->firstMove = true;
	Castling = false;
	assert(direction == 'w' || direction == 'b');
	assert(symbol != ' ');
}

int* Knight::moveLogic(int* move, char GameBoardArray[][8], int row)
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

    if(down_from > 7 || down_from < 0){
        return nullptr;
    }
    else if(down_to > 7 || down_to < 0){
        return nullptr;
    }
    else if(across_from > 7 || across_from < 0){
        return nullptr;
    }
    else if(across_to > 7 || across_to < 0){
        return nullptr;
    }

    int absoluteX = abs(directionalDifferenceXAxis);
    int absoluteY = abs(directionalDifferenceYAxis);

    if(absoluteX == 2 && absoluteY == 1){
        if(direction == '+' &&
           GameBoardArray[across_to][down_to] != 'w' &&
           GameBoardArray[across_to][down_to] != 'W'){
            firstMove = false;
            return move;
        }
        else if(direction == '-' &&
                GameBoardArray[across_to][down_to] != 'b' &&
                GameBoardArray[across_to][down_to] != 'B'){
            firstMove = false;
            return move;
        }
    }
    else if(absoluteX == 1 && absoluteY == 2){
        if(direction == '+' &&
           GameBoardArray[across_to][down_to] != 'w' &&
           GameBoardArray[across_to][down_to] != 'W'){
            firstMove = false;
            return move;
        }
        else if(direction == '-' &&
                GameBoardArray[across_to][down_to] != 'b' &&
                GameBoardArray[across_to][down_to] != 'B'){
            firstMove = false;
            return move;
        }
    }
    return nullptr;
}

void Knight::testKingCheck(char GameBoardArray[][8], int x, int y)
{


    if(x > 1 && y < 7){
        if(GameBoardArray[x-2][y+1] == '_'){
            GameBoardArray[x-2][y+1] = 'x';
        }
    }

    if(x > 0 && y < 6){
        if(GameBoardArray[x-1][y+2] == '_'){
            GameBoardArray[x-1][y+2] = 'x';
        }
    }

    if(x < 6 && y < 7){
        if(GameBoardArray[x+2][y+1] == '_'){
            GameBoardArray[x+2][y+1] = 'x';
        }
    }

    if(x < 7 && y < 6){
        if(GameBoardArray[x+1][y+2] == '_'){
            GameBoardArray[x+1][y+2] = 'x';
        }
    }


    if(x > 1 && y > 0){
        if(GameBoardArray[x-2][y-1] == '_'){
            GameBoardArray[x-2][y-1] = 'x';
        }
    }

    if(x > 0 && y > 1){
        if(GameBoardArray[x-1][y-2] == '_'){
            GameBoardArray[x-1][y-2] = 'x';
        }
    }

    if(x < 6 && y > 0){
        if(GameBoardArray[x+2][y-1] == '_'){
            GameBoardArray[x+2][y-1] = 'x';
        }
    }

    if(x < 7 && y > 1){
        if(GameBoardArray[x+1][y-2] == '_'){
            GameBoardArray[x+1][y-2] = 'x';
        }
    }
}
