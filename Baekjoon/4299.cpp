#include <iostream>
#include <algorithm>
using namespace std;

int digit[10];

int main() {
    int sum, diff;
    cin >> sum >> diff;

    bool find = false;
    for(int i=0; i<=1000; i++) {
        for(int j=0; j<=1000; j++) {
            if(i + j== sum && abs(i - j) == diff) {
                find = true;
                if(i < j) swap(i, j);
                cout << i << ' ' << j << '\n';
                break;
            }
        }
        if(find) break;
    }
    if(!find) cout << "-1\n";
    return 0;
}