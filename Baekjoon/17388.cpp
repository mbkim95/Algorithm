#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int s, k, h;
    cin >> s >> k >> h;
    if(s+k+h >= 100) cout << "OK\n";
    else {
        if(min(s, min(k, h)) == s) cout << "Soongsil\n";
        else if(min(s, min(k, h)) == k) cout << "Korea\n";
        else cout << "Hanyang\n";
    }
    return 0;
}