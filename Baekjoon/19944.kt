fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    println(if (m == 1 || m == 2) "NEWBIE!" else if (m <= n) "OLDBIE!" else "TLE!")
}