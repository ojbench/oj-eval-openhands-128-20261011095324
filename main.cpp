#include <iostream>
#include <vector>
#include <string>

int main() {
    // Read the 3x3 board
    std::vector<std::string> board(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> board[i];
    }
    
    // Count the number of x's and o's
    int count_x = 0, count_o = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x') count_x++;
            else if (board[i][j] == 'o') count_o++;
        }
    }
    
    // Check if x wins
    bool x_wins = false;
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x') {
            x_wins = true;
            break;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == 'x' && board[1][j] == 'x' && board[2][j] == 'x') {
            x_wins = true;
            break;
        }
    }
    // Check diagonals
    if ((board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') || 
        (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x')) {
        x_wins = true;
    }
    
    // Check if o wins
    bool o_wins = false;
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == 'o') {
            o_wins = true;
            break;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == 'o' && board[1][j] == 'o' && board[2][j] == 'o') {
            o_wins = true;
            break;
        }
    }
    // Check diagonals
    if ((board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') || 
        (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o')) {
        o_wins = true;
    }
    
    // Check for invalid cases
    // Case 1: Both x and o win
    if (x_wins && o_wins) {
        std::cout << "invalid" << std::endl;
        return 0;
    }
    
    // Case 2: o has more moves than x (x goes first)
    if (count_o > count_x) {
        std::cout << "invalid" << std::endl;
        return 0;
    }
    
    // Case 3: x has more than one extra move
    if (count_x > count_o + 1) {
        std::cout << "invalid" << std::endl;
        return 0;
    }
    
    // Case 4: x wins but o has same number of moves (should have stopped when x won)
    if (x_wins && count_o == count_x) {
        std::cout << "invalid" << std::endl;
        return 0;
    }
    
    // Case 5: o wins but x has more moves (should have stopped when o won)
    if (o_wins && count_x > count_o) {
        std::cout << "invalid" << std::endl;
        return 0;
    }
    
    // Now check valid game states
    if (x_wins) {
        std::cout << "win" << std::endl;
    } else if (o_wins) {
        std::cout << "lose" << std::endl;
    } else if (count_x + count_o == 9) {
        // Board is full but no one wins
        std::cout << "tie" << std::endl;
    } else {
        // Game is still ongoing
        std::cout << "ongoing" << std::endl;
    }
    
    return 0;
}