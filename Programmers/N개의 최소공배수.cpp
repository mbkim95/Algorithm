#include <string>
#include <vector>
#include <queue>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int solution(vector<int> arr) {
    int answer = 0;
    queue<int> q;
    for (int i : arr) q.push(i);

    while (q.size() > 1) {
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();
        int g = gcd(a, b);
        q.push(a * b / g);
    }
    answer = q.front();
    return answer;
}