import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i : works) pq.add(i);
        while (n-- > 0) {
            if (pq.peek() > 0) {
                pq.add(pq.poll() - 1);
            }
        }
        while (!pq.isEmpty()) {
            int num = pq.poll();
            answer += (num * num);
        }
        return answer;
    }
}