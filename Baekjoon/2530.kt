fun main() {
    var (h, m, s) = readLine()!!.split(" ").map { it.toInt() }
    var r = readLine()!!.toInt()
    h += r / 3600
    r %= 3600
    m += r / 60
    s += r % 60
    if (s >= 60) {
        m += s / 60
        s %= 60
    }
    if (m >= 60) {
        h += m / 60
        m %= 60
    }
    if (h >= 24) h %= 24
    println("$h $m $s")
}