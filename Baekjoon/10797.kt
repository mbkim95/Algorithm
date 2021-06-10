fun main() {
    val n = readLine()!!.toInt()
    println(readLine()!!.split(" ").map { it.toInt() }.count { it == n })
}