#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int cur_weight = 0;
    int idx = 0;
    queue<int> q;
    while (true) {
        time++;
        if (q.size() == bridge_length) {
            cur_weight -= q.front();
            q.pop();
        }
        
        if (cur_weight + truck_weights[idx] <= weight) {
            if (idx == truck_weights.size() - 1) {
                time += bridge_length;
                break;
            }
            q.push(truck_weights[idx]);
            cur_weight += truck_weights[idx];
            idx++;
        }
        else q.push(0);
    }
    return time;
}