#include <iostream>
#include <set>
using namespace std;

int main() {
    int k;
    cin >> k;
    while(k--) {
        int p, m, ans = 0;
        set<int> s;
        cin >> p >> m;
        for(int i=0; i<p; i++) {
            int tmp;
            cin >> tmp;
            if(s.find(tmp) != s.end()) ans++;
            else s.insert(tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}