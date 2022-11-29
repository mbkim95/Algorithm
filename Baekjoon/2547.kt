fun main() = repeat(readLine()!!.toInt()) {
    readLine()
    val n = readLine()!!.toInt()
    var ans = 0L
    for(i in 1..n) {
        ans += readLine()!!.toLong()
        ans %= n
    }
    println(if(ans == 0L) "YES" else "NO")
}