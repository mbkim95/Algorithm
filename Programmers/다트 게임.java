class Solution {
    public int solution(String dartResult) {
        int sum = 0;
        int num = 0;
        int prev = 0;
        boolean isTen = false;
        boolean option = false;
        for (int i = 0; i < dartResult.length(); i++) {
            char c = dartResult.charAt(i);
            if (isTen) {
                isTen = false;
                continue;
            }

            if ('0' <= c && c <= '9') {
                if (!option) {
                    prev = num;
                    sum += num;
                }
                option = false;
                num = c - '0';
                if (c == '1' && dartResult.charAt(i + 1) == '0') {
                    num = 10;
                    isTen = true;
                }
            } else if (c == 'D') num = (int) Math.pow(num, 2);
            else if (c == 'T') num = (int) Math.pow(num, 3);
            else if (c == '*') {
                num *= 2;
                sum += prev;
                prev = num;
                sum += num;
                option = true;
            } else if (c == '#') {
                num *= -1;
                prev = num;
                sum += num;
                option = true;
            }
        }
        if (!option) sum += num;
        return sum;
    }
}