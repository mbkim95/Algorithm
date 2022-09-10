fun main() {
    val num = mutableListOf(0)
    var n = 1
    while (num.size < 1001) {
        for (i in 1..n) num.add(n)
        n++
    }
    var ans = 0
    val (a, b) = readLine()!!.split(" ").map { it.toInt() }
    for (i in a..b) ans += num[i]
    println(ans)
}
