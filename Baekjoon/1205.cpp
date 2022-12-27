#include <iostream>
#include <vector>
using namespace std;

int n, s, p;
vector<int> scores;

int main() {
    cin >> n >> s >> p;
    scores.resize(n);
    for(int i=0; i<n; i++) cin >> scores[i];

    int ans = 1;
    if(n == p && scores[n-1] >= s) ans = -1;
    else {
        for(int i=0; i<n; i++) {
            if(scores[i] > s) ans++;
        }
    }
    cout << ans << '\n';
}