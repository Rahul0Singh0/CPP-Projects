#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Board {
    vector<vector<char>> board;
    vector<vector<char>> vis;
    int size;
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
        vis.resize(3, vector<char> (3, '-'));
        size = 0;
    }

    void updateBoard(int location, char player) {
        if(location == 1) {
            board[1][3] = player;
            vis[0][0] = player;
        } else if(location == 2) {
            board[1][9] = player;
            vis[0][1] = player;
        } else if(location == 3) {
            board[1][15] = player;
            vis[0][2] = player;
        } else if(location == 4) {
            board[3][3] = player;
            vis[1][0] = player;
        } else if(location == 5) {
            board[3][9] = player;
            vis[1][1] = player;
        } else if(location == 6) {
            board[3][15] = player;
            vis[1][2] = player;
        } else if(location == 7) {
            board[5][3] = player;
            vis[2][0] = player;
        } else if(location == 8) {
            board[5][9] = player;
            vis[2][1] = player;
        } else if(location == 9) {
            board[5][15] = player;
            vis[2][2] = player;
        }
        size++;
        printBoard();
    }

    void printBoard() {
        system("cls");
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 19; j++) {
                cout<<board[i][j];
            }
            cout<<endl;
        }
        cout<<"\n\n";
    }

    bool checkWin(char player) {
        for(int i = 0; i < 3; i++) {
            // column checked
            if(vis[i][0] == player && vis[i][1] == player && vis[i][2] == player) return true;
            // row checked
            else if(vis[0][i] == player && vis[1][i] == player && vis[2][i] == player) return true;
            // diagonals checked
            else if(vis[0][0] == player && vis[1][1] == player && vis[2][2] == player) return true;
            else if(vis[0][2] == player && vis[1][1] == player && vis[2][0] == player) return true;
        }
        return false;
    }
    bool isFull() {
        return size == 9;
    }
};