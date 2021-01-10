import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val road = readLine()!!.split(' ').map { it.toLong() }.toList()
    val city = readLine()!!.split(' ').map { it.toLong() }.toList()

    var cost: Long = 0
    var minCost: Long = Int.MAX_VALUE.toLong()
    for (i in 0 until n - 1) {
        minCost = min(minCost, city[i])
        cost += minCost * road[i]
    }
    println(cost)
}
