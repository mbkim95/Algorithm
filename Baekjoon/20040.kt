import kotlin.system.exitProcess

lateinit var roots: IntArray

fun find(idx: Int): Int {
    if (roots[idx] == idx) return idx
    roots[idx] = find(roots[idx])
    return roots[idx]
}

fun union(a: Int, b: Int): Boolean {
    val r1 = find(a)
    val r2 = find(b)

    if (r1 == r2) return true
    roots[r2] = r1
    return false
}

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    roots = IntArray(n) { it }

    for (i in 1..m) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        if (union(a, b)) {
            println(i)
            return
        }
    }
    println(0)
}