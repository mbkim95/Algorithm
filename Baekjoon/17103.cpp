#include <iostream>
using namespace std;

bool prime[1000001];

void preCalc() {
    for(int i=2; i<=1000000; i++) prime[i] = true;

    for(int i=2; i<=1000000; i++) {
        if(!prime[i]) continue;

        for(int j=2; j*i<=1000000; j++) prime[i*j] = false;
    }
}

int main() {
    int t, n;
    cin >> t;
    preCalc();

    while(t--) {
        cin >> n;

        int cnt = 0;
        for(int i=2; i<=n/2; i++) {
            if(prime[i] && prime[n-i]) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}