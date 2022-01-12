import kotlin.math.*

class Solution {
    fun solution(sizes: Array<IntArray>): Int {
        var a = 0
        var b = 0
        for (i in sizes) {
            i.sort()
            a = max(a, i[0])
            b = max(b, i[1])
        }
        return a * b
    }
}