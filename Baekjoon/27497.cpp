#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    deque<char> q;
    vector<pair<char, int>> order;

    while(n--) {
        int cmd;
        char c;
        cin >> cmd;

        if(cmd == 1) {
            cin >> c;
            q.push_back(c);
            order.push_back({c, 1});
        } else if(cmd == 2) {
            cin >> c;
            q.push_front(c);
            order.push_back({c, 2});
        } else {
            if(q.size() == 0) continue;

            if(q.front() == order.back().first && order.back().second == 2) {
                q.pop_front();
            } else if(q.back() == order.back().first && order.back().second == 1) {
                q.pop_back();
            }
            order.pop_back();
        }
    }

    if(q.size() == 0) cout << "0\n";
    else {
        for(char c : q) cout << c;
        cout << '\n';
    }
    return 0;
}