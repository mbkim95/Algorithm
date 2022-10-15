#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100000];
long long x;

int main() {
    cin >> n;
    cin >> x;
    n--;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    bool canSurvive = true;
    for(int i=0; i<n; i++) {
        if(x <= a[i]) {
            canSurvive = false;
            break;
        }
        x += a[i];
    }
    if(canSurvive) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}