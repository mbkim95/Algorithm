#include <iostream>
using namespace std;

const int day[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if(x <= 23 && y <= 59) cout << "Yes";
        else cout << "No";
        if(1 <= x && x <= 12 && 1 <= y && y <= day[x]) cout << " Yes\n";
        else cout << " No\n";
    }
    return 0;
}