#include <iostream>
using namespace std;

int main() { 
    int t, k;
    cin >> t;
    while(t--) {
        cin >> k;
        for(int i=0; i<k; i++) cout << '=';
        cout << '\n';
    }
}