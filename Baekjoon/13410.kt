import java.lang.Integer.max

fun main() {
    val (n, k) = readln().split(" ").map { it.toInt() }
    var ans = 0
    for(i in 1..k) {
        ans = max(ans, (i * n).toString().reversed().toInt())
    }
    println(ans)
}