import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> map = new HashMap<>();
        for (String name : participant)
            map.put(name, map.getOrDefault(name, 0) + 1);

        for (String name : completion) {
            if (map.get(name) > 1) map.put(name, map.get(name) - 1);
            else map.remove(name);
        }
        answer = map.keySet().iterator().next();
        return answer;
    }
}