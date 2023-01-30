import kotlin.math.roundToInt

fun main() {
    val s = mutableListOf<Int>()
    repeat(readln().toInt()) { s.add(readln().toInt()) }
    s.sort()
    if(s.size == 0) {
        println(0)
        return
    }

    val e = (s.size * 0.15).roundToInt()
    if (e == 0) println(s.sum() / s.size)
    else {
        var sum = s.sum()
        for(i in 0 until e) sum -= (s[i] + s[s.size - 1 - i])
        println((sum.toFloat() / (s.size - 2 * e)).roundToInt())
    }
}