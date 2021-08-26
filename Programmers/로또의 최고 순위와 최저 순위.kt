class Solution {
    fun solution(lottos: IntArray, win_nums: IntArray): IntArray {
        val zero = lottos.filter { it == 0 }.size
        var cnt = 0
        win_nums.forEach { if (lottos.contains(it)) cnt++ }
        val min = if (7 - cnt > 6) 6 else 7 - cnt
        val max = if (7 - zero - cnt > 6) 6 else 7 - zero - cnt
        return intArrayOf(max, min)
    }
}