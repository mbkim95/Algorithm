#include <iostream>
using namespace std;

int main() {
    int s1, s2, a, b;
    cin >> s1 >> s2;
    
    string ans = "Accepted";
    for(int i=0; i<s1; i++) {
        cin >> a >> b;
        if(a != b) ans = "Wrong Answer";
    }
    for(int i=0; i<s2; i++) {
        cin >> a >> b;
        if(ans == "Accepted" && a != b) ans = "Why Wrong!!!";
    }
    cout << ans << '\n';
    return 0;
}
