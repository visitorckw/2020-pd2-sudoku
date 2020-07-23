#include<iostream>
using namespace std;
int board[9][9];
int a, x, y;//input variables
void changeNum();
void changeRow();
void changeCol();
void rotate();
void flip();
int main() {
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            cin >> board[i][j];
    while(cin >> a) {
        if(!a) {
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 8; j++)
                    cout << board[i][j] << ' ';
                cout << board[i][8] << '\n';
            }
            return 0;
        }
        if(a == 1) {
            cin >> x >> y;
            changeNum();
        } else if(a == 2) {
            cin >> x >> y;
            changeRow();
        } else if(a == 3) {
            cin >> x >> y;
            changeCol();
        } else if(a == 4) {
            cin >> x;
            x %= 4;
            for(int i = 0; i < x; i++)
                rotate();
        } else {
            cin >> x;
            flip();
        }
    }
    return 0;
}
void changeNum() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == x)
                board[i][j] = y;
            else if(board[i][j] == y)
                board[i][j] = x;
        }
    }
}
void changeRow() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 9; j++)
            swap(board[3*x+i][j],board[3*y+i][j]);
}
void changeCol() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 9; j++)
            swap(board[j][3*x+i],board[j][3*y+i]);
}
void rotate() {
    for(int i = 0; i < 9; i++)
        for(int j = i; j < 9; j++)
            swap(board[i][j],board[j][i]);
    for(int j = 0; j < 4; j++)
        for(int i = 0; i < 9; i++)
            swap(board[i][j],board[i][8-j]);
}
void flip() {
    if(x) {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 4; j++)
                swap(board[i][j],board[i][8-j]);
    } else {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 4; j++)
                swap(board[j][i],board[8-j][i]);
    }
}
