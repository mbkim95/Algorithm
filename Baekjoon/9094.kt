fun main() {
    var t = readLine()!!.toInt()
    while (t-- > 0) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        var ans = 0
        for (a in 1..n - 2) {
            for (b in a + 1 until n) {
                if ((a * a + b * b + m) % (a * b) == 0) ans++
            }
        }
        println(ans)
    }
}
