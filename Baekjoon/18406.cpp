#include <iostream>
using namespace std;

int main() {
    string n;
    cin >> n;

    int left = 0;
    int right = 0;

    for (int i = 0; i < n.length() / 2; i++) left += (n[i] - '0');
    for (int i = n.length() / 2; i < n.length(); i++) right += (n[i] - '0');

    if (left == right) cout << "LUCKY\n";
    else cout << "READY\n";
    return 0;
}