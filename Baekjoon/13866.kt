import kotlin.math.abs

fun main() {
    val t = readLine()!!.split(" ").map { it.toInt() }.sorted()
    println(abs(t[0] + t[3] - t[1] - t[2]))
}