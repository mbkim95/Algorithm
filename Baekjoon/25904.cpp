#include <iostream>
using namespace std;

int n, x, t[101];

int main() {
    cin >> n >> x;
    for(int i=1; i<=n; i++) cin >> t[i];

    int turn = 1;
    while(true) {
        if(t[turn] < x) {
            cout << turn << '\n';
            break;
        }
        x++;
        turn = turn == n ? 1 : turn + 1;
    }
    return 0;
}