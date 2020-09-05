class Solution {
    long[] factorial = new long[21];

    public void preCalc() {
        factorial[0] = 1;
        for (int i = 1; i <= 20; i++)
            factorial[i] = factorial[i - 1] * i;
    }

    public int[] solution(int n, long k) {
        preCalc();
        int[] answer = new int[n];
        boolean[] check = new boolean[n + 1];
        int select = 0;
        while (select != n) {
            for (int i = 1; i <= n; i++) {
                if (check[i]) continue;
                long num = factorial[n - 1 - select];
                if (k > num) {
                    k -= num;
                    continue;
                }
                check[i] = true;
                answer[select++] = i;
                break;
            }
        }
        return answer;
    }
}