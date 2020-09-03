import java.util.*;

class Solution {
    Comparator<Integer> comp = (o1, o2) -> {
        int x = countBits(o1), y = countBits(o2);
        return Integer.compare(x, y);
    };

    public int countBits(int n) {
        int ret = 0;
        while (n > 0) {
            if ((n & 1) == 1) ret++;
            n >>= 1;
        }
        return ret;
    }

    public boolean check(String[][] relation, int subset) {
        for (int i = 0; i < relation.length - 1; i++) {
            for (int j = i + 1; j < relation.length; j++) {
                boolean isSame = true;
                for (int k = 0; k < relation[0].length; k++) {
                    if ((subset & 1 << k) == 0) continue;
                    if (!relation[i][k].equals(relation[j][k])) {
                        isSame = false;
                        break;
                    }
                }
                if (isSame) return false;
            }
        }
        return true;
    }

    public int solution(String[][] relation) {
        int answer = 0;
        List<Integer> candidate = new LinkedList<>();
        for (int i = 1; i < 1 << relation[0].length; i++) {
            if (check(relation, i))
                candidate.add(i);
        }
        candidate.sort(comp);
        for(int i : candidate)
            System.out.print(i + " ");
        System.out.println();
        System.out.println();

        while (!candidate.isEmpty()) {
            int n = candidate.remove(0);
            answer++;
            candidate.removeIf(i -> (n & i) == n);
            System.out.println("result " + n);
            for(int i : candidate) System.out.print(i + " ");
            System.out.println();
        }
        return answer;
    }
}