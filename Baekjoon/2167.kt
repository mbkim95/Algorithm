fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val arr = mutableListOf<List<Int>>()
    for (i in 0 until n) arr.add(readLine()!!.split(" ").map { it.toInt() }.toList())

    for (t in 0 until readLine()!!.toInt()) {
        val (a, b, c, d) = readLine()!!.split(" ").map { it.toInt() }
        var sum = 0
        for (i in a-1 until c) for (j in b-1 until d) sum += arr[i][j]
        println(sum)
    }
}