#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    for(int t=0; t<n; t++) {
        cin >> a >> b;
        for(int i=0; i<b; i++) {
            for(int j=0; j<a; j++) cout << "X";
            cout << '\n';
        }
        if(t != n-1) cout << '\n';
    }
    return 0;
}