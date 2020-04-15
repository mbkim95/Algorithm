#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = numeric_limits<long long>::max();
    sort(times.begin(), times.end());
    long long left = 1;
    long long right = (long long)n * times[times.size() - 1];

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long cnt = 0;
        for (int t : times) {
            cnt += (mid / t);
        }

        // n명을 모두 처리한 경우
        if (cnt >= n) {
            answer = min(answer, mid);
            right = mid - 1;
        }
        // n명을 처리하지 못한 경우
        else {
            left = mid + 1;
        }
    }
    return answer;
}