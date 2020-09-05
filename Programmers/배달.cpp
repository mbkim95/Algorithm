#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
	vector<vector<int>> adj(N + 1, vector<int>(N + 1, MAX));
	for (vector<int> r : road) {
		int a = r[0], b = r[1], c = r[2];
		adj[a][b] = min(adj[a][b], c);
		adj[b][a] = min(adj[b][a], c);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (adj[i][k] != MAX && adj[k][j] != MAX) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
	}
	int answer = 1;
	for (int i = 2; i <= N; i++)
		if (adj[1][i] <= K) answer++;
	return answer;
}