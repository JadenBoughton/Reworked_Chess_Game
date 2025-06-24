#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ChessGame.h"
using namespace std;


void ChessGame::main()
{
    // This is the main function for the ChessGame class
    // You can implement the game logic here, such as initializing the board,
    // handling player input, and managing the game state.

    //Player 

    cout << "Welcome to Chess!" << endl;

    cout << "Initializing the chess board..." << endl;
    
    // Initialize the chess board
    ChessBoard* board = ChessBoard::getInstance();

    cout << "Chess board initialized." << endl;

    cout << "Do you want to play against another player or against the computer? (p/c): ";
    char choice;
    cin >> choice;

    if (choice == 'p' || choice == 'P') {
        cout << "You chose to play against another player." << endl;
    } else if (choice == 'c' || choice == 'C') {
        cout << "You chose to play against the computer." << endl;
    } else {
        cout << "Invalid choice. Exiting the game." << endl;
        return; // Exit if the choice is invalid
    }
    
    // Example of how to set up pieces (you would need to implement this)
    // board->initializeBoard();
    
    // Start the game loop
    while (true) {
        // Get player input for moves
        string move;
        cout << "Enter your move (e.g., e2-e4): ";
        cin >> move;
        if (move == "exit") {
            cout << "Exiting the game." << endl;
            break; // Exit the game loop
        }
        // Process the move (you would need to implement this)
        // board->updateBoard(move);
        
        // Check for game over conditions, checkmate, etc.
        // if (gameOver) break;
    }

    cout << "Game over!" << endl;
}
