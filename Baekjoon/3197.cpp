#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
 
int r, c;
bool can_find;
char map[1501][1501];
bool visited[1501][1501];
const int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
vector<pair<int, int>> swan;
queue<pair<int, int>> swan_q, swan_nq, q, nq;
 
void bfs(){
    while (!swan_q.empty() && !can_find){
        int x = swan_q.front().first;
        int y = swan_q.front().second;
        swan_q.pop();
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if(nx < 0 || nx > c-1 || ny < 0 || ny > r-1) continue;
            if (visited[ny][nx] == false){
                if (map[ny][nx] == '.'){
                    visited[ny][nx] = true;
                    swan_q.push({nx, ny});
                }else if (map[ny][nx] == 'L'){
                    visited[ny][nx] = true;
                    can_find = true;
                    break;
                }else if (map[ny][nx] == 'X'){
                    visited[ny][nx] = true;
                    swan_nq.push({nx, ny});
                }            
            }
        }
    }
}
 
void bfs2(){
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if(nx < 0 || nx > c-1 || ny < 0 || ny > r-1) continue;

            if (map[ny][nx] == 'X'){
                map[ny][nx] = '.';
                nq.push({nx, ny});
            }
        }
    }
}
 
void solve() {
    int day = 0;
    swan_q.push({swan[0].first, swan[0].second});
    visited[swan[0].second][swan[0].first] = true;
 
    while (!can_find){
        bfs();
 
        if (!can_find){
            bfs2();
            q = nq;
            swan_q = swan_nq;
 
            while (!nq.empty()) nq.pop();
            while (!swan_nq.empty()) swan_nq.pop();
            day++;
        }
    }
    cout << day << '\n';
}
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 'X') q.push({j, i});    
            if (map[i][j] == 'L') swan.push_back({j, i});
        }
    }
    solve();
    return 0;
}
