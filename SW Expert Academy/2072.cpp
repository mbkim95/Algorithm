#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
 
    for (int c = 1; c <= t; c++) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            int tmp;
            cin >> tmp;
            if (tmp % 2)
                sum += tmp;
        }
        cout << "#" << c << ' ' << sum << '\n';
    }
    return 0;
}