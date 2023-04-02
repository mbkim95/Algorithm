#include <iostream>
using namespace std;

int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    int hc = 0, wc = 0;
    for(int i=1; i<=h; i+=(n+1)) hc++;
    for(int i=1; i<=w; i+=(m+1)) wc++;
    cout << hc * wc << '\n'; 
    return 0;
}