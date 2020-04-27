#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    // 거리 계산을 위해 distance도 rocks에 포함
    rocks.push_back(distance);
    // 이분 탐색을 위해 정렬
    sort(rocks.begin(), rocks.end());

    int left = 1, right = distance;
    while (left <= right) {
        int mid = (left + right) / 2;

        int diff;
        int last = -1;
        int cnt = 0;
        for (int i = 0; i < rocks.size(); i++) {
            // i번째 바위 전에는 바위가 존재하지 않는 경우
            if (last == -1) diff = rocks[i];
            else diff = rocks[i] - rocks[last];

            // mid보다 작은 경우 제거할 바위의 개수를 증가
            if (diff < mid) cnt++;
            // mid보다 큰 경우 last 값 갱신
            else last = i;
        }

        if (cnt > n) right = mid - 1;
        else {
            left = mid + 1;
            answer = max(answer, mid);
        }
    }
    return answer;
}