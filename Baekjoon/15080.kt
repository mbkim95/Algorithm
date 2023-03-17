fun main() {
    val (h1, m1, s1) = readln().split(":").map { it.trim().toInt() }
    var (h2, m2, s2) = readln().split(":").map { it.trim().toInt() }
    val t1 = h1 * 3600 + m1 * 60 + s1
    var t2 = h2 * 3600 + m2 * 60 + s2
    if (t2 < t1) t2 += (24 * 3600)
    println(t2 - t1)
}