#include <iostream>
using namespace std;

bool isUpper[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q, cnt = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int rest = i % 10;
        if (rest == 1 || rest == 4 || rest == 7) {
            isUpper[i] = true;
            cnt++;
        }
    }
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if(isUpper[x]) cnt--;
        else cnt++;
        isUpper[x] = !isUpper[x];
        cout << cnt << '\n';
    }
    return 0;
}