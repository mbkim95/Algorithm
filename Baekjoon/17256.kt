fun main() {
    val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
    val (d, e, f) = readLine()!!.split(" ").map { it.toInt() }
    println("${d - c} ${e / b} ${f - a}")
}