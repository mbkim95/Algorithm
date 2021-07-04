fun main() {
    val m = readLine()!!.split(" ").map { it.toInt() }
    val ans = m[0] * m[1] - m[2]
    println("${if (ans > 0) ans else 0}")
}