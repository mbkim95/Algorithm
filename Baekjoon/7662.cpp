#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, k, input;
    char cmd;
    cin >> t;

    while (t--) {
        cin >> k;

        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;
        map<int, int> num;
        while (k--) {
            cin >> cmd >> input;
            if (cmd == 'I') {
                maxQ.push(input);
                minQ.push(input);

                if (num.count(input) == 0) num[input] = 1;
                else num[input]++;
            } else {
                if (input == 1) {
                    while (!maxQ.empty() && num[maxQ.top()] == 0) maxQ.pop();

                    if (!maxQ.empty()) {
                        num[maxQ.top()]--;
                        maxQ.pop();
                    }
                } else {
                    while (!minQ.empty() && num[minQ.top()] == 0) minQ.pop();

                    if (!minQ.empty()) {
                        num[minQ.top()]--;
                        minQ.pop();
                    }
                }
            }
        }
        while (!maxQ.empty() && num[maxQ.top()] == 0) maxQ.pop();
        while (!minQ.empty() && num[minQ.top()] == 0) minQ.pop();

        if (maxQ.empty()) cout << "EMPTY\n";
        else cout << maxQ.top() << ' ' << minQ.top() << '\n';
    }
    return 0;
}