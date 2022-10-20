#include <iostream>
using namespace std;

int main() {
    int n, l, cnt = 0, i = 0;
    cin >> n >> l;
    while(cnt < n) {
        int tmp = ++i;
        
        bool can_make = true;
        while(tmp > 0) {
            if(tmp % 10 == l) {
                can_make = false;
                break;
            }
            tmp /= 10;
        }
        if(can_make) cnt++;
    }
    cout << i << '\n';
    return 0;
}