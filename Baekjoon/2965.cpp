#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(b - a - 1, c - b - 1) << '\n';
    return 0;
}