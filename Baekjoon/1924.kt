fun main() {
    var (x, y) = readLine()!!.split(' ').map { it.toInt() }
    var cur = 1
    val m = listOf(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
    val d = listOf("SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT")
    while (cur < x) {
        y += m[cur - 1]
        cur++
    }
    println(d[y % 7])
}