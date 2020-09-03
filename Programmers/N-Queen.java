class Solution {
    int N;
    int ans = 0;
    boolean[][] map;

    boolean check(int x, int y) {
        for (int i = 0; i < N; i++) {
            if (i == y) continue;
            if (map[i][x]) return false;
        }
        for (int j = 0; j < N; j++) {
            if (j == x) continue;
            if (map[y][j]) return false;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(i == y && j == x) continue;
                if (i + j == x + y && map[i][j]) return false;
                if (j - i == x - y && map[i][j]) return false;
            }
        }
        return true;
    }

    public void dfs(int y, int cnt) {
        if (y == N) {
            ans++;
            return;
        }

        for (int j = 0; j < N; j++) {
            map[y][j] = true;
            if (check(j, y)) dfs(y + 1, cnt+1);
            map[y][j] = false;
        }
    }

    public int solution(int n) {
        N = n;
        int answer = 0;
        map = new boolean[n][n];
        dfs(0, 0);
        answer = ans;
        return answer;
    }
}