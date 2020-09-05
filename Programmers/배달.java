class Solution {
    static int MAX = Integer.MAX_VALUE;

    public int solution(int N, int[][] road, int K) {
        int[][] adj = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) adj[i][j] = MAX;
        for (int[] r : road) {
            int a = r[0], b = r[1], c = r[2];
            adj[a][b] = Integer.min(adj[a][b], c);
            adj[b][a] = Integer.min(adj[b][a], c);
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (i == j) continue;
                    if (adj[i][k] != MAX && adj[k][j] != MAX) {
                        adj[i][j] = Integer.min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }

        int answer = 1;
        for (int i = 2; i <= N; i++)
            if (adj[1][i] <= K)
                answer++;
        return answer;
    }
}
