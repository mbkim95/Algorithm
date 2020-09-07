import java.util.Arrays;

class Solution {
    boolean visited[];

    public void dfs(int n, int[][] computers, int idx) {
        visited[idx] = true;

        for (int i = 0; i < n; i++) {
            if (i == idx) continue;
            if (!visited[i] && computers[idx][i] == 1) dfs(n, computers, i);
        }
    }

    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n];
        Arrays.fill(visited, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                answer++;
                dfs(n, computers, i);
            }
        }
        return answer;
    }
}