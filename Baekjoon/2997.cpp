#include <iostream>
#include <algorithm>
using namespace std;

int num[3];

int main() {
    for(int i=0; i<3; i++) cin >> num[i];

    sort(num, num+3);

    int a = num[1] - num[0];
    int b = num[2] - num[1];

    if(a > b) cout << num[0] + b << '\n';
    else if(a < b) cout << num[1] + a << '\n';
    else cout << num[2] + a << '\n';
    return 0;
}