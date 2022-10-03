#include <iostream>
using namespace std;

long long t[36];

int main() {
    int n;
    cin >> n;
    t[0] = t[1] = 1;

    for(int i=2; i<=n; i++) 
        for(int j=0; j<i; j++) 
            t[i] += t[j] * t[i-j-1];
    cout << t[n] << '\n';
}