class Solution {
    fun solution(absolutes: IntArray, signs: BooleanArray): Int {
        var answer = 0
        for (i in signs.indices) answer += absolutes[i] * if (signs[i]) 1 else -1
        return answer
    }
}