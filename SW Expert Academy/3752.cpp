#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
int n;
vector<bool> chk;
vector<int> score;
 
int main() {
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n;
        int sum = 0;
        score = vector<int>(n);
        for (int i = 0; i < n; i++) {
            cin >> score[i];
            sum += score[i];
        }
        chk = vector<bool>(10001, false);
        int ans = 0;
        chk[0] = true;
 
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= 0; j--) {
                if (chk[j]) 
                    chk[j + score[i]] = true;
            }
        }
 
        for (int i = 0; i <= 10000; i++)
            if (chk[i])
                ans++;
 
        cout << "#" << c << ' ' << ans << '\n';
    }
}