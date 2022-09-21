import java.util.PriorityQueue

fun main() {
    val n = readLine()!!.toInt()
    var d = readLine()!!.toInt()
    val pq = PriorityQueue<Int>(Comparator.reverseOrder())
    for (i in 1 until n) pq.add(readLine()!!.toInt())
    var ans = 0

    while (pq.isNotEmpty() && d <= pq.peek()) {
        pq.add(pq.poll() - 1)
        d++
        ans++
    }
    println(ans)
}