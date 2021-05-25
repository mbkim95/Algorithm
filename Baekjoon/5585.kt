fun main() {
    val coin = listOf(500, 100, 50, 10, 5, 1)
    var p = 1000 - readLine()!!.toInt()
    var ans = 0
    for (c in coin)
        if (p >= c) {
            ans += (p / c)
            p %= c
        }
    println(ans)
}