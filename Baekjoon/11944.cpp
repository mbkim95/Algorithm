#include <iostream>
using namespace std;

int main(){
    string n, m;
    cin >> n >> m;
    string ans = "";    
    for(int i=0; i<stoi(n); i++)
        ans += n;
    if(ans.length() > stoi(m)) cout << ans.substr(0, stoi(m)) << '\n';
    else cout << ans << '\n';
    return 0;
}