fun main() {
    val m = readLine()!!.split(" ").sumOf { it.toInt() }
    val c = readLine()!!.toInt()
    println("${if (m - 2 * c >= 0) m - 2 * c else m}")
}