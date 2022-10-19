import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, k, l) = br.readLine().split(" ").map { it.toInt() }
    val ans = mutableListOf<Int>()
    repeat(n) {
        var isVip = true
        var sum = 0
        val t = br.readLine().split(" ").map { it.toInt() }
        t.forEach {
            if (it < l) {
                isVip = false
                return@forEach
            }
            sum += it
        }
        if (isVip && sum >= k) ans.addAll(t)
    }
    bw.write("${ans.size / 3}\n")
    ans.forEach { bw.write("$it ") }
    bw.flush()
}