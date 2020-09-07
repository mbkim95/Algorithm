class Solution {
    static final char[] Hex = {'A', 'B', 'C', 'D', 'E', 'F'};

    // n진수로 변환
    public String decToN(int n, int num) {
        if (num == 0 || n == 10) return String.valueOf(num);
        StringBuilder ret = new StringBuilder();
        while (num > 0) {
            int div = num % n;
            if (div >= 10) ret.insert(0, Hex[div - 10]);
            else ret.insert(0, div);
            num /= n;
        }
        return ret.toString();
    }

    public String solution(int n, int t, int m, int p) {
        String answer = "";
        String num = "";
        for (int i = 0; i <= t * m; i++)
            num += decToN(n, i);

        for (int i = 0; i < t; i++) {
            answer += num.charAt(m * i + p - 1);
        }
        return answer;
    }
}