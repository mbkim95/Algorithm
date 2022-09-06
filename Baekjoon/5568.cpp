#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, k;
string card[10];
bool selected[10];
vector<string> pick;
set<string> s;

void dfs() {
    if(pick.size() == k) {
        string num = pick[0];

        for(int i=1; i<k; i++) num += pick[i];
        s.insert(num);
        return;
    }

    for(int i=0; i<n; i++) {
        if(!selected[i]) {
            pick.push_back(card[i]);
            selected[i] = true;
            dfs();
            selected[i] = false;
            pick.pop_back();
        }
    }
}

int main() {
    cin >> n;
    cin >> k;
    for(int i=0; i<n; i++) cin >> card[i];
    dfs();
    cout << s.size() << '\n';
    return 0;
}