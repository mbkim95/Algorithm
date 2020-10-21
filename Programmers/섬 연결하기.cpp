#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int parent[101];
vector<pair<int, pair<int, int>>> edges;

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int  kruskal(){
    sort(edges.begin(), edges.end());
    int sum = 0;
    for(int i=0; i<edges.size(); i++){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int cost = edges[i].first;
        
        if(find(a) == find(b)) continue;
        merge(a, b);
        sum += cost;
    }
    return sum;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(auto i : costs){
        edges.push_back({i[2], {i[0], i[1]}});
    }
    for(int i=1; i<=n; i++) parent[i] = i;
    answer = kruskal();
    return answer;
}