import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        boolean isAllZero = true; // 모든 숫자가 0인지 체크하기 위한 변수
        ArrayList<String> arr = new ArrayList<>(); // 문자열로 변환한 숫자를 담을 배열

        // 모든 숫자를 문자열로 변환
        for (int num : numbers) {
            if (num != 0) isAllZero = false;
            arr.add(String.valueOf(num));
        }
        if (isAllZero) return "0"; // 모든 숫자가 0이면 정답도 0이 된다

        Collections.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return Integer.compare(Integer.parseInt(o2 + o1), Integer.parseInt(o1 + o2));
            }
        });
        for (String s : arr) answer += s;
        return answer;
    }
}