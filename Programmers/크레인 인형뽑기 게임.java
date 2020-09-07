import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        int n = board.length;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < moves.length; i++) {
            int x = moves[i] - 1;
            for (int y = 0; y < n; y++) {
                if (board[y][x] != 0) {
                    int doll = board[y][x];
                    board[y][x] = 0;
                    if (!stack.empty() && stack.peek() == doll) {
                        stack.pop();
                        answer += 2;
                    } else {
                        stack.push(doll);
                    }
                    break;
                }
            }
        }
        return answer;
    }
}