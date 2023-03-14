#include <iostream>
using namespace std;

int main() {
    int n, sum = 0, g = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == 0) g++;
        sum += tmp;
    }
    if((n % 2 == 1 && g >= (n/2) + 1) || (n % 2 == 0 && g >= n/2)) cout << "INVALID\n";
    else if(sum > 0) cout << "APPROVED\n";
    else if(sum <= 0) cout << "REJECTED\n";
    return 0;
}