fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    println(readLine()!!.split(" ").map { it.toInt() }.sorted()[n - k])
}