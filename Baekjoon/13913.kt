import java.util.*

const val MAX = 100000
val map = IntArray(MAX + 1) { -1 }

fun main() {
    var (n, k) = readLine()!!.split(' ').map { it.toInt() }
    bfs(n, k)
    backWarding(n, k)
}

fun bfs(n: Int, k: Int) {
    val q: Queue<Int> = LinkedList()
    q.add(n)
    map[n] = 0

    while (!q.isEmpty()) {
        val cur = q.poll()

        if (cur == k) break

        if (cur - 1 >= 0 && map[cur - 1] == -1) {
            q.add(cur - 1)
            map[cur - 1] = map[cur] + 1
        }
        if (cur + 1 <= MAX && map[cur + 1] == -1) {
            q.add(cur + 1)
            map[cur + 1] = map[cur] + 1
        }
        if (2 * cur <= MAX && map[2 * cur] == -1) {
            q.add(2 * cur)
            map[2 * cur] = map[cur] + 1
        }
    }
    println(map[k])
}

fun backWarding(n: Int, k: Int) {
    val q: Queue<Int> = LinkedList()
    q.add(k)
    val ans = MutableList(0) { 0 }

    while (!q.isEmpty()) {
        val cur = q.poll()
        ans.add(cur)

        if (cur == n) break

        if (cur - 1 >= 0 && map[cur - 1] + 1 == map[cur]) q.add(cur - 1)
        else if (cur + 1 <= MAX && map[cur + 1] + 1 == map[cur]) q.add(cur + 1)
        else if (cur / 2 > 0 && map[cur / 2] + 1 == map[cur]) q.add(cur / 2)
    }

    ans.reverse()
    ans.forEach {
        print("$it ")
    }
    println()
}
