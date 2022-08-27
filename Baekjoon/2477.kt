import kotlin.math.max

fun main() {
    val k = readLine()!!.toInt()
    var maxW = 0
    var maxH = 0
    var extraW = 0
    var extraH = 0
    val borders = mutableListOf<Pair<Int, Int>>()
    for (i in 0 until 6) {
        val (dir, dist) = readLine()!!.split(" ").map { it.toInt() }
        borders.add(Pair(dir, dist))
    }
    for (i in 0 until 6) {
        val (dir, dist) = borders[i]
        if (dir in 1..2) {
            maxW = max(maxW, dist)
            if (dir == borders[(i + 2) % 6].first) extraW = borders[(i + 1) % 6].second
        } else {
            maxH = max(maxH, dist)
            if (dir == borders[(i + 2) % 6].first) extraH = borders[(i + 1) % 6].second
        }
    }
    println(k * (maxW * maxH - extraW * extraH))
}