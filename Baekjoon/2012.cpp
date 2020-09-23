#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    vector<int> s;
    cin >> n;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    sort(s.begin(), s.end());
    
    long long answer = 0;
    for (int i=0; i<n; i++) {
        answer += (long long) abs(s[i] - (i + 1));
    }
    cout << answer << '\n';
    return 0;
}