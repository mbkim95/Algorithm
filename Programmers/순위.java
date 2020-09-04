class Solution {
    boolean[][] win;

    public int solution(int n, int[][] results) {
        int answer = 0;
        win = new boolean[n + 1][n + 1]; // 승리 관계 표현 배열

        // 승리한 경우 true로 표시
        for (int[] result : results)
            win[result[0]][result[1]] = true;

        // 플로이드 와샬 알고리즘
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    // i가 k를 이기고 k가 j를 이겼으면 i가 j를 이긴 것으로 표시
                    if (win[i][k]  && win[k][j])
                        win[i][j] = true;


        for (int i = 1; i <= n; i++) {
            int count = 0;
            for (int j = 1; j <= n; j++) {
                // 이기거나 진 결과 카운트
                if (win[i][j] || win[j][i]) count++;
            }
            // 자기 자신과는 싸울 수 없기 때문에 n-1의 결과가 나오면 순위가 결정됨
            if (count == n - 1) answer++;
        }
        return answer;
    }
}