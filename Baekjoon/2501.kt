fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val a = (1..n).filter { n % it == 0 }
    println("${if (a.size < k) 0 else a[k - 1]}")
}