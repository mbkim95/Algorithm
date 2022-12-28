#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    for(int t=1; t<=k; t++) {
        if(t != 1) cout << '\n';
        int h;
        cin >> h;
        string s;
        cin >> s;
        for(char c : s) {
            if(c == 'c') h++; 
            else h--;    
        }
        cout << "Data Set " << t << ":\n";
        cout << h << '\n';
    }
    return 0;
}