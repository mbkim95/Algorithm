#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string word;
    vector<string> cand;
    cin >> word;

    int n = word.length();
    for(int i=1; i<=n-2; i++) {
        for(int j=i+1; j<=n-1; j++) {
            string a = word.substr(0, i);
            string b = word.substr(i, j-i);
            string c = word.substr(j, n-j);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            cand.push_back(a + b + c);  
        }
    }
    sort(cand.begin(), cand.end());
    cout << cand.front() << '\n';
    return 0;
}