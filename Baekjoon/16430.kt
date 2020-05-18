fun main() {
    val (a, b) = readLine()!!.split(" ").map { it.toInt() }
    println("${b-a} ${b}")
}