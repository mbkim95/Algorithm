fun main() {
    val (h1, m1, s1) = readln().split(":").map { it.toInt() }
    val (h2, m2, s2) = readln().split(":").map { it.toInt() }
    val seconds1 = h1 * 3600 + m1 * 60 + s1
    var seconds2 = h2 * 3600 + m2 * 60 + s2
    if (seconds1 >= seconds2) seconds2 += 24 * 3600
    var diff = seconds2 - seconds1
    val h3 = diff / 3600
    diff -= h3 * 3600
    val m3 = diff / 60
    val s3 = diff % 60
    println("${if (h3 < 10) "0$h3" else h3}:${if (m3 < 10) "0$m3" else m3}:${if (s3 < 10) "0$s3" else s3}")
}