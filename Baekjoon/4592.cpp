#include <iostream>
using namespace std;

int main() {
    while(true) {
        int n;
        cin >> n;

        if(n == 0) break;

        int prev = 0;
        for(int i=0; i<n; i++) {
            int tmp;
            cin >> tmp;
            if(prev == tmp) continue;
            prev = tmp;
            cout << tmp << ' ';
        }
        cout << "$\n";
    }
    return 0;
}