#include <iostream>
using namespace std;

int digit[10];

int main() {
    int n, d;
    cin >> n >> d;

    for(int i=1; i<=n; i++) {
        int tmp = i;
        while(tmp > 0) {
            digit[tmp%10]++;
            tmp /= 10;
        }
    }
    cout << digit[d] << '\n';
    return 0;
}