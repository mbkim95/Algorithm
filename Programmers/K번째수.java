import java.util.Arrays;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int n = commands.length;
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            int a = commands[i][0];
            int b = commands[i][1];
            int c = commands[i][2];
            int[] temp = Arrays.copyOfRange(array, a - 1, b);
            Arrays.sort(temp);
            answer[i] = temp[c - 1];
        }
        return answer;
    }
}