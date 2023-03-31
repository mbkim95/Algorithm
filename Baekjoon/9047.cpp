#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int cnt = 0;
        string n;
        cin >> n;
        while(n != "6174") {
            sort(n.begin(), n.end());
            int minN = stoi(n);
            sort(n.begin(), n.end(), greater<char>());
            int maxN = stoi(n);
            n = to_string((maxN - minN));

            while(n.length() < 4) {
                n = '0' + n;
            }
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}