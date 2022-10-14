#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    n1--;
    n2--;
    cout << abs(n1%4-n2%4)+abs(n1/4-n2/4) << '\n';
    return 0;
}