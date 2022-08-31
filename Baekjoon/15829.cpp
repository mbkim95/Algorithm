#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m = 1234567891;

    int l;
    cin >> l;
    string str;
    cin >> str;

    long long hash = 0, r = 1;
    for(int i=0; i<l; i++) {
        hash = (hash + (str[i] - 'a' + 1) * r) % m;
        r = (r * 31) % m;
    }
    cout << hash << '\n';
    return 0;
}