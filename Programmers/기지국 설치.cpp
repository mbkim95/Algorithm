#include <vector>
using namespace std;

int countStation(int left, int right, int w) {
	int length = right - left + 1;
	int range = 2 * w + 1;
	int count = 0;
	while (count * range < length) count++;
	return count;
}

int solution(int n, vector<int> stations, int w) {
	int answer = 0;
	if (stations[0] - w > 1) answer += countStation(1, stations[0] - w - 1, w);
	for (int i = 1; i < stations.size(); i++)
		answer += countStation(stations[i - 1] + w + 1, stations[i] - w - 1, w);
	int last = stations.size() - 1;
	if (stations[last] + w < n) answer += countStation(stations[last] + w + 1, n, w);
	return answer;
}