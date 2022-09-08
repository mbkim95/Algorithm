import kotlin.math.min

fun main() {
    var (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
    println(min(m, k) + min(n - m, n - k))
}