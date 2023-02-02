#include <iostream>
using namespace std;

int main() {
    int n, t, sum = 0, cnt = 0;
    cin >> n >> t;

    bool isFinished = false;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if(sum <= t && sum + tmp > t) isFinished = true;
        if(isFinished) continue;
        sum += tmp;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}