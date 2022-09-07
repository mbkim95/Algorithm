#include <iostream>
#include <algorithm>
using namespace std;

bool can_make(const string& paper) {
    int n = paper.length();

    if(n == 1) return true;
    if(n == 3) return paper[0] != paper[2];

    string p1 = paper.substr(0, n/2);
    string p2 = paper.substr(n/2+1, n/2);
    reverse(p2.begin(), p2.end());

    for(int i=0; i<n/2; i++) if(p1[i] == p2[i]) return false;
    return can_make(p1) & can_make(p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string paper;
        cin >> paper;
        cout << (can_make(paper) ? "YES\n" : "NO\n");
    }
    return 0;
}