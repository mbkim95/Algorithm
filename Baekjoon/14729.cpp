#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<float> s;

int main() {
    int n;
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());

    cout.precision(3);
    for(int i=0; i<7; i++) cout << fixed << s[i] << '\n';
    return 0;
}