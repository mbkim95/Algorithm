import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int[] solution(String msg) {
        ArrayList<Integer> arr = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();
        // 사전 초기화
        for (int i = 0; i < 26; i++) map.put(String.valueOf((char) ('A' + i)), i + 1);
        // msg의 인덱스
        int idx = 0;
        // 사전에 없는 글자가 나올 때 매핑해줄 값
        int mapping = 27;
        // msg를 다 탐색할 때까지 반복
        while (idx < msg.length()) {
            String tok = "";
            // idx 위치에서 길이가 짧아지는 순서로 문자열 자르기
            for (int i = msg.length(); i > idx; i--) {
                tok = msg.substring(idx, i);
                // 사전에 등록된 문자열을 발견한 경우
                if (map.containsKey(tok)) break;
            }
            // 정수값 저장
            arr.add(map.get(tok));
            // 인덱스 값 조정
            idx += tok.length();
            // 뒤에 글자가 남아있는 경우
            if (idx < msg.length())
                // 사전에 등록
                map.put(tok + msg.charAt(idx), mapping++);
        }
        int[] answer = new int[arr.size()];
        for (int i = 0; i < arr.size(); i++) answer[i] = arr.get(i);
        return answer;
    }
}