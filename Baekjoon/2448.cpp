#include <iostream>
using namespace std;

char board[3072][6144];

void draw(int n, int x, int y) {
    if(n == 3) {
        board[y][x] = board[y+1][x-1] = board[y+1][x+1] = '*';
        for(int i=x-2; i<=x+2; i++) board[y+2][i] = '*';
        return;
    }
    draw(n/2, x, y);
    draw(n/2, x-(n/2), y+(n/2));
    draw(n/2, x+(n/2), y+(n/2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    draw(n, n-1, 0);

    for(int i=0; i<n; i++) {
        for(int j=0; j<2*n-1; j++) {
            if(board[i][j] != '*') cout << ' ';
            else cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}