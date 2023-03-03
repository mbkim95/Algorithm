fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val r = IntArray(n + 1) { 0 }
    repeat(m) {
        readln().split(" ").forEach { r[it.toInt()]++ }
    }
    for (i in 1..n) println(r[i])
}