import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (n, m) = br.readLine().split(" ").map { it.toInt() }
    val sites = hashMapOf<String, String>()
    for (i in 1..n) {
        val (site, password) = br.readLine().split(" ")
        sites[site] = password
    }
    for (i in 1..m) bw.write("${sites[br.readLine()]}\n")
    bw.flush()
}