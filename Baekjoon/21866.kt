fun main() {
    val s = readln().split(" ").map { it.toInt() }
    var t = 0
    for (i in s.indices) {
        if (s[i] > 100 + 100 * (i / 2)) t = -1
        else if (t != -1) t += s[i]
    }
    println(if (t >= 100) "draw" else if (t == -1) "hacker" else "none")
}