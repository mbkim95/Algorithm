#include <iostream>
#include <algorithm>
using namespace std;

int d[3];

int main() {
    for(int i=0; i<3; i++) cin >> d[i];
    sort(d, d+3);
    cout << d[1] << '\n';
    return 0;
}