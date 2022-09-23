#include <iostream>
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    int x = 0, y = 0;
    bool is_good = true;
    int dir = 0;
    for(int i=0; i<n; i++) {
        string cmd;
        int num;
        cin >> cmd >> num;

        if(!is_good) continue;

        if(cmd == "MOVE") {
            for(int i=0; i<num; i++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx < 0 || nx > m || ny < 0 || ny > m) {
                    is_good = false;
                    break;
                }
                x = nx, y = ny;
            }
        } else {
            if(num == 0) dir = dir == 0 ? 3 : dir - 1;
            else dir = (dir + 1) % 4;
        }
    }
    if(is_good) cout << x << ' ' << y << '\n';
    else cout << "-1\n";
    return 0;
}