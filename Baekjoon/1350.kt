fun main() {
    readln()
    val files = readln().split(" ").map { it.toInt() }
    val c = readln().toInt()
    var ans = 0L
    for (f in files) {
        ans += if (f > c) if (f % c == 0) (f / c) * c else ((f / c) + 1) * c
        else if (f == 0) continue
        else c
    }
    println(ans)
}