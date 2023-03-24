#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, e = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        e = max(e, tmp);
    }
    cout << e << '\n';
}