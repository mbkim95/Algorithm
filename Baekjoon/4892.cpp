#include <iostream>
using namespace std;

int main() {
    int t = 0;
    while(true) {
        t++;
        int n;
        cin >> n;

        if(n == 0) break;

        int n2;
        if(n % 2) n2 = ((n * 3) + 1) / 2;
        else n2 = (n * 3) / 2;
        cout << t << ". " << (n % 2 ? "odd " : "even ") << (3 * n2) / 9 << '\n';
    }
    return 0;
}