fun main() {
    val (a, b, c, m) = readLine()!!.split(" ").map { it.toInt() }

    var t = 0
    var f = 0
    var w = 0
    while (t < 24) {
        f = if (f + a <= m) {
            w += b
            f + a
        } else {
            if (f - c < 0) 0 else f - c
        }
        t++
    }
    println(w)
}