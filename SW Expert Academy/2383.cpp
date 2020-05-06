#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct pos {
	int x, y, t;
};

int n, ans;
int map[10][10];
vector<pos> p, s;
vector<int> sel;

int calc_distance(int p_idx, int s_idx) {
	return abs(p[p_idx].x - s[s_idx].x) + abs(p[p_idx].y - s[s_idx].y) + 1;
}

void dfs(int idx) {
	if (idx == p.size()) {
		// 계단까지 이동하는데 걸리는 시간을 저장할 배열
		vector<int> stair[2];
		for (int i = 0; i < sel.size(); i++) {
			// 계단 1까지 이동하는데 걸리는 시간 계산
			if (sel[i]) stair[1].push_back(calc_distance(i, 1));
			// 계단 0까지 이동하는데 걸리는 시간 계산
			else stair[0].push_back(calc_distance(i, 0));
		}
		// 시간이 짧은 순으로 정렬
		sort(stair[0].begin(), stair[0].end());
		sort(stair[1].begin(), stair[1].end());
		queue<int> q;
		int time1 = 0, time2 = 0;
		int idx = -1;

		// 계단 1을 사용하는 사람들이 모두 내려가는 시간 계산
		while (true) {
			// 현재 시간에 계단을 다 내려갈 수 있는 사람을 내려보낸다
			while (!q.empty() && q.front() <= time1) q.pop();
			// 계단에 있는 사람이 3명보다 적은 경우
			if (q.size() < 3) {				
				// idx로 몇 번째 사람까지 계단에 갔는지 기록하고, 그 다음 사람부터 계단으로 보낸다
				for (int i = idx + 1; i < stair[0].size(); i++) {
					// 계단이 다 차면 보내는 것을 중지
					if (q.size() == 3) break;
					// i번째 사람이 계단에 내려가기 시작한 시간
					// 계단에 도착했지만 계단에 사람이 3명 이상이라 내려가지 못하는 경우가 있으므로 현재 시간과 비교한다.
					int tmp = max(time1, stair[0][i]);
					// 계단을 다 내려가는 시간을 더해준다
					q.push({ tmp + s[0].t });
					idx = i;
				}
			}
			// 모든 사람이 계단을 내려간 경우 종료
			if (idx == stair[0].size() - 1 && q.empty()) break;
			time1++;
		}

		idx = -1;
		while (true) {
			while (!q.empty() && q.front() <= time2) q.pop();
			if (q.size() < 3) {
				for (int i = idx + 1; i < stair[1].size(); i++) {
					if (q.size() == 3) break;
					int tmp = max(time2, stair[1][i]);
					q.push({ tmp + s[1].t });
					idx = i;
				}
			}
			if (idx == stair[1].size() - 1 && q.empty()) break;
			time2++;
		}		
		ans = min(ans, max(time1, time2));
		return;
	}

	sel[idx] = 1;
	dfs(idx + 1);
	sel[idx] = 0;
	dfs(idx + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		ans = 987654321;
		p.clear();
		s.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) p.push_back({ j, i, 0 });
				else if (map[i][j] >= 2) s.push_back({ j, i, map[i][j] });
			}
		}
		sel = vector<int>(p.size());
		dfs(0);
		cout << "#" << c << ' ' << ans << '\n';
	}
}