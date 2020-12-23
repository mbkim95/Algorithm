#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n, m;
vector<int> num, result;
unordered_set<string> s;

void dfs(int idx){
    if(result.size() == m){
        string str = "";
        for(int i : result){
            str += to_string(i);
            str += ' ';
        }
        if(s.find(str) == s.end()){
            s.insert(str);
            cout << str << '\n';
        }
        return;
    }

    for(int i=idx+1; i<n; i++){
        result.push_back(num[i]);
        dfs(i);
        result.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    num.resize(n);
    for(int i=0; i<n; i++)
        cin >> num[i];

    sort(num.begin(), num.end());
    dfs(-1);
    return 0;
}
