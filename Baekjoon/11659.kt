import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, m) = br.readLine().split(" ").map { it.toInt() }
    val num = br.readLine().split(" ").map { it.toInt() }
    val sum = mutableListOf(0)
    var tmp = 0
    for (i in num) {
        tmp += i
        sum.add(tmp)
    }

    for (t in 0 until m) {
        val (i, j) = br.readLine().split(" ").map { it.toInt() }
        bw.write("${sum[j] - sum[i - 1]}\n")
    }
    bw.flush()
}