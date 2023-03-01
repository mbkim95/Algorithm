#include <iostream>
using namespace std;

int n, x, k;

int main() {
    cin >> n >> x >> k;
    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        if(a == x) x = b;
        else if(b == x) x = a;
    }
    cout << x << '\n';
    return 0;
}