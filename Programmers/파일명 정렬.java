import java.util.Arrays;
import java.util.Comparator;

class Pair {
    String head;
    int number;

    public Pair(String head, int number) {
        this.head = head;
        this.number = number;
    }
}

class Solution {
    // HEAD NUMBER 분리
    public Pair parseHeadNumber(String str) {
        int number = 0;
        int idx = 0;
        // HEAD를 분리하기 위해 탐색
        for (char c : str.toCharArray()) {
            if ('0' <= c && c <= '9') break;
            idx++;
        }
        // NUMBER를 분리하기 위해 탐색
        for (int i = idx; i < str.length(); i++) {
            if (!('0' <= str.charAt(i) && str.charAt(i) <= '9')) break;
            number = 10 * number + (str.charAt(i) - '0');
        }
        // HEAD, NUMBER 리턴
        return new Pair(str.substring(0, idx), number);
    }

    public String[] solution(String[] files) {
        Arrays.sort(files, new Comparator<>() {
            @Override
            public int compare(String o1, String o2) {
                Pair p1 = parseHeadNumber(o1);
                Pair p2 = parseHeadNumber(o2);
                // 대문자로 변환
                String h1 = p1.head.toUpperCase();
                String h2 = p2.head.toUpperCase();
                // HEAD가 다르면 HEAD를 비교해서 정렬
                if (!h1.equals(h2)) return h1.compareTo(h2);
                // HEAD가 일치하면 NUMBER를 비교해서 정렬
                if (p1.number == p2.number) return 0;
                else return Integer.compare(p1.number, p2.number);
            }
        });
        return files;
    }
}