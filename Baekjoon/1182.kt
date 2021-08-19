var ans = 0

fun dfs(list: List<Int>, idx: Int, sum: Int, s: Int, cnt: Int) {
    if (idx == list.size) {
        if (sum == s && cnt > 0) ans++
        return
    }

    dfs(list, idx + 1, sum, s, cnt)
    dfs(list, idx + 1, sum + list[idx], s, cnt + 1)
}

fun main() {
    val (n, s) = readLine()!!.split(" ").map { it.toInt() }
    val list = readLine()!!.split(" ").map { it.toInt() }
    dfs(list, 0, 0, s, 0)
    println(ans)
}