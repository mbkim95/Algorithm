#include <iostream>
using namespace std;

string s, y, k;
int yIdx, kIdx;

int main() {
    y = "YONSEI";
    k = "KOREA"; 
    cin >> s;

    for(char c : s) {
        if(yIdx == y.length()) {
            cout << "YONSEI\n";
            break;
        }
        if(kIdx == k.length()) {
            cout << "KOREA\n";
            break;
        }
        if(c == y[yIdx]) yIdx++;
        if(c == k[kIdx]) kIdx++;
    }
    return 0;
}