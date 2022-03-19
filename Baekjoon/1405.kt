var ans: Double = 1.0
val set = hashSetOf<Pair<Int, Int>>()
var C = 0
var P = intArrayOf(0, 0, 0, 0)
val dx = listOf(1, -1, 0, 0)
val dy = listOf(0, 0, -1, 1)

fun dfs(x: Int, y: Int, cnt: Int, percent: Double) {
    if (cnt == C) {
        if (set.size < C + 1) {
            ans -= percent
        }
        return
    }

    for (i in 0..3) {
        val nx = x + dx[i]
        val ny = y + dy[i]

        if (set.contains(Pair(nx, ny))) {
            ans -= (percent * P[i] / 100)
        } else {
            set.add(Pair(nx, ny))
            dfs(nx, ny, cnt + 1, percent * P[i] / 100)
            set.remove(Pair(nx, ny))
        }
    }
}

fun main() {
    val (c, e, w, s, n) = readLine()!!.split(" ").map { it.toInt() }
    C = c; P[0] = e; P[1] = w; P[2] = s; P[3] = n

    set.add(Pair(0, 0))
    dfs(0, 0, 0, 1.0)
    println(ans)
}