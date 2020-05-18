fun main() {
    val (a, b) = readLine()!!.split(" ").map { it.toLong() }
    println("${(a + b) * (a - b)}")
}