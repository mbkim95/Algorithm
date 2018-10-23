#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#define INF 9876543210
using namespace std;

int n;
double dist[10][10];

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	if (path.size() == n)
		return currentLength;

	double ret = INF;

	for (int i = 0; i<n; i++) {
		if (visited[i])
			continue;
		int here = path.back();
		path.push_back(i);
		visited[i] = true;
		double cand = shortestPath(path, visited, currentLength + dist[here][i]);

		ret = min(ret, cand);
		visited[i] = false;
		path.pop_back();
	}
	return ret;
}

int main() {
	int t;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				cin >> dist[i][j];
			}
		}
		
		
		double ans = INF;
		for (int i = 0; i < n; i++) {
			vector<int> path(1, i);
			vector<bool> visited(n, false);			
			visited[i] = true;
			ans = min(ans, shortestPath(path, visited, 0));
		}
		cout << fixed << setprecision(10) << ans << '\n';
	}
}