class Solution {
    public int[] solution(String[] gems) {
        int[] answer = {1, gems.length}; // 전체 범위가 정답인 경우로 초기화
        Set<String> jewels = new HashSet<>(); // 보석 종류 개수를 세기 위한 set
        Map<String, Integer> jewelMap = new HashMap<>(); // 범위 내에 보석이 몇 개나 저장됐는지 확인용 map
        for (String s : gems) jewels.add(s); // set에 저장해서 보석 종류 개수 파악

        int s = 0, e = 0;
        int diff = gems.length; // diff의 최댓값은 전체 배열 길이

        while (true) {
            // 보석 종류를 다 채운 경우
            if (jewelMap.size() == jewels.size()) {
                if (diff > e - s) {
                    diff = e - s;
                    answer[0] = s + 1;
                    answer[1] = e;
                }
                // gems[s]의 보석이 범위 내에 1개인 경우
                if (jewelMap.get(gems[s]) == 1) {
                    // 보석을 지우고 계속 탐색 (ans.size() 로 보석 종류를 다 모았는지 판단하므로 ans[gems[s]-- 가 아니라 remove 해줘야함)
                    jewelMap.remove(gems[s]);
                    s++;
                }
                // gems[s] 보석이 2개 이상인 경우
                else if (jewelMap.get(gems[s]) > 1) {
                    // 보석의 갯수 - 1
                    jewelMap.put(gems[s], jewelMap.get(gems[s]) - 1);
                    s++;
                }
            }
            // 범위 벗어난 경우
            else if (e == gems.length) break;
            // 범위 안벗어나고 모든 종류 보석을 다 못찾은 경우
            else{
                jewelMap.put(gems[e], 1);
                e++;
            }
        }
        return answer;
    }
}
