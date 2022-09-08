fun main() {
    var s = 0
    while (true) {
        val n = readLine()!!.toInt()
        if (n == -1) {
            println(s)
            break
        } else s += n
    }
}