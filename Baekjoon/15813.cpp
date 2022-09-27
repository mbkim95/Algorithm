#include <iostream>
using namespace std;

int main() { 
    int n, ans = 0;
    string name;
    cin >> n;
    cin >> name;
    for(char c : name) ans += (int)(c - 'A' + 1);
    cout << ans << '\n';
    return 0;
}