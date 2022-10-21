fun main() {
    val (k, d, a) = readLine()!!.split("/").map { it.toInt() }
    println(if (k + a < d || d == 0) "hasu" else "gosu")
}