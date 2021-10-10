import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var c = 1
    val (n, m) = br.readLine().split(" ").map { it.toInt() }
    for (i in 1..n) for (j in 1..m) bw.write("${c++}${if (j == m) "\n" else " "}")
    bw.flush()
}