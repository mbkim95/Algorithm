import kotlin.math.*

val sk = listOf('A', 'B', 'C')
val cy = listOf('B', 'A', 'B', 'C')
val hj = listOf('C', 'C', 'A', 'A', 'B', 'B')

fun main() {
    val n = readLine()!!.toInt()
    val p = readLine()!!
    val id = IntArray(3) { 0 }
    var ans = 0
    for (i in 0 until n) {
        if (p[i] == sk[i % 3]) id[0]++
        if (p[i] == cy[i % 4]) id[1]++
        if (p[i] == hj[i % 6]) id[2]++
    }
    ans = max(id[0], max(id[1], id[2]))
    println(ans)
    if (ans == id[0]) println("Adrian")
    if (ans == id[1]) println("Bruno")
    if (ans == id[2]) println("Goran")
}