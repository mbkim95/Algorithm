#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r = 1, c = 1, tmp, max_value = 0;

    for(int i=1; i<=9; i++) {
        for(int j=1; j<=9; j++) {
            cin >> tmp;
            if(tmp > max_value) {
                max_value = tmp;
                r = i;
                c = j;
            }
        }
    }
    cout << max_value << '\n' << r << ' ' << c << '\n';
    return 0;
}