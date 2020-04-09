#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map (n, vector<int>(m, 0));
    for(auto v : puddles) map[v[1]-1][v[0]-1] = -1;
    for(int i=0; i<n; i++){
        if(map[i][0] == -1) break;
        map[i][0] = 1;
    }
    for(int i=0; i<m; i++){
        if(map[0][i] == -1) break;
        map[0][i] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(map[i][j] == -1) continue;
            int left = map[i][j-1] == -1 ? 0 : map[i][j-1];
            int up = map[i-1][j] == -1 ? 0 : map[i-1][j];
            map[i][j] = (left + up) % MOD;
        }
    }
    return map[n-1][m-1];
}