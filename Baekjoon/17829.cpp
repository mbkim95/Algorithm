#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int table[1024][1024];

int calculate(int x, int y) {
    vector<int> tmp;
    for(int i=0; i<2; i++) for(int j=0; j<2; j++) tmp.push_back(table[y+i][x+j]);
    sort(tmp.begin(), tmp.end());
    return tmp[2];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> table[i][j];

    while(n > 1) {
        n /= 2;
        vector<int> tmp;
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) tmp.push_back(calculate(2 * j, 2 * i));
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) table[i][j] = tmp[n * i + j];
    }
    cout << table[0][0] << '\n';
    return 0;
}