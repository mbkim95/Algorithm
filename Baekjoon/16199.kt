fun main() {
    val (y, m, d) = readLine()!!.split(" ").map { it.toInt() }
    val (y2, m2, d2) = readLine()!!.split(" ").map { it.toInt() }
    val diff = y2 - y
    print("${if (m < m2 || (m == m2 && d <= d2)) diff else diff - 1}\n${diff + 1}\n$diff")
}