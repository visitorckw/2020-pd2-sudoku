#include<iostream>
//#include<ctime>
using namespace std;
int ans = 0;
int board[9][9];
int ans_board[9][9];
bool row[9][10];
bool col[9][10];
bool square[3][3][10];
int frow[9];
int fcol[9];
void copy();
//void validNumber(const int, const int, bool []);
void dfsRow(const int, const int);
void dfsCol(const int, const int);
void copy() {
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            ans_board[i][j] = board[i][j];
}
/*void validNumber(const int x, const int y, bool valid[]) {
    for(int i = 0; i < 10; i++)
        valid[i] = true;
    for(int i = 0; i < 9; i++) {
        if(board[x][i])
            valid[board[x][i]] = false;
        if(board[i][y])
            valid[board[i][y]] = false;
    }
    for(int i = x - x%3; i < x - x%3 + 3; i++)
        for(int j = y - y%3; j < y - y%3 + 3; j++)
            if(board[i][j])
                valid[board[i][j]] = false;
}*/
void dfsRow( const int x, const int y) {
    if(ans > 1)
        return;
    /*if(y >= 9) {
        ans++;
        copy();
        return;
    }*/
    if(y >= 9) {
        int maxR = -1, r = -1;
        int maxC = -1, c = -1;
        for(int i = 0; i < 9; i++) {
            if(frow[i] < 9 && frow[i] > maxR) {
                maxR = frow[i];
                r = i;
            }
            if(fcol[i] < 9 && fcol[i] > maxC) {
                maxC = fcol[i];
                c = i;
            }
        }
        if(r == -1 && c == -1) {
            ans++;
            copy();
            return;
        }
        if(maxR > maxC)
            dfsRow(r,0);
        else
            dfsCol(0,c);
        return;
    }
    if(board[x][y]) {
        dfsRow(x,y+1);
        return;
    }
    //bool valid[10];
    //validNumber(x,y,valid);
    for(int i = 1; i <= 9; i++) {
        if(!row[x][i] && !col[y][i] && !square[x/3][y/3][i]) {
            board[x][y] = i;
            row[x][i] = true;
            col[y][i] = true;
            square[x/3][y/3][i] = true;
            frow[x]++;
            fcol[y]++;
            dfsRow(x, y+1);
            board[x][y] = 0;
            row[x][i] = false;
            col[y][i] = false;
            square[x/3][y/3][i] = false;
            frow[x]--;
            fcol[y]--;
        }
    }
}
void dfsCol( const int x, const int y) {
    if(ans > 1)
        return;
    /*if(y >= 9) {
        ans++;
        copy();
        return;
    }*/
    if(x >= 9) {
        int maxR = -1, r = -1;
        int maxC = -1, c = -1;
        for(int i = 0; i < 9; i++) {
            if(frow[i] < 9 && frow[i] > maxR) {
                maxR = frow[i];
                r = i;
            }
            if(fcol[i] < 9 && fcol[i] > maxC) {
                maxC = fcol[i];
                c = i;
            }
        }
        if(r == -1 && c == -1) {
            ans++;
            copy();
            return;
        }
        if(maxR > maxC)
            dfsRow(r,0);
        else
            dfsCol(0,c);
        return;
    }
    if(board[x][y]) {
        dfsCol(x+1,y);
        return;
    }
    //bool valid[10];
    //validNumber(x,y,valid);
    for(int i = 1; i <= 9; i++) {
        if(!row[x][i] && !col[y][i] && !square[x/3][y/3][i]) {
            board[x][y] = i;
            row[x][i] = true;
            col[y][i] = true;
            square[x/3][y/3][i] = true;
            frow[x]++;
            fcol[y]++;
            dfsCol(x+1, y);
            board[x][y] = 0;
            row[x][i] = false;
            col[y][i] = false;
            square[x/3][y/3][i] = false;
            frow[x]--;
            fcol[y]--;
        }
    }
}
int main() {
    int gridCtr = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if(board[i][j]) {
                gridCtr++;
                if(row[i][board[i][j]] || col[j][board[i][j]] || square[i/3][j/3][board[i][j]]) {
                    cout << 0 << '\n';
                    return 0;
                }
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                square[i/3][j/3][board[i][j]] = true;
                frow[i]++;
                fcol[j]++;
            }
        }
    }
    if(gridCtr < 17) {
        cout << 2 << '\n';
        return 0;
    }
    //int start = clock();
    dfsRow(9,9);
    if(ans > 2)
        ans = 2;
    cout << ans << '\n';
    if(ans == 1) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 8; j++)
                cout << ans_board[i][j] << ' ';
            cout << ans_board[i][8] << '\n';
        }
    }
    //cout << clock() - start;
    return 0;
}
