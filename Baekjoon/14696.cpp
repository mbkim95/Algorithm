#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int p[2][5];
        memset(p, 0, sizeof(p));

        for(int i=0; i<2; i++) {
            int t, tmp;
            cin >> t;
            while(t--) {
                cin >> tmp;
                p[i][tmp]++;
            }
        }

        int winner = 0;
        for(int i=4; i>0; i--) {
            if(p[0][i] > p[1][i]) winner = 1;
            else if(p[0][i] < p[1][i]) winner = 2;
            if(winner != 0) break;
        }
        if(winner == 0) cout << "D\n";
        else if(winner == 1) cout << "A\n";
        else cout << "B\n";
    }
    return 0;
}