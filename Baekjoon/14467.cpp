#include <iostream>
using namespace std;

int n, c[11], cnt;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) c[i] = -1;

    while(n--) {
        int cow, dir;
        cin >> cow >> dir;
        if(c[cow] == -1) c[cow] = dir;
        else if(c[cow] != dir) {
            c[cow] = dir;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
