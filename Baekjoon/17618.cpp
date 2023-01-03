#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int tmp = i, sum = 0;
        while(tmp > 0) {
            sum += (tmp % 10);
            tmp /= 10;
        }
        if(i % sum == 0) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}