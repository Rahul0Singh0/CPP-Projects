#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Board {
    vector<vector<char>> board;
public:
    Board() {
        board.resize(6, vector<char>(19));
        board = {
                 {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
                 {'|','_','_','_','_','_','|','_','_','_','_','_','|','_','_','_','_','_','|'},
                 {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
                 {'|','_','_','_','_','_','|','_','_','_','_','_','|','_','_','_','_','_','|'},
                 {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
                 {'|','_','_','_','_','_','|','_','_','_','_','_','|','_','_','_','_','_','|'},
                };
    }
    void updateBoard(int location, char player) {
        if(location == 1) {
            board[1][3] = player;
        } else if(location == 2) {
            board[1][9] = player;
        } else if(location == 3) {
            board[1][15] = player;
        } else if(location == 4) {
            board[3][3] = player;
        } else if(location == 5) {
            board[3][9] = player;
        } else if(location == 6) {
            board[3][15] = player;
        } else if(location == 7) {
            board[5][3] = player;
        } else if(location == 8) {
            board[5][9] = player;
        } else if(location == 9) {
            board[5][15] = player;
        }
        printBoard();
    }
    void printBoard() {
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 19; j++) {
                cout<<board[i][j];
            }
            cout<<endl;
        }
    }
};