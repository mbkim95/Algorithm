#include<vector>
#include <queue>
using namespace std;

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int bfs(vector<vector<int>>& maps){
    int ret = 0;
    int m = maps.size();
    int n = maps[m-1].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || nx > n-1 || ny < 0 || ny > m-1) continue;
            if(visited[ny][nx] == 0 && maps[ny][nx] == 1){
                visited[ny][nx] = visited[cur.second][cur.first] + 1;
                q.push({nx, ny});
            }
        }
    }
    if(visited[m-1][n-1] == 0) ret = -1;
    else ret = visited[m-1][n-1];
    return ret;
}

int solution(vector<vector<int> > maps)
{
	return bfs(maps);
}