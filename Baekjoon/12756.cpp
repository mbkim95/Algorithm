#include <iostream>
using namespace std;

int main() {
    int aa, ad, ba, bd;
    cin >> aa >> ad;
    cin >> ba >> bd;
    while(ad > 0 && bd > 0) {
        ad -= ba;
        bd -= aa;
    }
    if(ad < 1 && bd < 1) cout << "DRAW\n";
    else if(ad < 1) cout << "PLAYER B\n";
    else cout << "PLAYER A\n";
    return 0;
}