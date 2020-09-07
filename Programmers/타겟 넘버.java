class Solution {
    int n, ans;

    public void dfs(int[] numbers, int target, int idx, int sum) {
        if (idx == n) {
            if (sum == target) ans++;
            return;
        }
        dfs(numbers, target, idx + 1, sum + numbers[idx]);
        dfs(numbers, target, idx + 1, sum - numbers[idx]);
    }

    public int solution(int[] numbers, int target) {
        n = numbers.length;
        int answer = 0;
        dfs(numbers, target, 0, 0);
        answer = ans;
        return answer;
    }
}