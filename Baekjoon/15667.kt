fun main() {
    var n = readLine()!!.toInt()
    var f = 1

    for (i in 1..100) if (f + f * i + f * i * i == n) {
        println(i)
        break
    }
}
