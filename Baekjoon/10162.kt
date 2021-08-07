fun main() {
    var t = readLine()!!.toInt()
    if (t % 10 != 0) println(-1)
    else {
        val a = t / 300
        t %= 300
        val b = t / 60
        t %= 60
        println("$a $b ${t / 10}")
    }
}