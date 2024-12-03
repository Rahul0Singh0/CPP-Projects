#include <iostream>
#include <vector>
#include <string>
#include "Board.h"
using namespace std;

class Game {
    char player;
    Board b;
public:
    Game() {
        cout<<"Welcome to Tic-Tac-Toe Two Player Game\n";
        cout<<"First Player: X\nSecond Player: O\n";
        player = 'X';
    }
    void start() {
        b.printBoard();
    }
    bool winGame() {

    }
    void play() {
        int grid;
        while(true) {
            cout<<"Player "<<player<<"\n";
            cout<<"Enter your choice grid: ";
            cin>>grid;
            b.updateBoard(grid, player);
            player = player == 'X' ? 'O' : 'X'; // player switched
            // return;
        }
    }
};

int main() {
    while(true) {
        Game ga;
        cout<<"1.Start Game\n";
        cout<<"2.End Game\n";
        int n; cin>>n;
        switch(n) {
            case 1:
                ga.start();
                ga.play();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout<<"Invalid Input!\n";
                break;
        }
    }
    return 0;
}