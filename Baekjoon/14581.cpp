#include <iostream>
using namespace std;

int main() {
    string h;
    cin >> h;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i == 1 && j == 1) cout << ":" << h << ":";
            else cout << ":fan:";
        }
        cout << '\n';
    }
    return 0;
}