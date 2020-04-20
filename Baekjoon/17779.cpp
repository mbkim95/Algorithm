#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int map[25][25];
bool chk[25][25];
int area[5];

int calculate(int x, int y, int d1, int d2) {
    memset(chk, 0, sizeof(chk));
    memset(area, 0, sizeof(area));

    // 왼쪽 아래 방향 경계
    for (int i = 0; i <= d1; i++) {
        chk[x + i][y - i] = true;
        chk[x + d2 + i][y + d2 - i] = true;
        area[4] += map[x + i][y - i] + map[x + d2 + i][y + d2 - i];
    }

    // 오른쪽 아래 방향 경계
    for (int i = 1; i < d2; i++) {
        chk[x + d1 + i][y - d1 + i] = true;
        chk[x + i][y + i] = true;
        area[4] += map[x + d1 + i][y - d1 + i] + map[x + i][y + i];
    }

    // 5번 선거구 합 구하기
    for (int i = 0; i < d1; i++){
        int j = 0;
        while (!chk[x + i + j + 1][y - i]){
            chk[x + i + j + 1][y - i] = true;
            area[4] += map[x + i + j + 1][y - i];
            j++;
        }
    }

    // 5번 선거구 합 구하기
    for (int i = 1; i < d2; i++) {
        int j = 0;
        while (!chk[x + i + j + 1][y + i]) {
            chk[x + i + j + 1][y + i] = true;
            area[4] += map[x + i + j + 1][y + i];
            j++;
        }
    }

    /*
    1번 선거구 : 1 ≤ r < x + d1, 1 ≤ c ≤ y
    2번 선거구 : 1 ≤ r ≤ x + d2, y < c ≤ N
    3번 선거구 : x + d1 ≤ r ≤ N, 1 ≤ c < y - d1 + d2
    4번 선거구 : x + d2 < r ≤ N, y - d1 + d2 ≤ c ≤ N
    */

    // 1, 2, 3, 4 선거구의 합 구하기
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (chk[r][c]) continue;
            if (r < x + d1 && c <= y) area[0] += map[r][c];
            else if (r <= x + d2 && y < c) area[1] += map[r][c];
            else  if (x + d1 <= r && c < y - d1 + d2) area[2] += map[r][c];
            else if (x + d2 < r && y - d1 + d2 <= c) area[3] += map[r][c];
        }
    }

    int large = 0;
    int small = numeric_limits<int>::max();
    for (int i = 0; i < 5; i++) {
        large = max(large, area[i]);
        small = min(small, area[i]);
    }
    return large - small;
}

int divide() {
    int ret = numeric_limits<int>::max();
    for (int x = 1; x < n - 1; ++x) {
        for (int y = 2; y <= n - 1; ++y) {
            int d1 = 1;
            int d2 = 1;
            while (true) {
                if (x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n)
                    ret = min(ret, calculate(x, y, d1, d2++));
                else {
                    d1++;
                    d2 = 1;
                    if (!(x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n)) break;
                }
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    cout << divide() << '\n';
    return 0;
}