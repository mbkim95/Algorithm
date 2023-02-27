#include <iostream>
using namespace std;

int main() {
    int l, c;
    cin >> l;
    cin >> c;
    if(c - l >= 31) cout << "You are speeding and your fine is $500.";
    else if(c - l >= 21) cout << "You are speeding and your fine is $270.\n";
    else if(c - l >= 1) cout << "You are speeding and your fine is $100.\n";
    else cout << "Congratulations, you are within the speed limit!\n";
    return 0;
}