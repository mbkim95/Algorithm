#include <iostream>
using namespace std;

char m[10][10];

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        for(int i=0; i<10; i++) for(int j=0; j<10; j++) m[i][j] = '#';
        cin >> n;

        for(int i=1; i<n-1; i++) for(int j=1; j<n-1; j++) m[i][j] = 'J';
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) cout << m[i][j];
            cout << '\n';
        }
        if(t != 0) cout << '\n';
    }
    return 0;
}