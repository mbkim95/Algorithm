#include <iostream>
using namespace std;

int main() {
    int n, o = 0, e = 0, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp % 2) o++;
        else e++;
    }
    if (n / 2 == e) cout << "1\n";
    else cout << "0\n";
    return 0;
}