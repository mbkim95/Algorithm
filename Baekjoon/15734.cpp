#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int l, r, a;
    cin >> l >> r >> a;
    int diff = abs(l - r);
    if(diff == 0) cout << 2 * (l + a / 2) << '\n';
    else{
        if(diff >= a) cout << 2 * (min(l, r) + a) << '\n';
        else{
            a -= diff;
            cout << 2 * (max(l, r) + a / 2) << '\n';
        }
    }
    return 0;
}
