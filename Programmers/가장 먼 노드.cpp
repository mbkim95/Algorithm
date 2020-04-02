#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> adj;
vector<int> visited;

int bfs(){
    queue<int> q;
    q.push(1);
    visited[1] = 0;
    int ret = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<adj[cur].size(); i++){
            int next = adj[cur][i];
            if(visited[next] == -1){
                visited[next] = visited[cur] + 1;
                ret = max(ret, visited[next]);
                q.push(next);
            }
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    adj = vector<vector<int>>(n+1);
    visited = vector<int>(n+1, -1);
    for(int i=0; i<edge.size(); i++){
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    int t = bfs();
    
    for(int i=1; i<=n; i++)
        if(visited[i] == t) answer++;
    return answer;
}