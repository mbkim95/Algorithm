fun main() {
    val (h1, m1, s1) = readLine()!!.split(":").map { it.toInt() }
    val (h2, m2, s2) = readLine()!!.split(":").map { it.toInt() }
    val t1 = h1 * 3600 + m1 * 60 + s1
    var t2 = h2 * 3600 + m2 * 60 + s2
    if (t1 >= t2) t2 += 24 * 3600
    var t = t2 - t1
    val nh = t / 3600
    t %= 3600
    val nm = t / 60
    val ns = t % 60
    println("${if (nh < 10) "0$nh" else nh}:${if (nm < 10) "0$nm" else nm}:${if (ns < 10) "0$ns" else ns}")
}