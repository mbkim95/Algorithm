import java.util.ArrayList;
import java.util.List;

class Solution {
    List<int[]> moves = new ArrayList<>();

    public void move(int from, int to) {
        moves.add(new int[]{from, to});
    }

    public void hanoi(int n, int from, int to, int by) {
        if (n == 1) {
            moves.add(new int[]{from, to});
            return;
        }
        hanoi(n - 1, from, by, to);
        moves.add(new int[]{from, to});
        hanoi(n - 1, by, to, from);
    }

    public int[][] solution(int n) {
        hanoi(n, 1, 3, 2);
        int[][] answer = new int[moves.size()][2];
        for (int i = 0; i < answer.length; i++)
            answer[i] = new int[]{moves.get(i)[0], moves.get(i)[1]};
        return answer;
    }
}