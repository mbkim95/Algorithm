import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val r = IntArray(n) { 0 }
    for (i in 0 until n) r[i] = readLine()!!.toInt()
    r.sort()
    var ans = 0
    for (i in 0 until n) ans = max(ans, r[i] * (n - i))
    println(ans)
}