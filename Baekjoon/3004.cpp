#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d = n / 2;
    if (n % 2) cout << (d + 2) * (d + 1) << '\n';
    else cout << (d + 1) * (d + 1)<< '\n';
    return 0;
}