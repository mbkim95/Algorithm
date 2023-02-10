#include <iostream>
using namespace std;

int n, m, l, f[51], t;

int main() {
    cin >> n >> m >> l;
    int b = 1;
    while(true) {
        f[b]++;
        if(f[b] == m) break;
        
        if(f[b] % 2) {
            for(int i=0; i<l; i++) b++;
            if(b > n) b -= n;
        } else {
            for(int i=0; i<l; i++) b--;
            if(b < 1) b += n;
        }
        t++;
    }
    cout << t << '\n';
    return 0;
}