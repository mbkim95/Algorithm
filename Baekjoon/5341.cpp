#include <iostream>
using namespace std;

int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        cout << (n * (n + 1)) / 2 << '\n';
    }
    return 0;
}
