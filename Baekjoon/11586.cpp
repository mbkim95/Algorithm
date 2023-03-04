#include <iostream>
using namespace std;

int n, k;
char m[100][101];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> m[i][j];
    cin >> k;

    if(k == 1) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) cout << m[i][j];
            cout << '\n';
        }
    } else if(k == 2) {
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=0; j--) cout << m[i][j];
            cout << '\n';
        }
    } else {
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<n; j++) cout << m[i][j];
            cout << '\n';
        }
    }
    return 0;
}