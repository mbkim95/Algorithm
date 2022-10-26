#include <iostream>
using namespace std;

int main() {
    int t, n, w = 0, l = 0;
    cin >> t;
    while(t--) {
        int n, w = 0, l = 0;
        cin >> n;
        for(int i=0; i<n; i++) {
            char m, e;
            cin >> m >> e;

            if(m == e) continue;
            if((m == 'R' && e == 'S') || (m == 'S' && e == 'P') || (m == 'P' && e == 'R')) w++;
            else l++;
        }
        if(w == l) cout << "TIE\n";
        else if(w > l) cout << "Player 1\n";
        else cout << "Player 2\n";
    }
    return 0;
}