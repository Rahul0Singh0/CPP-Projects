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
        system("cls");
        cout<<"Welcome to Tic-Tac-Toe Two Player Game\n";
        cout<<"First Player: X\nSecond Player: O\n";
        player = 'X';
    }
    void start() {
        b.printBoard();
    }
    bool checkWin() {
        return b.checkWin(player);
    }
    bool isFull() {
        return b.isFull();
    }
    void play() {
        int location;
        while(true) {
            if(isFull()) {
                cout<<"Draw the game!\n\n";
                system("pause");
                return;
            }

            cout<<"Player "<<player<<"\n";
            cout<<"Enter your choice grid: ";
            cin>>location;
            if(location < 1 && location > 9) {
                cout<<"Invalid location!!!\n";
                cout<<"Try Again: ";
            } 
            
            b.updateBoard(location, player);

            if(checkWin()) {
                cout<<player<<" won the game!\n\n";
                system("pause");
                return;
            } 

            player = player == 'X' ? 'O' : 'X'; // player switched
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