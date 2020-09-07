import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i : scoville) pq.add(i);
        while (pq.size() > 1) { // 음식 1개가 될 때까지 섞기
            if(pq.peek() >= K) break; // 가장 낮은 스코빌 지수가 K 이상인 경우
            int a = pq.poll(), b = pq.poll();
            pq.add(a + 2 * b);
            answer++;
        }
        if (pq.peek() < K) return -1; // 음식이 1개이고 스코빌 지수가 K 미만인 경우
        return answer;
    }
}