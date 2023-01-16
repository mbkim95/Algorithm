#include <iostream>
#include <map>
using namespace std;

int n;
map<string, int> c;

int main(){
    cin >> n;
    for(int i=0; i<n; i++) {
        string f;
        int cnt;
        cin >> f >> cnt;
        c[f] += cnt;
    }
    bool find = false;
    for(auto it : c) {
        if(it.second == 5) {
            find = true;
            break;
        }
    }
    if(find) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}