fun main() {
    val n = readLine()!!.toInt()
    val player = Array(n) { mutableListOf<Int>() }
    for (i in 0 until n) {
        player[i].addAll(readLine()!!.split(" ").map { it.toInt() })
    }

    for (p in 0 until n) {
        var sum = 0
        for (i in 0..2) {
            var round = player[p][i]
            for (j in 0 until n) {
                if (p == j) continue
                if(player[p][i] == player[j][i]) {
                    round = 0
                    break
                }
            }
            sum += round
        }
        player[p].add(sum)
    }
    for (i in 0 until n) println(player[i][3])
}