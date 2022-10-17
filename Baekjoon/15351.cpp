#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    while(n--) {
        string s;
        getline(cin, s);

        int sum = 0;
        for(char c: s) {
            if(c == ' ') continue;
            sum += c - 'A' + 1;
        }
        if(sum == 100) cout << "PERFECT LIFE\n";
        else cout << sum << '\n';
    }
    return 0;
}