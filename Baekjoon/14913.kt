fun main() {
    val (a, d, k) = readLine()!!.split(" ").map { it.toInt() }
    var cur = 1
    while (true) {
        val num = a + (cur - 1) * d
        if (num == k) {
            println(cur)
            break
        } else if ((d > 0 && num > k) || (d < 0 && num < k)) {
            println("X")
            break
        }
        cur++
    }
}