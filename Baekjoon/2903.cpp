#include <iostream>
using namespace std;

int main() {
    int n, w = 2;;
    cin >> n;
    while(n--) w += w-1;
    cout << w * w << '\n';
    return 0;
}