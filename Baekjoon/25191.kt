import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val (a, b) = readLine()!!.split(" ").map { it.toInt() }
    println(min(n, a / 2 + b))
}