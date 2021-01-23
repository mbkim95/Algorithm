fun main() {
    val n = readLine()
    val num = readLine()!!.toList().sumBy { it.toInt() - '0'.toInt() }
    println(num)
}
