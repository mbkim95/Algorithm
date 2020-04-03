#include <vector>
#include <queue>
using namespace std;

int M, N;
vector<vector<bool>> visited;
const int dx[] = {-1 ,0, 1, 0}, dy[] = {0, -1, 0, 1};

bool inRange(int x, int y){
    return (0 <= x && x < N) && (0 <= y && y < M);
}

int bfs(int x, int y, vector<vector<int>>& picture){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    int v = picture[y][x];
    int cnt = 1;

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(inRange(nx, ny) && !visited[ny][nx] && picture[ny][nx] == v){
                visited[ny][nx] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int area_cnt = 0;
    int max_area = 0;
    M = m;
    N = n;
    vector<int> answer(2);
    visited = vector<vector<bool>>(M, vector<bool>(N, false));
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j] && picture[i][j] != 0){
                area_cnt++;
                max_area = max(max_area, bfs(j, i, picture));
            }
        }
    }
    answer[0] = area_cnt;
    answer[1] = max_area;
    return answer;
}