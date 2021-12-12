fun main() {
    val (r1, s) = readLine()!!.split(" ").map { it.toInt() }
    println("${2 * s - r1}")
}