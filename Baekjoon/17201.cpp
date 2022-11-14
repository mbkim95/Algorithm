#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string b = s.substr(0, 2);
    bool isConnected = true;
    for(int i=1; i<n; i++) if(b != s.substr(i*2, 2)) isConnected = false;
    cout << (isConnected ? "Yes\n" : "No\n");
    return 0;
}