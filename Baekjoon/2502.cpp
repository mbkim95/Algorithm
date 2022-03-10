#include <iostream>
using namespace std;

int d, k, a[31], b[31];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> d >> k;

    a[1] = b[2] = 1;
    a[2] = b[1] = 0;

    for (int i = 3; i <= 30; i++) {
        a[i] = a[i - 1] + a[i - 2];
        b[i] = b[i - 1] + b[i - 2];
    }

    bool find = false;

    for(int i=1; i<=100000; i++) {
        for(int j=i; j<=100000; j++) {
            if(i * a[d] + j * b[d] == k) {
                cout << i << '\n' << j << '\n';
                find = true;
                break;
            }
        }
        if(find) break;
    }
    return 0;
}